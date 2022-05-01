#include <stddef.h>
#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	char	*argv[] = {"ls", "-al", "test.txt", NULL};
	execv("/bin/ls", argv);
	return (0);
}
