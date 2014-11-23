/*---------------------------------------------------------------
Kaushik Kalyanaraman, kkalyana@eng.ucsd.edu
Priyanka Ganapathy, pganapat@eng.ucsd.edu

Loopback TCP Server
---------------------------------------------------------------*/

#include "headers.h"

#define PORT 5000

int main(int argc, char *argv[])
{
	int sockDesc, connected, t = 1;
	uint bytes;
	char recv_data[1024];
	const char* send_data = "ServeramOneBytesLongabcdefghijkl";       

	struct sockaddr_in s_addr, c_addr;    
	int sin_size;

	/*------------------------------------------------------------------------
	Setting up the server information, sockets, status and everything else
	------------------------------------------------------------------------*/
	s_addr.sin_family = AF_INET;         
	s_addr.sin_port = htons(PORT);     
	s_addr.sin_addr.s_addr = INADDR_ANY; 
	bzero(&(s_addr.sin_zero), 8); 

	if ((sockDesc = socket(AF_INET, SOCK_STREAM, 0)) == -1) \
	{
		perror("Socket");
		exit(1);
	}

	if (setsockopt(sockDesc, SOL_SOCKET, SO_REUSEADDR, &t, sizeof(int)) < 0) 
	{
		perror("Setsockopt");
		exit(1);
	}

	if (bind(sockDesc, (struct sockaddr *)&s_addr, sizeof(s_addr)) < 0) 
	{
		perror("Bind");
		exit(1);
	}

	if (listen(sockDesc, 5) < 0) 
	{
		perror("Listen");
		exit(1);
	}
	/*------------------------------------------------------------------------
	End of server setup
	------------------------------------------------------------------------*/

	cout<<"\nServer waiting for client on loopback interface, port 5000";

	while(1)
	{  
		sin_size = sizeof(struct sockaddr_in);
		connected = accept(sockDesc, (struct sockaddr*)&c_addr, (socklen_t*)&sin_size);

		cout<<"\n Connection from Client IP: "<<inet_ntoa(c_addr.sin_addr)<<", Port: "<<ntohs(c_addr.sin_port)<<")";

		while (1)
		{
			// memset(recv_data, 0, sizeof(recv_data));
			// bytes = recv(connected, recv_data, 1024, 0);
			// recv_data[bytes] = '\0';
			// cout<<"Received "<<bytes<<" bytes with content "<<recv_data;

			// send(connected, send_data, strlen(send_data), 0);  

			// if (strcmp(recv_data , "q") == 0 || strcmp(send_data , "Q") == 0)
			// {
			// 	close(connected);
			// 	break;
			// }
		}
	}       
	close(sockDesc);
	return 0;
} 
