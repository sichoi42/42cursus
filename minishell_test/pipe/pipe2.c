#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define READ 0
#define WRITE 1
#define BUFSIZE 4096

int	main(void)
{
	int		fd[2];
	int		ret;
	pid_t	pid;
	char	buf[BUFSIZE];

	if (pipe(fd) == -1)
		return (1);
	printf("Parent: fd for Read %d, fd for Write %d\n", fd[READ], fd[WRITE]);
	pid = fork();
	if (pid < 0)
	{
		close(fd[READ]);
		close(fd[WRITE]);
		return (1);
	}
	else if (pid > 0) //Parent
	{
		close(fd[READ]);
		strcpy(buf, "message from parent");
		write(fd[WRITE], buf, strlen(buf));
		close(fd[WRITE]);
	}
	else //Child
	{
		close(fd[WRITE]);
		ret = read(fd[READ], buf, BUFSIZE);
		buf[ret] = 0;
		printf("child got message: %s\n", buf);
		close(fd[READ]);
	}
	return (0);
}
