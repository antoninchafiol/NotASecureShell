all: nassh nasshS chlib.o


chlib.o: chlib/chlib.c chlib/chlib.h
	gcc -c chlib/chlib.c chlib/chlib.h

nassh: NASSHClient.c
	gcc -Wall -o nassh NASSHClient.c chlib.o 

nasshS: NASSHServer.c
	gcc -Wall -o nasshS NASSHServer.c chlib.o  -lpthread