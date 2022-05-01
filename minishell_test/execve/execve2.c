#include <unistd.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int		i;
	char	**args;

	if (argc == 1)
		return (1);
	args = (malloc(sizeof(char *) * argc));
	if (!args)
		return (1);
	args[argc - 1] = NULL;
	i = -1;
	while (++i < argc - 1)
		args[i] = argv[i + 1];
	execve("/usr/bin/gcc", args, NULL);
	free(args);
	return (0);
}
