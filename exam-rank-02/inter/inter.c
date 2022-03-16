#include <unistd.h>

int main(int argc, char **argv)
{
	int	check[256] = {0,};
	int	i, j;

	if (argc == 3)
	{
		i = 2;
		while (i > 0)
		{
			j = 0;
			while (argv[i][j])
			{
				if (i == 2 && check[(unsigned char)argv[i][j]] == 0)
					check[(unsigned char)argv[i][j]]++;
				if (i == 1 && check[(unsigned char)argv[i][j]] == 1)
				{
					write(1, &argv[i][j], 1);
					check[(unsigned char)argv[i][j]]++;
				}
				j++;
			}
			i--;
		}
	}
	write(1, "\n", 1);
	return (0);
}