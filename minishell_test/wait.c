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
		printf("Child: I will yield Exit Code 2\n");
		return (2);
	}
	else
	{
		printf("Parent: I have a Child with pid %d\n", pid);
		ret = wait(&status);
		printf("Parent: Successfully got status from %d Child\n", ret);
		if (WIFEXITED(status))
			printf("Parent: Exit Code is %d, Signal is %d\n", WEXITSTATUS(status), WTERMSIG(status));
	}
	return (0);
}
