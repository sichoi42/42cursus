#include <stdio.h>

int ft_power(int n, int r)
{
	if (r == 0)
		return (1);
	else
		return (n * ft_power(n, r-1));
}

void print_deci_add(char *s)
{
	int i=0, n[4]={0}, j=0;
	while (s[i])
	{
		n[j] += (s[i] - '0') * ft_power(2, 7 - (i % 8));
		i++;
		if (i % 8 == 0)
			j++;
	}
	printf("%d.%d.%d.%d\n", n[0], n[1], n[2], n[3]);
}

void print_net_add(char *s1, char *s2)
{
	int i =0;
	char s3[33];
	while (i < 32)
	{
		if (s1[i] - '0' && s2[i] - '0')
			s3[i] = '1';
		else
			s3[i] = '0';
		i++;
	}
	s3[i] = 0;
	printf("network add == ");
	print_deci_add(s3);
}

void print_broad_add(char *s1, char *s2, int j)
{
	int i =0;
	char s3[33];
	while (i < j)
	{
		if (s1[i] - '0' && s2[i] - '0')
			s3[i] = '1';
		else
			s3[i] = '0';
		i++;
	}
	while (i < 32)
	{
		if (s3[i] == '1')
			s3[i] = '0';
		else
			s3[i] = '1';
		i++;
	}
	s3[i] = 0;
	printf("broadcast add == ");
	print_deci_add(s3);
}

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

int get_bi_info(char *input, char *s1, char *s2)
{
	int i = 0, n[4] = {0}, j, k;

	for (j=0;input[i] != '/';j++)
	{
		while (input[i] != '.' && input[i] != '/')
		{
			n[j] *= 10;
			n[j] += input[i] - '0';
			i++;
		}
		if (input[i] == '/')
			break ;
		i++;
	}
	for (k=0;k<4;k++)
	{
		deci_to_bi(s1, n[k]);
		s1 += 8;
	}
	s1[32] = 0;
	i++;
	j = 0;
	while (input[i])
	{
		j *= 10;
		j += input[i] - '0';
		i++;
	}
	i = 0;
	while (i < j)
	{
		s2[i] = '1';
		i++;
	}
	while (i < 32)
	{
		s2[i] = '0';
		i++;
	}
	s2[i] = 0;
	return (j);
}

int main(int argc, char **argv)
{
	char ip_add_bi[33];
	char subnet_mask_bi[33];
	int i = get_bi_info(argv[1], ip_add_bi, subnet_mask_bi);
	printf("%s\n", ip_add_bi);
	printf("%s\n", subnet_mask_bi);
	print_net_add(ip_add_bi, subnet_mask_bi);
	print_broad_add(ip_add_bi, subnet_mask_bi, i);
}
