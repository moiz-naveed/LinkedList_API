CC = gcc

CFLAGS = -std=c99 -pedantic -Wall -c -Iinclude

all:
	make build
	
main.o:
	$(CC) $(CFLAGS) src/main.c -o bin/main.o

testmain.o:
	$(CC) $(CFLAGS) src/testmain.c -o bin/testmain.o

linkedlistAPI.o:
	$(CC) $(CFLAGS) src/linkedlistAPI.c -o bin/linkedlistAPI.o		

traffic.o:
	$(CC) $(CFLAGS) src/traffic.c -o bin/traffic.o

build:  main.o linkedlistAPI.o traffic.o testmain.o
	$(CC) bin/main.o bin/linkedlistAPI.o bin/traffic.o -Iinclude -o bin/runMe  
	$(CC) bin/testmain.o bin/linkedlistAPI.o bin/traffic.o -Iinclude -o bin/testMe 

run:
	./bin/runMe 
	
clean:
	rm bin/*.o
	rm bin//runMe
	rm bin//testMe
	
