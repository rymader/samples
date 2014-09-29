/*************************************************************
	
	Header file for retrieve 

	Authors:
	Ryan Mader
	Madison Hennig

**************************************************************/

#ifndef RETRIEVE_H
#define RETRIEVE_H
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct qnode {
	int sockfd;
	unsigned long ip_addr;
	unsigned long port_no;
	struct qnode *next;
} NODE;

NODE *HEAD;

FILE *open_file(char *filename, char *tag);
char *getLine(char*, FILE*);
int addNode(int sockfd, unsigned long ip_addr, unsigned long port_no);
void makeClientList();
void outLog(char *line, char *path);

void decrypt(char* args[]);
NODE *pop();

#endif
