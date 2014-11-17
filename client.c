#include "headFile.h"
#include "func.c"

int main(int argc, char *argv[])
{
	int sockfd;
	struct hostent *host;
	struct sockaddr_in serv_addr;

	struct timeval tcpStart, tcpEnd;
	float timeuse;

	Dect_input_parm_num(argc);
	host = gethostbyname(argv[1]);
	Dect_hostname(host);

	sockfd= Socket(AF_INET, SOCK_STREAM, 0);
	init_server_add_at_client(&serv_addr, host);
	Connect(sockfd, serv_addr);

	Print_Date_Time();
	gettimeofday(&tcpStart, NULL);

	Message_Process_Client(sockfd);

	gettimeofday(&tcpEnd, NULL);

	timeuse = TimeUsed(&tcpStart, &tcpEnd);
	printf("Used Time: %f\n", timeuse);
	Print_Date_Time();
	
	close(sockfd);
	return 0;
}

