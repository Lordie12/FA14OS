/*---------------------------------------------------------------
Kaushik Kalyanaraman, kkalyana@eng.ucsd.edu
TCP Client
---------------------------------------------------------------*/

#include "headers.h"

void sendQ(int sockDesc)
{
	send(sockDesc, reinterpret_cast<void*>('q'), sizeof(char), 0);
}

char* create_packet(uint size)
{
	char* newPacket = new char[size];
	memset(newPacket, 'a', size);
	return newPacket;
}

int main()
{
	char recv_data[PACKET_SIZE];
	struct sockaddr_in s_addr;  
	int sockDesc;
	uint bytes;
	char* packet = create_packet(PACKET_SIZE);
	longVar tot = 0, start, end, avgLatency;

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

	for(int i = 0; i < NUM_PACKETS; i++)
	{
		start = mach_absolute_time();
		send(sockDesc, packet, PACKET_SIZE, 0);
		bytes = recv(sockDesc, recv_data, PACKET_SIZE, 0);
		if (bytes == -1 || bytes == 0)
		{
			perror("Recv");
			break;
		}
		end = mach_absolute_time();
	 	tot += end - start;
	}   

	//Compute average one way transmission time
	avgLatency = tot / (2 * NUM_PACKETS);
	cout<<endl<<" Bandwidth is "<<CALCSIZEBYTES(NUM_PACKETS) / (float)(NStoS(avgLatency) * 1024 * 1024 * 1024)<<" GB/s"<<endl;
	cout<<" Localhost latency is "<<avgLatency / 1000<<" us"<<endl;
	close(sockDesc);
	return 0;
}
