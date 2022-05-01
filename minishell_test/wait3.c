#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int	main(void)
{
	pid_t	pid;
	pid_t	ret;
	int		status;

	pid = fork();
	if (pid == -1)
		return (1);
	else if (pid == 0)
	{
		printf("Child: I don't know how I will be handled\n");
		usleep(10000000);
		return (3);
	}
	else
	{
		printf("Parent: I have a Child with pid %d\n", pid);
		ret = waitpid(pid, &status, WUNTRACED | WCONTINUED);
		printf("Parent: Successfully got status from %d Child\n", ret);
		if (WIFEXITED(status))
			printf("Parent: Exited!\vExit Code is %d, Signal is %d\n", WEXITSTATUS(status), WTERMSIG(status));
		else if (WIFSIGNALED(status))
			printf("Parent: Signaled!\vExit Code is %d, Signal is %d\n", WEXITSTATUS(status), WTERMSIG(status));
		else if (WIFSTOPPED(status))
			printf("Parent: Stopped!\vExit Code is %d, Signal is %d\n", WSTOPSIG(status), WTERMSIG(status));
		else if (WIFCONTINUED(status))
			printf("Parent: Continued!\vExit Code is %d, Signal is %d\n", WSTOPSIG(status), WTERMSIG(status));
	}
	return (0);
}
