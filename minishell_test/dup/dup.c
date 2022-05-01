#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
	int		fd;
	int		tmp;
	int		ret;
	char	buf[4096];

	tmp = open("test.txt", O_RDONLY);
	fd = dup2(tmp, STDIN_FILENO);
	printf("tmp: %d\tfd: %d\n", tmp, fd);
	close(tmp);
	if (fd == -1)
		return (1);
	ret = read(STDIN_FILENO, buf, 4096);
	if (ret == -1)
		return (1);
	buf[ret] = 0;
	write(STDOUT_FILENO, buf, strlen(buf));
	return (0);
}
