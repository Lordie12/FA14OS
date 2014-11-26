/*---------------------------------------------------------------
Kaushik Kalyanaraman, kkalyana@eng.ucsd.edu
Priyanka Ganapathy, pganapat@eng.ucsd.edu

Loopback TCP Server
---------------------------------------------------------------*/

#include "headers.h"

void signal_callback_handler(int signum)
{
	printf("Caught signal %d", signum);
}

int main(int argc, char *argv[])
{
	int sockDesc, connected, t = 1;
	uint bytes;
	char recv_data[PACKET_SIZE];

	struct sockaddr_in s_addr, c_addr;    
	int sin_size;

	// Register signal and signal handler
	signal(SIGTERM, signal_callback_handler);

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
	while(1)
	{
		sin_size = sizeof(struct sockaddr_in);
		connected = accept(sockDesc, (struct sockaddr*)&c_addr, (socklen_t*)&sin_size);

		cout<<"\n Connection from Client IP: "<<inet_ntoa(c_addr.sin_addr)<<", Port: "<<ntohs(c_addr.sin_port)<<")"<<endl;
		memset(recv_data, 0, sizeof(recv_data));

		while(1)
		{
			bytes = recv(connected, recv_data, PACKET_SIZE, 0);
			if (bytes == -1 || bytes == 0)
				break;
			recv_data[bytes] = '\0';
			send(connected, recv_data, PACKET_SIZE, 0);  
		}
		close(connected);
	}       
	close(sockDesc);
	return 0;
} 
