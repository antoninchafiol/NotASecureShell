all: nassh nasshS


chlib.o: chlib.c chlib.h
	gcc -c chlib.c chlib.h -Wall

nassh: NASSHClient.c chlib.o
	gcc -Wall -o nassh NASSHClient.c chlib.o

nasshS: NASSHServer.c chlib.o
	gcc -Wall -o nasshS NASSHServer.c chlib.o  -lpthread

clear:
	rm *.o