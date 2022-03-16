#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

typedef struct flag
{
	int width;
	int preci;
	int len;
	int dot;
}flag;
flag f;

int	ft_atoi(const char *s, int *idx)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (s[i] && s[i] >= '0' && s[i] <= '9')
	{
		len *= 10;
		len += s[i] - '0';
		i++;
	}
	*idx += i;
	return (len);
}

int	ft_strlen(char *s)
{
	int i;

	i = 0;
	if (s)
	{
		while (s[i])
			i++;
	}
	return (i);
}

void	write_n_count(int n, char c)
{
	if (n > 0)
	{
		for (int i=0;i<n;i++)
		{
			write(1, &c, 1);
			f.len++;
		}
	}
}
//%10.5s
void	print_s(char *s)
{
	if (!s)
		s = "(null)";
	int len_s = ft_strlen(s);
	if (f.dot == 1 && len_s > f.preci && f.preci >= 0)
		len_s = f.preci;
	write_n_count(f.width - len_s, ' ');
	write(1, s, len_s);
	f.len += len_s;
}

void	ft_putnbr_rec(long long nb)
{
	if (nb < 0)
	{
		nb *= -1;
		write_n_count(1, '-');
	}
	if (nb >= 10)
	{
		ft_putnbr_rec(nb / 10);
		ft_putnbr_rec(nb % 10);
	}
	else
		write_n_count(1, nb + '0');
}

void	ft_putnbr(long long nb)
{
	if (nb == 0 && f.dot == 1 && f.preci == 0)
		;
	else
		ft_putnbr_rec(nb);
}

int	get_len_d(int d)
{
	int i=0;
	if (d == -2147483648)
		return (11);
	else if (d < 0)
	{
		d = -d;
		i++;
	}
	while (d > 0)
	{
		d /= 10;
		i++;
	}
	if (i == 0)
		return (1);
	return (i);
}

void	print_d(int d)
{
	int len;
	len = get_len_d(d);
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
			write_n_count(f.width - f.preci, ' ');
			if (d < 0)
				write_n_count(1, '-');
			write_n_count(f.preci - len, '0');
			if (d < 0)
			{
				ft_putnbr(-d);
				return ;
			}
		}
		else
			write_n_count(f.width - len, ' ');
	}
	if (f.preci > f.width && f.preci > len)
	{
		if (d < 0)
			write_n_count(1, '-');
		write_n_count(f.preci - len, '0');
		if (d < 0)
		{
			ft_putnbr(-d);
			return ;
		}
	}
	ft_putnbr(d);
}

int	get_len_hex(unsigned int hex)
{
	int i=0;
	while (hex > 0)
	{
		hex /= 16;
		i++;
	}
	if (i == 0)
		return (1);
	return (i);
}

void	ft_putnbr_hex_rec(unsigned int hex)
{
	if (hex >= 16)
	{
		ft_putnbr_hex_rec(hex / 16);
		ft_putnbr_hex_rec(hex % 16);
	}
	else
	{
		if (hex < 10)
			write_n_count(1, hex + '0');
		else
			write_n_count(1, hex - 10 + 'a');
	}
}

void	ft_putnbr_hex(unsigned int hex)
{
	if (f.dot == 1 && f.preci == 0 && hex == 0)
		;
	else
		ft_putnbr_hex_rec(hex);
}

void	print_hex(unsigned int hex)
{
	int len = get_len_hex(hex);
	if (f.dot == 1 && f.preci == 0 && hex == 0)
		len = 0;
	if (f.width > f.preci && f.width > len)
	{
		if (f.preci > len)
		{
			write_n_count(f.width - f.preci, ' ');
			write_n_count(f.preci - len, '0');
		}
		else
			write_n_count(f.width - len, ' ');
	}
	if (f.preci > f.width && f.preci > len)
		write_n_count(f.preci - len, '0');
	ft_putnbr_hex(hex);
}

void	init_flag()
{
	f.dot = 0;
	f.len = 0;
	f.preci = 0;
	f.width = 0;
}

int	ft_printf(const char *s, ...)
{
	va_list ap;

	init_flag();
	if (s)
	{
		va_start(ap, s);
		int i = 0;
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
					print_hex(va_arg(ap, unsigned int));
					i++;
				}
			}
			else
				write_n_count(1, s[i]);
			i++;
		}
		va_end(ap);
	}
	return (f.len);
}
//main source from aggarcia42
int main(void)
{
	char *str = NULL;
	printf("\n\nTEST %%s\n\n");
	printf("\n___TEST %%s___\n");
	printf("No original - %d\n", ft_printf("|%s|\n", str));
	printf("Original - %d\n", printf("|%s|\n", str));

	printf("\n___TEST %%ss___\n");
	printf("No original - %d\n", ft_printf("|%ss|\n", str));
	printf("Original - %d\n", printf("|%ss|\n", str));

	printf("\n___TEST %%20s___\n");
	printf("No original - %d\n", ft_printf("|%20s|\n", str));
	printf("Original - %d\n", printf("|%20s|\n", str));

	printf("\n___TEST %%2s___\n");
	printf("No original - %d\n", ft_printf("|%2s|\n", str));
	printf("Original - %d\n", printf("|%2s|\n", str));

	printf("\n___TEST %%.2s___\n");
	printf("No original - %d\n", ft_printf("|%.2s|\n", str));
	printf("Original - %d\n", printf("|%.2s|\n", str));

	printf("\n___TEST %%.20s___\n");
	printf("No original - %d\n", ft_printf("|%.20s|\n", str));
	printf("Original - %d\n", printf("|%.20s|\n", str));

	printf("\n___TEST %%2.20s___\n");
	printf("No original - %d\n", ft_printf("|%2.20s|\n", str));
	printf("Original - %d\n", printf("|%2.20s|\n", str));

	printf("\n___TEST %%22.20s___\n");
	printf("No original - %d\n", ft_printf("|%22.20s|\n", str));
	printf("Original - %d\n", printf("|%22.20s|\n", str));

	printf("\n___TEST %%12.20s___\n");
	printf("No original - %d\n", ft_printf("|%12.20s|\n", str));
	printf("Original - %d\n", printf("|%12.20s|\n", str));

	printf("\n___TEST %%12.s___\n");
	printf("No original - %d\n", ft_printf("|%12.s|\n", str));
	printf("Original - %d\n", printf("|%12.s|\n", str));

	printf("\n___TEST %%.s___\n");
	printf("No original - %d\n", ft_printf("|%.s|\n", str));
	printf("Original - %d\n", printf("|%.s|\n", str));

	printf("\n___TEST %%20.s___\n");
	printf("No original - %d\n", ft_printf("|%20.s|\n", str));
	printf("Original - %d\n", printf("|%20.s|\n", str));

	printf("\n___TEST %%2.s___\n");
	printf("No original - %d\n", ft_printf("|%2.s|\n", str));
	printf("Original - %d\n", printf("|%2.s|\n", str));



	printf("\n\nTEST %%d\n\n");
	int num = 0;
	printf("\n___TEST %%d___\n");
	printf("No original - %d\n", ft_printf("|%d|\n", num));
	printf("Original - %d\n", printf("|%d|\n", num));

	printf("\n___TEST %%dd___\n");
	printf("No original - %d\n", ft_printf("|%dd|\n", num));
	printf("Original - %d\n", printf("|%dd|\n", num));

	printf("\n___TEST %%20d___\n");
	printf("No original - %d\n", ft_printf("|%20d|\n", num));
	printf("Original - %d\n", printf("|%20d|\n", num));

	printf("\n___TEST %%2d___\n");
	printf("No original - %d\n", ft_printf("|%2d|\n", num));
	printf("Original - %d\n", printf("|%2d|\n", num));

	printf("\n___TEST %%.2d___\n");
	printf("No original - %d\n", ft_printf("|%.2d|\n", num));
	printf("Original - %d\n", printf("|%.2d|\n", num));

	printf("\n___TEST %%.20d___\n");
	printf("No original - %d\n", ft_printf("|%.20d|\n", num));
	printf("Original - %d\n", printf("|%.20d|\n", num));

	printf("\n___TEST %%2.20s___\n");
	printf("No original - %d\n", ft_printf("|%2.20d|\n", num));
	printf("Original - %d\n", printf("|%2.20d|\n", num));

	printf("\n___TEST %%22.20d___\n");
	printf("No original - %d\n", ft_printf("|%22.20d|\n", num));
	printf("Original - %d\n", printf("|%22.20d|\n", num));

	printf("\n___TEST %%12.20d___\n");
	printf("No original - %d\n", ft_printf("|%12.20d|\n", num));
	printf("Original - %d\n", printf("|%12.20d|\n", num));

	printf("\n___TEST %%12.d___\n");
	printf("No original - %d\n", ft_printf("|%12.d|\n", num));
	printf("Original - %d\n", printf("|%12.d|\n", num));

	printf("\n___TEST %%.d___\n");
	printf("No original - %d\n", ft_printf("|%.d|\n", num));
	printf("Original - %d\n", printf("|%.d|\n", num));

	printf("\n___TEST %%20.d___\n");
	printf("No original - %d\n", ft_printf("|%20.d|\n", num));
	printf("Original - %d\n", printf("|%20.d|\n", num));

	printf("\n___TEST %%2.d___\n");
	printf("No original - %d\n", ft_printf("|%2.d|\n", num));
	printf("Original - %d\n", printf("|%2.d|\n", num));

	printf("\n\nTEST %%x\n\n");
	unsigned int un = 0;
	printf("\n___TEST %%x___\n");
	printf("No original - %d\n", ft_printf("|%x|\n", un));
	printf("Original - %d\n", printf("|%x|\n", un));

	printf("\n___TEST %%xx___\n");
	printf("No original - %d\n", ft_printf("|%xx|\n", un));
	printf("Original - %d\n", printf("|%xx|\n", un));

	printf("\n___TEST %%20x___\n");
	printf("No original - %d\n", ft_printf("|%20x|\n", un));
	printf("Original - %d\n", printf("|%20x|\n", un));

	printf("\n___TEST %%2x___\n");
	printf("No original - %d\n", ft_printf("|%2x|\n", un));
	printf("Original - %d\n", printf("|%2x|\n", un));

	printf("\n___TEST %%.2x___\n");
	printf("No original - %d\n", ft_printf("|%.2x|\n", un));
	printf("Original - %d\n", printf("|%.2x|\n", un));

	printf("\n___TEST %%.20x___\n");
	printf("No original - %d\n", ft_printf("|%.20x|\n", un));
	printf("Original - %d\n", printf("|%.20x|\n", un));

	printf("\n___TEST %%2.20x___\n");
	printf("No original - %d\n", ft_printf("|%2.20x|\n", un));
	printf("Original - %d\n", printf("|%2.20x|\n", un));

	printf("\n___TEST %%22.20x___\n");
	printf("No original - %d\n", ft_printf("|%22.20x|\n", un));
	printf("Original - %d\n", printf("|%22.20x|\n", un));

	printf("\n___TEST %%12.20x___\n");
	printf("No original - %d\n", ft_printf("|%12.20x|\n", un));
	printf("Original - %d\n", printf("|%12.20x|\n", un));

	printf("\n___TEST %%12.x___\n");
	printf("No original - %d\n", ft_printf("|%12.x|\n", un));
	printf("Original - %d\n", printf("|%12.x|\n", un));

	printf("\n___TEST %%.x___\n");
	printf("No original - %d\n", ft_printf("|%.x|\n", un));
	printf("Original - %d\n", printf("|%.x|\n", un));

	printf("\n___TEST %%20.x___\n");
	printf("No original - %d\n", ft_printf("|%20.x|\n", un));
	printf("Original - %d\n", printf("|%20.x|\n", un));

	printf("\n___TEST %%2.x___\n");
	printf("No original - %d\n", ft_printf("|%2.x|\n", un));
	printf("Original - %d\n", printf("|%2.x|\n", un));
    printf("\n");
    printf("No original - %d\n",ft_printf("%d and %s and %x\n", 42, "cuarenta", 42));
    printf("Original - %d\n",printf("%d and %s and %x\n", 42, "cuarenta", 42));

	printf("No original - %d\n", ft_printf("|%7.5x|\n", 100));
	printf("Original - %d\n", printf("|%7.5x|\n", 100));
	return (0);
}
