CFLAG = -g -c -Wall -Werror
LIBS = -lpthread
CC = gcc

all: bin/main_sub_thread bin/rwlock bin/rwlockII

bin/rwlock: obj/rwlock.o
	$(CC) obj/rwlock.o $(LIBS) -o bin/rwlock
obj/rwlock.o: src/rwlock.c
	$(CC) $(CFLAG) src/rwlock.c -o obj/rwlock.o

bin/rwlockII: obj/rwlockII.o
	$(CC) obj/rwlockII.o $(LIBS) -o bin/rwlockII
obj/rwlockII.o: src/rwlockII.c
	$(CC) $(CFLAG) src/rwlockII.c -o obj/rwlockII.o

bin/main_sub_thread: obj/main_sub_thread.o
	$(CC) obj/main_sub_thread.o $(LIBS) -o bin/main_sub_thread
obj/main_sub_thread.o: src/main_sub_thread.c
	$(CC) $(CFLAG) src/main_sub_thread.c -o obj/main_sub_thread.o

clean:
	rm -rf bin/* obj/*	
