#include<stdio.h>
#include<sys/types.h>//socket
#include<sys/socket.h>//socket
#include<string.h>//memset
#include<stdlib.h>//sizeof
#include<netinet/in.h>//INADDR_ANY
#include<unistd.h>

#define PORT 8000
#define MAXSZ 100
int main()
{
	int sockfd;//to create socket
	int newsockfd;//to accept connection

	struct sockaddr_in serverAddress;//server receive on this address
	struct sockaddr_in clientAddress;//server sends to client on this address

	int n;
	char msg[MAXSZ];
    char buffer[1024];
	int array[100];
	int temp[2];
	int clientAddressLength;
	int pid;

	//create socket
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	//initialize the socket addresses
	memset(&serverAddress,0,sizeof(serverAddress));
	serverAddress.sin_family=AF_INET;
	serverAddress.sin_addr.s_addr=htonl(INADDR_ANY);
	serverAddress.sin_port=htons(PORT);

	//bind the socket with the server address and port
	bind(sockfd,(struct sockaddr *)&serverAddress, sizeof(serverAddress));

	//listen for connection from client
	listen(sockfd,5);

	while(1)
	{
		//parent process waiting to accept a new connection
		//printf("\n*****server waiting for new client connection:*****\n");
		clientAddressLength=sizeof(clientAddress);
		newsockfd=accept(sockfd,(struct sockaddr*)&clientAddress,&clientAddressLength);
		//printf("connected to client: %s\n",inet_ntoa(clientAddress.sin_addr));

		//child process is created for serving each new clients
		pid=fork();
		if(pid==0)//child process rec and send
		{
			//rceive from client
			//while(1)
			//{

			n=recv(newsockfd, buffer, 100, 0);
			if(n==0)
				{
					close(newsockfd);
					break;
				}


int value1=(int)buffer[0];
int value2=(int)buffer[1];

printf("Value 1 is %d and value 2 is %d\n", value1, value2);

int m1= ~value1;
int m2= ~value2;

int sum= m1+m2;

int i=0;
int c,k;
for (c = 32; c >= 0; c--)
  {
    k = sum >> c;
 
    if (k & 1)
		{
	  	array[i]=1;
		i++;
		}
    else
		{
      	array[i]=0;
		i++;
		}
  }




char str[MAXSZ];
			
			
		
			for(int j = 0;j<i;j++)
			{
				str[j]=array[j];
			}
			printf("Below is the result that is going to be send to client\n");
			for(int j=0;j<i;j++)
			{
		    printf("%d ",array[j]);
		
			}
			array[i]='\0';


			
			send(newsockfd,str,i+1,0);


			//}//close interior while
			exit(0);
		}
		else
		{
			close(newsockfd);//sock is closed BY PARENT
		}
	}//close exterior while

	return 0;
}
