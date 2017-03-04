#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


#define PORT 8000
#define MAXSZ 100
int main()
{
	char *servIP = "127.0.0.1"; 
	int sockfd;//to create socket
	int n,n1,n2;
	int array[32],temp[100];
	char buffer[100];
    char charArray[2];
	struct sockaddr_in serverAddress;//client will connect on this
	FILE *file1;

	file1=fopen("input.txt","r");
	if(file1==NULL)
	{
	fprintf(stderr,"Can not open input file\n");
	exit(1);
	}
	while(fscanf(file1,"%d %d", &n1,&n2)!=EOF)
	charArray[0]=n1;
	charArray[1]=n2;

	char msg1[MAXSZ];
	char msg2[MAXSZ];
	
	//create socket
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	//initialize the socket addresses
	memset(&serverAddress,0,sizeof(serverAddress));
	serverAddress.sin_family=AF_INET;
	serverAddress.sin_port=htons(PORT);
	int rtnVal = inet_pton(AF_INET, servIP, &serverAddress.sin_addr.s_addr);
	if (rtnVal == 0)
		printf("inet_pton() failed invalid address string");
	else if (rtnVal < 0)
		printf("inet_pton() failed");
	//client  connect to server on port
	connect(sockfd,(struct sockaddr *)&serverAddress,sizeof(serverAddress));
	



		send(sockfd,charArray,2,0);
			//char arr[100];	
		recv(sockfd, buffer, 100, 0);	
		printf("The resuled number is: \n");
		for(int i=0;i<33;i++)
		{
			array[i]=buffer[i];
			printf("%d",array[i]);
		}
		printf("\n");
		//printf("%c" ,array[0]);
		
	//}

	return 0;
}
