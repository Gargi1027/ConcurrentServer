all:
	gcc -o server -std=gnu99 Concurrent.c
	gcc -o client -std=gnu99 ConcurrentClient.c
	
