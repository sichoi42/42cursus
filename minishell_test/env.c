#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv, char **envp)
{
	char	*term;

	term = getenv("PATH");
	if (!term)
		return (1);
	printf("Term Type is %s\n", term);
	return (0);
}
