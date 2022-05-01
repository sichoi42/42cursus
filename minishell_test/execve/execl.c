#include <unistd.h>
#include <stddef.h>

int	main(void)
{
	execl("/bin/ls", "ls", "-al", "test.txt", NULL);
	return (0);
}
