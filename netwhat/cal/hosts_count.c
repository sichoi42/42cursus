#include <stdio.h>

void deci_to_bi(char *s, int n)
{
	int i;

	i = 7;
	while (n > 0)
	{
		s[i] = n % 2 + '0';
		i--;
		n /= 2;
	}
	while (i >= 0)
	{
		s[i] = '0';
		i--;
	}
}

int ft_power(int n, int r)
{
	if (r == 0)
		return (1);
	else
		return (n * ft_power(n, r-1));
}

void input_is_add(char *input)
{
	char bi[33];
	int n[4] = {0};
	int i=0,j=0,count=0, k;

	while (input[i])
	{
		if (input[i] == '.')
		{
			j++;
			i++;
		}
		n[j] *= 10;
		n[j] += input[i] - '0';
		i++;
	}
	i = 0;
	for (k=0;k<4;k++)
	{
		deci_to_bi(bi + i, n[k]);
		i += 8;
	}
	bi[32] = 0;
	for (i=0;i<32;i++)
		if (bi[i] == '1')
			count++;
	printf("totals assigned hosts == %d\n", ft_power(2, 32-count) - 2);
}

int argv_has_dot(char *input)
{
	int i=0;
	while (input[i])
	{
		if (input[i] == '.')
			return (1);
		i++;
	}
	return (0);
}

void input_is_len(char *input)
{
	int i, n;

	i = 0;
	n = 0;
	while (input[i])
	{
		n *= 10;
		n += input[i] - '0';
		i++;
	}
	printf("totals assigned hosts == %d\n", ft_power(2, 32-n) - 2);
}

int main(int argc, char **argv)
{
	if (argv_has_dot(argv[1]) == 1)
		input_is_add(argv[1]);
	else
		input_is_len(argv[1]);
}
