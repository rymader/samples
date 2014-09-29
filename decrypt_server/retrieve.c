/*************************************************************
	
	Function definition file for PA5 

	Authors:
	Ryan Mader
	Madison Hennig

**************************************************************/

#include "retrieve.h"
#include <pthread.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <strings.h>
#include <unistd.h>

#define MAXSIZE 160*sizeof(char)
typedef int bool;
#define true 1
#define false 0

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to open file with a tag (i.e. read/write) functionality
FILE *open_file(char *filename, char *tag) {

	FILE *fp;
	if((fp = fopen(filename, tag)) == NULL) {
		fprintf(stderr, "ERROR: Failed to open file %s\n", filename);
		return NULL;
	}
	return fp;
}

// Function to get the line of a text file
char *getLine(char *buffer, FILE *fp) {
	//bzero(buffer, MAXSIZE);
	buffer = fgets(buffer, MAXSIZE, fp);
	return buffer;
}

// Function to add a line of text to the queue
int addNode(int sockfd, unsigned long ip_addr, unsigned long port_no) {
	
	NODE *node = (NODE *)malloc(sizeof(NODE));
	assert(node != NULL);
	
	node->sockfd = sockfd;
	node->ip_addr = ip_addr;
	node->port_no = port_no;
	
	if (HEAD == NULL) {
		HEAD = node;
	}

	else{

		NODE *current = HEAD;		
		while(current->next != NULL){ 
			current = current->next;
		}
		current->next = node;				
	}
		
	return 0;
}

// Prints file and thread info to log.txt
void outLog(char *line, char *path) {
	
	FILE *log = open_file(path, "a");
	assert(log != NULL);
	fprintf(log, line); 
	if(fclose(log) != 0) {
		fprintf(stderr, "ERROR: Failed to close %s\n", (char *)log);
	}
	
}

// Returns the first node on the queue and deletes it
NODE *pop(){
		
	if(pthread_mutex_lock(&mutex) != 0) {
		perror("ERROR: Mutex lock failed");
		exit(1);
	}
		
	if (HEAD == NULL){
		pthread_mutex_unlock(&mutex);
		return NULL;
	}
		
	NODE *current = HEAD;
		
	if (current != NULL){
		HEAD = HEAD->next;
	}
		
	pthread_mutex_unlock(&mutex);	

	return current;
}	

// Function to open the file and print the decryption to the out/text file
void decrypt(char* argv[]){

	int n;
    char buffer[MAXSIZE];
    int payload_size;
    int id;
	
	while (true){
	NODE *current = pop();
	
		if (current != NULL){
			
			// print Client handling message
			fprintf(stderr, "Thread %lu is handling client (%lu, %lu)\n", (unsigned long)pthread_self(), current->ip_addr, current->port_no);					

/***************Start of Handshake Message************************/
			// handshake current client
			bzero(buffer,MAXSIZE);
			strcpy(buffer, "100");
			n = write(current->sockfd, buffer, sizeof(buffer));
			if (n < 0) {
				perror("ERROR writing to socket");
			}
			
			// send payload size
			bzero(buffer, MAXSIZE);
			strcpy(buffer, "0");
			if((n = write(current->sockfd, buffer, sizeof(buffer))) == -1) {
				perror("ERROR writing to socket");
			}

			// send payload
			bzero(buffer, MAXSIZE);
			if((n = write(current->sockfd, buffer, sizeof(buffer))) == -1) {
				perror("ERROR writing to socket");
			}
			
			fprintf(stderr, "server sends handshaking: (100,0,)\n");

/*************End Handshake***************************************/


/*******************Start Handshake Response Message*************/

			// wait for handshake
			bzero(buffer,MAXSIZE);
			n = read(current->sockfd,buffer,MAXSIZE);
			if (n < 0){
				perror("Error reading from socket");
			}
			if ((id = atoi(buffer)) == 101){
				fprintf(stderr, "client sends handshake response: (101,0,)\n");
			}
			else {
				fprintf(stderr, "Error reading from socket.  Expected: 101, Recieved %s\n", buffer);
				bzero(buffer, MAXSIZE);
				strcpy(buffer, "105");
				n = write(current->sockfd, buffer, sizeof(buffer));
				if (n < 0) {
					perror("ERROR writing to socket");
				}
				close(current->sockfd);
				break;
			}
			
			// get payload size
			bzero(buffer, MAXSIZE);
			if((n = read(current->sockfd,buffer, MAXSIZE)) == -1) {
				perror("ERROR reading from socket");
			}
	
			payload_size = atoi(buffer);

			// get payload
			bzero(buffer, MAXSIZE);
			if((n = read(current->sockfd,buffer, MAXSIZE)) == -1) {
				perror("ERROR reading from socket");
			}

			printf("server sends handshaking: (%d,%d,\"%s\")\n", id, payload_size, buffer);
		
/*******************End Handshake Response***************************/
	
			while (true){				

/*******************Send Decryption Request**************************/

				bzero(buffer,MAXSIZE);
				n = read(current->sockfd,buffer,MAXSIZE);
				if (n < 0) {
					perror("ERROR reading from socket");
				}
				
/**********************Start of End of Request Message****************/

				// if end message, break
				if (atoi(buffer) == 104){
					close(current->sockfd);
					fprintf(stderr, "server closes the connection\n");
					break;
				}
				
/********************End of End of Request Message********************/

				else if ((id = atoi(buffer)) != 102){
					fprintf(stderr, "Error reading from socket.  Expected: 102, Recieved %s\n", buffer);
					bzero(buffer, MAXSIZE);
					strcpy(buffer, "105");
					n = write(current->sockfd, buffer, sizeof(buffer));
					if (n < 0) {
						perror("ERROR writing to socket");
					}
					close(current->sockfd);
					break;
				}


				// wait for decrypt text size
				bzero(buffer,MAXSIZE);
				n = read(current->sockfd,buffer,MAXSIZE);
				if (n < 0) {
					perror("ERROR reading from socket");
				}
				
				payload_size = atoi(buffer);
				
				// wait for decrypt text
				bzero(buffer,MAXSIZE);
				n = read(current->sockfd,buffer,MAXSIZE);
				if (n < 0) {
					perror("ERROR reading from socket");
				}
				//printf("client sends decryption request: (%d,%d,\"%s\")\n", id, payload_size, buffer);

/*********************End Decryption Request*************************/


/*********************Start of Decryption****************************/

				int i;
				char *newText = malloc(MAXSIZE);
				assert(newText != NULL);
				char *text = malloc(MAXSIZE);
				assert(text != NULL);
					
				// text = buffer
				bzero(text, MAXSIZE);
				bzero(newText, MAXSIZE);
				strcpy(text, buffer);

				// decrypt
				if (text != NULL){
					for(i = 0; i < strlen(text); i++){
					
						if(((text[i]>='a')&&(text[i]<'y'))||((text[i]>='A') && (text[i]<'Y'))){
							newText[i] =text[i] +2;
						}
						else if (text[i] == 'y'){
							newText[i] = 'a';
						}
						else if (text[i] == 'Y'){
							newText[i] = 'A';
						}
						else if (text[i] == 'z'){
							newText[i] = 'b';
						}
						else if (text[i] == 'Z'){
							newText[i] = 'B';
						}
						else{
							newText[i] = text[i];
						}
					}

/************************End of Decryption***************************/

/*******************Start of Decryption Response*********************/

					// write decrpytion signal to buffer
					bzero(buffer,MAXSIZE);
					strcpy(buffer, "103");
					n = write(current->sockfd, buffer, sizeof(buffer));
					if (n < 0) {
						perror("ERROR writing to socket");
					}
					
					// write decrpytion payload to buffer
					bzero(buffer,MAXSIZE);
					sprintf(buffer, "%lu", strlen(newText));
					n = write(current->sockfd, buffer, sizeof(buffer));
					if (n < 0) {
						perror("ERROR writing to socket");
					}
				
					// write decrpytion to buffer
					bzero(buffer, MAXSIZE);
					strcpy(buffer, newText);
					n = write(current->sockfd, buffer, sizeof(buffer));
					//fprintf(stderr, "server sends decryption response: (102,%lu,\"%s\")\n", strlen(newText), newText);
					if (n < 0) {
						perror("ERROR writing to socket");
					}	
		
			free(newText);
			free(text);
			
/************************End of Decryption Response*******************/

			}
		}

	// Print client finished message and free current client
	fprintf(stderr, "Thread %lu finished handling client (%lu, %lu)\n", (unsigned long)pthread_self(), current->ip_addr, current->port_no);					
	free(current);	
	}
}
	
}
	
