#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

extern char **environ;

int	main(int argc, char **argv)
{
	char	**new_argv;
	char	command[] = "ls";
	int		idx;

	new_argv = malloc(sizeof(char *) * argc + 1);
	new_argv[0] = command;

	idx = 0;
	while (++idx < argc)
		new_argv[idx] = argv[idx];
	new_argv[argc] = 0;
	if (execve("/bin/ls", new_argv, environ) == -1)
	{
		printf("error!\n");
		return (1);
	}
}
