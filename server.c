#include "headFile.h"
#include "func.c"

int main()
{
	int sockfd,client_fd;
	int i = 0, th_num = 8;
	struct sockaddr_in my_addr;
	struct sockaddr_in remote_addr;
	pthread_t tids[th_num];
	thread_arg targ[th_num];
	
	Init_Thread_Argc(targ, th_num);
	sockfd = Socket(AF_INET, SOCK_STREAM, 0);
	init_server_add_at_server(&my_addr);
	Bind(sockfd, &my_addr);
	Listen(sockfd, BACKLOG);
	printf("Listening:\n");
	while(1)
	{
		client_fd = Accept(sockfd, &remote_addr);		
		printf("Received a connection!\n");
		if((int)client_fd > 0)
			{
				targ[i].recvbytes = 0;
				targ[i].sockfd    = client_fd;
			}
		
		if( (int)client_fd > 0 && \
			!pthread_create(&tids[i], NULL, (void *)&Message_Process_Server, (void *)&targ[i]) )
			{
				i++;

				if(i >= (th_num - 1))
					{
						printf("Threads use up\n");
						return -1;
					}
			}

		
	}
	
	close(client_fd);
	close(sockfd);
	return 0;
}
