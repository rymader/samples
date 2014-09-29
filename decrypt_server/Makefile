CC = gcc
DEBUG = -g
CFLAGS = -Wall

all: decryption_server decryption_client

decryption_server: decryption_server.o retrieve.o
	$(CC) $^ -lpthread -o $@ -lnsl

decryption_server.o: decryption_server.c retrieve.h 
	$(CC) $(DEBUG) $(CFLAGS) -c decryption_server.c

decryption_client: decryption_client.o retrieve.o
	$(CC) $^ -lpthread -o $@ -lnsl

decryption_client.o: decryption_client.c retrieve.h 
	$(CC) $(DEBUG) $(CFLAGS) -c decryption_client.c


retrieve.o: retrieve.h retrieve.c
	$(CC) $(DEBUG) $(CFLAGS) -c retrieve.c

clean: 
	rm -f *.o decryption_server decryption_client



