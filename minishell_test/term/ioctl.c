#include <sys/ioctl.h>
#include <unistd.h>
#include <stdio.h>

int main(void)
{
	struct winsize	size;

	if (ioctl(STDIN_FILENO, TIOCGWINSZ, &size) == -1)
		return (1);
	printf("Terminal Row Size: %d\n", size.ws_row);
	printf("Terminal Col Size: %d\n", size.ws_col);
}
