#include "get_next_line.h"

typedef struct s_bak
{
	char			*content;
	struct s_bak	*next;
}	t_bak;

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char 	*dst;
	int		i;

	dst = malloc(ft_strlen(src) + 1);
	if (dst == 0)
		return (0);
	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}

int	ft_strchr(char *s, char c)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	bak_strchr(t_bak *bak, char c)
{
	while (bak)
	{
		if (ft_strchr(bak->content, c))
			return (1);
		bak = bak->next;
	}
	return (0);
}

t_bak	*bak_add(t_bak **bak, char *content)
{
	t_bak	*new;
	t_bak	*p;

	if (!content)
		return (0);
	new = malloc(sizeof(t_bak));
	if (new == 0)
		return (0);
	new->content = content;
	new->next = NULL;
	if (*bak == 0)
		*bak = new;
	else
	{
		p = *bak;
		while (p->next)
			p = p->next;
		p->next = new;
	}
	return (new);
}

int read_stdin(t_bak **bak)
{
	char	buf[128];
	int		n;

	while ((n = read(0, buf, 127)) > 0)
	{
		buf[n] = 0;
		if (bak_add(bak, ft_strdup(buf)) == 0)
			return (-1);
		if (ft_strchr(buf, '\n') == 1)
			break ;
	}
	return (n);
}

int bak_clear(t_bak **bak)
{
	t_bak	*next;

	while (*bak)
	{
		next = (*bak)->next;
		free((*bak)->content);
		free(*bak);
		*bak = next;
	}
	return (-1);
}

int	bak_len(t_bak *bak)
{
	int	total;
	int	i;

	total = 0;
	while (bak)
	{
		i = 0;
		while (bak->content[i] && bak->content[i] != '\n')
			i++;
		total += i;
		if (bak->content[i] == '\n')
			break ;
		bak = bak->next;
	}
	return (total);
}

int line_write(char **line, t_bak **bak)
{
	char	*tmp;
	t_bak	*p;
	int		len;
	int		i, j;

	len = bak_len(*bak);
	tmp = malloc(len + 1);
	if (tmp == 0)
		return (0);
	tmp[len] = 0;
	j = 0;
	while (*bak)
	{
		i = 0;
		while ((*bak)->content[i] && (*bak)->content[i] != '\n')
			tmp[j++] = (*bak)->content[i++];
		tmp[j] = 0;
		if ((*bak)->content[i++] == '\n')
		{
			j = 0;
			while ((*bak)->content[i])
				(*bak)->content[j++] = (*bak)->content[i++];
			(*bak)->content[j] = 0;
			break ;
		}
		else
		{
			p = (*bak)->next;
			free((*bak)->content);
			free(*bak);
			*bak = p;
		}
	}
	*line = tmp;
	return (1);
}

int get_next_line(char **line)
{
	static t_bak	*bak;

	if (bak == 0 || bak_strchr(bak, '\n') == 0)
		if (read_stdin(&bak) < 0)
			return (bak_clear(&bak));
	if (line_write(line, &bak) == 0)
		return (bak_clear(&bak));
	if (bak)
		return (1);
	else
		return (0);
}
