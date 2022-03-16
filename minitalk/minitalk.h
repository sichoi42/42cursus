/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 19:39:23 by sichoi            #+#    #+#             */
/*   Updated: 2021/08/16 17:25:14 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

/*server.c*/
void	conv_and_print(int *s, siginfo_t *info);
void	handler(int signo, siginfo_t *info, void *none);
/*client.c*/
void	send_msg(int pid, int bi);
void	binary_sending(int pid, int n);
void	send_control(int pid, char *s);
void	client_handler(int signo, siginfo_t *info, void *none);
/*utils.c*/
int		ft_strlen(const char *s);
void	ft_putstr(const char *s);
int		ft_atoi(const char *str);
/*ft_itoa.c*/
int		len_n(int n);
char	*tr_str(int n, char *s, int len);
char	*ft_strdup(char *src);
char	*ft_itoa(int n);

#endif
