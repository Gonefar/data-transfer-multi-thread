#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <time.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <pthread.h>




#define SERVPORT       7350
#define BACKLOG        10
#define	MAX_BUFF_SIZE  2000000
#define SEND_TIMES     500
#define BUFFER_SIZE    256
#define DATA_SIZE      1024
#define RECV_MODE      0
#define SEND_MODE      1
#define PACK_NUM       1000000
#define PACK_SIZE      128
#define CALCU_RATE_TIME_DIFF_MS  10

typedef struct _thread_arg
{
	int recvbytes;
	int sockfd;
	int recvpack;
	int flag;
}thread_arg;

