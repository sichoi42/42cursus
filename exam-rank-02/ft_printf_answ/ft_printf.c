#include <unistd.h>
#include <stdarg.h>

typedef struct s_flag
{
	int	len;
	int	width;
	int	dot;
	int	preci;
}	t_flag;
t_flag	f;

void	init_flag()
{
	f.len = 0;
	f.width = 0;
	f.dot = 0;
	f.preci = 0;
}

void	write_n_count(char c, int n)
{
	if (n > 0)
	{
		for (int i=0;i<n;i++)
			write(1, &c, 1);
		f.len += n;
	}
}

int	ft_atoi(const char *s, int *idx)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (s[i] && s[i] >= '0' && s[i] <= '9')
	{
		n *= 10;
		n += s[i] - '0';
		i++;
	}
	*idx += i;
	return (n);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	print_s(char *s)
{
	int	len;

	if (s == 0)
		s = "(null)";
	len = ft_strlen(s);
	if (f.dot == 1 && f.preci < len)
		len = f.preci;
	write_n_count(' ', f.width - len);
	write(1, s, len);
	f.len += len;
}

int	get_len(int d)
{
	int	n;

	n = 0;
	if (d == -2147483648)
		return (11);
	else if (d < 0)
	{
		n++;
		d = -d;
	}
	else if (d == 0)
		return (1);
	while (d > 0)
	{
		d /= 10;
		n++;
	}
	return (n);
}

void	ft_putnbr_rec(long long d)
{
	if (d < 0)
	{
		d *= -1;
		write_n_count('-', 1);
	}
	if (d >= 10)
	{
		ft_putnbr_rec(d / 10);
		ft_putnbr_rec(d % 10);
	}
	else
		write_n_count(d + '0', 1);
}

void	ft_putnbr(long long d)
{
	if (d == 0 && f.dot == 1 && f.preci == 0)
		return ;
	ft_putnbr_rec(d);
}

void	print_d(int d)
{
	int	len;

	len = get_len(d);
	if (f.dot == 1)
	{
		if (d < 0)
			f.preci++;
		if (d == 0 && f.preci == 0)
			len = 0;
	}
	if (f.width > f.preci && f.width > len)
	{
		if (f.preci > len)
		{
			write_n_count(' ', f.width - f.preci);
			if (d < 0)
				write_n_count('-', 1);
			write_n_count('0', f.preci - len);
			if (d < 0)
			{
				ft_putnbr(-d);
				return ;
			}
		}
		else
			write_n_count(' ', f.width - len);
	}
	else if (f.preci > f.width && f.preci > f.len)
	{
		if (d < 0)
			write_n_count('-', 1);
		write_n_count('0', f.preci - len);
		if (d < 0)
		{
			ft_putnbr(-d);
			return ;
		}
	}
	ft_putnbr(d);
}

int	get_len_x(unsigned int x)
{
	int	n;

	n = 0;
	if (x == 0)
		return (1);
	while (x > 0)
	{
		x /= 16;
		n++;
	}
	return (n);
}
void	ft_putnbr_x_rec(unsigned int x)
{
	if (x >= 16)
	{
		ft_putnbr_x_rec(x / 16);
		ft_putnbr_x_rec(x % 16);
	}
	else
	{
		if (x < 10)
			write_n_count(x + '0', 1);
		else
			write_n_count(x - 10 + 'a', 1);
	}
}
void	ft_putnbr_x(unsigned int x)
{
	if (x == 0 && f.dot == 1 && f.preci == 0)
		return ;
	ft_putnbr_x_rec(x);
}

void	print_x(unsigned int x)
{
	int	len;

	len = get_len_x(x);
	if (x == 0 && f.dot == 1 && f.preci == 0)
		len = 0;
	if (f.width > f.preci && f.width > len)
	{
		if (f.preci > len)
		{
			write_n_count(' ', f.width - f.preci);
			write_n_count('0', f.preci - len);
		}
		else
			write_n_count(' ', f.width - len);
	}
	else if (f.preci > f.width && f.preci > len)
		write_n_count('0', f.preci - len);
	ft_putnbr_x(x);
}

int	ft_printf(const char *s, ...)
{
	va_list ap;
	int		i;

	init_flag();
	if (s)
	{
		va_start(ap, s);
		i = 0;
		while (s[i])
		{
			if (s[i] == '%' && s[i + 1])
			{
				if (s[i + 1] >= '0' && s[i + 1] <= '9')
					f.width = ft_atoi(&s[i + 1], &i);
				if (s[i + 1] == '.')
				{
					i++;
					f.dot = 1;
					if (s[i + 1] >= '0' && s[i + 1] <= '9')
						f.preci = ft_atoi(&s[i + 1], &i);
				}
				if (s[i + 1] == 's')
				{
					print_s(va_arg(ap, char *));
					i++;
				}
				else if (s[i + 1] == 'd')
				{
					print_d(va_arg(ap, int));
					i++;
				}
				else if (s[i + 1] == 'x')
				{
					print_x(va_arg(ap, unsigned int));
					i++;
				}
			}
			else
				write_n_count(s[i], 1);
			i++;
		}
		va_end(ap);
	}
	return (f.len);
}

// #include <stdio.h>
// //n - 10
// int main(void)
// {
// 	int my, pf;
// 	pf = printf("pf = |%d|\n", 2147483648);
// 	my = ft_printf("my = |%d|\n", 2147483648);
// 	printf("pf = %d\n", pf);
// 	printf("my = %d\n", my);
// }
