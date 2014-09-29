#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include "retrieve.h"
#include <unistd.h>

#define MAXSIZE 160*sizeof(char)
#define ERROR_MESSAGE 105

void error(char *msg) {
	
	perror(msg);
	exit(1);
}



int main(int argc, char *argv[]) {

	int sockfd, portno, n, size, id, i;
	char *outfile = malloc(MAXSIZE);	
	char buffer[MAXSIZE];
	FILE *fp;
	struct hostent *server;
	struct sockaddr_in serv_addr;
	
	
	if(argc < 4) {
		fprintf(stderr, "usage %s hostname port\n", argv[0]);
		exit(1);
	}
	
	char files[argc - 3][MAXSIZE];
	portno = atoi(argv[2]);		

	if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1){
		error("ERROR: Failed to create socket");
	}

	if((server = gethostbyname(argv[1])) == NULL) {
		fprintf(stderr,"ERROR, no such host\n");
		exit(0);
	}

	bzero((char *) &serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	bcopy((char *)server->h_addr,
		(char *)&serv_addr.sin_addr.s_addr,
		server->h_length);
	serv_addr.sin_port = htons(portno);

	if(connect(sockfd,(struct sockaddr *)&serv_addr, sizeof
		(serv_addr)) == -1) {
		error("ERROR connecting");
	}

	// print to stdout
	printf("client connects\n");
	
/***************Start of Handshake Message************************/


	// get id
	bzero(buffer, MAXSIZE);
	if((n = read(sockfd,buffer, MAXSIZE)) == -1) {
		error("ERROR reading from socket");
	}

	// error check
	if((id = atoi(buffer)) != 100) {
		bzero(buffer, MAXSIZE);
		strcpy(buffer, "105");
		if((n = write(sockfd, buffer, sizeof(buffer))) == -1) {
			error("ERROR writing to socket");
		}
		close(sockfd);
		error("ERROR: Handshake failed");

	}
		
	// get payload size
	bzero(buffer, MAXSIZE);
	if((n = read(sockfd,buffer, MAXSIZE)) == -1) {
			error("ERROR reading from socket");
	}
	
	size = atoi(buffer);

	// get payload
	bzero(buffer, MAXSIZE);
	if((n = read(sockfd,buffer, MAXSIZE)) == -1) {
			error("ERROR reading from socket");
	}

	printf("server sends handshaking: (%d,%d)\n", id, size);

/*************End Handshake***************************************/


/*******************Start Handshake Response Message*************/

	// send id
	bzero(buffer, MAXSIZE);
	strcpy(buffer, "101");
	if((n = write(sockfd, buffer, sizeof(buffer))) == -1) {
		error("ERROR writing to socket");
	}

	// send payload size
	bzero(buffer, MAXSIZE);
	strcpy(buffer, "0");
	if((n = write(sockfd, buffer, sizeof(buffer))) == -1) {
		error("ERROR writing to socket");
	}

	// send payload
	bzero(buffer, MAXSIZE);
	if((n = write(sockfd, buffer, sizeof(buffer))) == -1) {
		error("ERROR writing to socket");
	}

	//print to stdout
	printf("client sends handshake response: (101,0)\n");
	
/*******************End Handshake Response***************************/


/*******************Begin For Loop To iterate through Files**********/

	for (i = 3; i < argc; i++){
		
		char *line = malloc(MAXSIZE);
		fp = open_file(argv[i], "r");	
		strcpy(outfile, argv[i]);
		strcat(outfile, ".decrypted");
		
		// if file fails to open, close socket and exit client
		if (fp == NULL) {
			close(sockfd);
			exit(1);
		}

		while((line = getLine(line, fp)) != NULL) {

/*******************Send Decryption Request**************************/
	
			// send idzsr yq y jmtcp fc umsjb fytc njyacb fgkqcjd gl y dyjqc nmqgrgml. Fc

			bzero(buffer, MAXSIZE);
			strcpy(buffer, "102");
			if((n = write(sockfd, buffer, sizeof(buffer))) == -1) {
				error("ERROR writing to socket");
			}

		
			// send payload size
			bzero(buffer, MAXSIZE);
			sprintf(buffer, "%d" , (int)strlen(line));
			if((n = write(sockfd, buffer, sizeof(buffer))) == -1) {
				error("ERROR writing to socket");
			}
			
			// send payload
			bzero(buffer, MAXSIZE);
			strcpy(buffer, line);
			if((n = write(sockfd, buffer, sizeof(buffer))) == -1) {
				error("ERROR writing to socket");
			}
	
			//print to stdout
			printf("client sends decryption request: (102,%d,\"%s\")\n", (int)strlen(line), line);
		
/*********************End Decryption Request*************************/
		

/*******************Start of Decryption Response********************/

			// get id
			bzero(buffer, MAXSIZE);
			if((n = read(sockfd, buffer, MAXSIZE)) == -1) {
				error("ERROR reading from socket");
			}			
		
			// error check
			if((id = atoi(buffer)) != 103) {
				bzero(buffer, MAXSIZE);
				strcpy(buffer, "105");
				if((n = write(sockfd, buffer, sizeof(buffer))) == -1) {
					error("ERROR writing to socket");
				}
				close(sockfd);
				error("ERROR: Handshake failed");

			}
		
			// get size of payload
			bzero(buffer, MAXSIZE);
			if((n = read(sockfd, buffer, MAXSIZE)) == -1) {
				error("ERROR reading from socket");
			}	
			size = atoi(buffer);
		
			// get payload		
			bzero(buffer, MAXSIZE);
			if ((n = read(sockfd, buffer, MAXSIZE)) == -1) {
				error("ERROR reading from socket");
			}
		
			//print to stdout
			printf("server sends decryption response: (%d,%d,\"%s\")\n", id, size, buffer);
/************************End of Decryption Response*******************/


			outLog(buffer, outfile);
			}
/*******************End For Loop To iterate through Files*************/

			
		fclose(fp);
		free(line);
	}
	
/**********************Start of End of Request Message****************/

	// send id
	bzero(buffer, MAXSIZE);
	strcpy(buffer, "104");
	if((n = write(sockfd, buffer, sizeof(buffer))) == -1) {
		error("ERROR writing to socket");
	}
	
	// send size of payload
	bzero(buffer, MAXSIZE);
	strcpy(buffer, "0");
	if((n = write(sockfd, buffer, sizeof(buffer))) == -1) {
		error("ERROR writing to socket");
	}
	
	// send payload
	bzero(buffer, MAXSIZE);
	if((n = write(sockfd, buffer, sizeof(buffer))) == -1) {
		error("ERROR writing to socket");
	}
	
	// print to stdout
	printf("client sends end of request: (104,0)\n");
	
/********************End of End of Request Message********************/
	
	if((n = close(sockfd)) == -1) {
		error("ERROR closing the socket");
	}

	return 0;

}








	
		
	
