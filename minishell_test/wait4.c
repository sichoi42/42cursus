#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void	handler(int sig)
{
	pid_t	ret;
	int		status;

	if (sig != SIGCHLD)
		exit(1);
	ret = waitpid(-1, &status, WNOHANG);
	printf("Parent: Successfully got status from %d Child\n", ret);
	printf("Parent: Exit Code is %d, Signal is %d\n", WEXITSTATUS(status), WTERMSIG(status));
	exit(0);
}

int		main(void)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		return (1);
	else if (!pid)
	{
		printf("Child: I am going to take a sleep for 5 seconds\n");
		usleep(5000000);
		return (0);
	}
	else
	{
		printf("Parent: I have a Child which pid is %d\n", pid);
		signal(SIGCHLD, handler);
		while(1)
			;
	}
	return (0);
}
