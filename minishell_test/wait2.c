#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void	print_msg(int sig)
{
	printf("Child: I got %d Signal\n", sig);
}

int	main(void)
{
	pid_t	pid;
	pid_t	ret;
	int		status;

	pid = fork();
	if (pid == -1)
		return (1);
	else if (!pid)
	{
		signal(SIGCONT, print_msg);
		printf("Child: I will be stopped\n");
		while (1);
	}
	else
	{
		printf("Parent: I have a Child with pid %d\n", pid);
		ret = waitpid(pid, &status, WUNTRACED);
		printf("Parent: Child has been stopped\n");
		printf("Parent: Successfully got status from %d Child\n", ret);
		if (WIFSTOPPED(status))
			printf("Parent: Exit Code is %d, Signal is %d\n", WSTOPSIG(status), WTERMSIG(status));
		usleep(10000000);
		ret = waitpid(pid, &status, WCONTINUED | WNOHANG);
		printf("Parent: Child has been continued\n");
		printf("Parent: Successfully got status from %d Child\n", ret);
		if (WIFCONTINUED(status))
			printf("Parent: Exit Code is %d, Signal is %d\n", WSTOPSIG(status), WTERMSIG(status));
	}
	return (0);
}
