#define _GNU_SOURCE
#include <unistd.h>
#include <sys/syscall.h>
#include <stdio.h>
#include <errno.h>
#define SYS_melike 548

int main(int argc, char **argv)
{
	if (argc <=1){
		printf("Must provide a string to give to system call.\n");
		return -1;
}

char *arg = argv[1];
printf("Making system call with \"%s\".\n", arg);
long res=syscall(SYS_melike, arg);

	if(res == -1)
		fprintf(stderr, "melike failed, errno = %d\n", errno);
	else
		printf("System call melike returned %ld.\n", res);
		return res;
}
