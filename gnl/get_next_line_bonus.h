/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 15:15:13 by sichoi            #+#    #+#             */
/*   Updated: 2021/06/24 22:01:52 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <stdlib.h>

int		get_next_line(int fd, char **line);
int		f_nl(char *s, int is_len);
char	*join(char *dst, const char *src, int size);
char	*bak_after_nl(char *bak);
int		ft_len(const char *s);
int		ft_strlcpy(char *dst, const char *src, int dstsize);
char	*ft_free(char *s);
void	init_buf(char *buf);
char	*ft_strdup(const char *s);

#endif
