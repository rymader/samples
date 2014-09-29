CC = g++
DEBUG = -g
CFLAGS = -Wall

scheduler: main.o scheduler.o RBT.o
	$(CC) $^ -o $@

main.o: main.cpp scheduler.h RBT.h
	$(CC) $(DEBUG) $(CFLAGS) -c main.cpp

scheduler.o: scheduler.cpp scheduler.h RBT.h
	$(CC) $(DEBUG) $(CFLAGS) -c scheduler.cpp

RBT.o: RBT.cpp RBT.h scheduler.h
	$(CC) $(DEBUG) $(CFLAGS) -c RBT.cpp

clean:
	rm -f *.o scheduler
