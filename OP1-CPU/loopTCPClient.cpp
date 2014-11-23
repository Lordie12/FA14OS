/*---------------------------------------------------------------
Kaushik Kalyanaraman, kkalyana@eng.ucsd.edu
Priyanka Ganapathy, pganapat@eng.ucsd.edu

Loopback TCP Client
---------------------------------------------------------------*/

#include "headers.h"

#define LOOPBACKIP "127.0.0.1"

void sendQ(int sockDesc)
{
	send(sockDesc, reinterpret_cast<void*>('q'), sizeof(char), 0);
}

int main()
{
	char recv_data[1024];
	struct sockaddr_in s_addr;  
	int sockDesc, bytes_recieved, i = 0;;
	uint bytes;
	const char* send_data = "ClientamOneBytesLongabcdefghijkl";

	if ((sockDesc = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
	{
	    perror("Socket");
	    exit(1);
	}

	memset(&s_addr, '0', sizeof(struct sockaddr_in));
	s_addr.sin_family = AF_INET;     
	s_addr.sin_port = htons(5000);   
	inet_pton(AF_INET, LOOPBACKIP, &s_addr.sin_addr);

	if (connect(sockDesc, (struct sockaddr *)&s_addr,
	            sizeof(struct sockaddr)) < 0) 
	{
	    perror("Connect");
	    exit(1);
	}

	while(1)
	{
		send(sockDesc, send_data, strlen(send_data), 0);
		bytes = recv(sockDesc, recv_data, 1024, 0);
		recv_data[bytes] = '\0';

		cout<<"\nRecieved "<<bytes<<" bytes with content "<<recv_data;
	 
	 	i++;
	 	if (i == 10)
	 	{
	 		sendQ(sockDesc);
	 		break;
	 	}
	}   
	cout<<endl;
	return 0;
}
