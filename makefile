all: nassh nasshS

nassh: NASSHClient.c
	gcc -Wall -o nassh NASSHClient.c

nasshS: NASSHServer.c
	gcc -Wall -o nasshS NASSHServer.c -lpthread