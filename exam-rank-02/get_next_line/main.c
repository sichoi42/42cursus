#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
int	main(void)
{
	int		n;
	char	*line;

	line = NULL;
	int fd = open("b.txt", 0);
	while ((n = get_next_line(&line, fd)) > 0)
	{
		printf("%s\n", line);
		free(line);
		line = NULL;
	}
	printf("%s\n", line);
	free(line);
	line = NULL;
}
