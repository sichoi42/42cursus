#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char	*term;

	term = getenv("*");
	if (!term)
		return (1);
	printf("Term Type is %s\n", term);
	return (0);
}
