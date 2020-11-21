/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_record.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 20:40:11 by sid-bell          #+#    #+#             */
/*   Updated: 2019/11/11 09:21:13 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_script.h"

void	ft_print(char *str, int fd)
{
	ft_printf_fd(fd, "#%d\n", str[0]);
	ft_printf_fd(fd, "#%d\n", str[1]);
	ft_printf_fd(fd, "#%d\n", str[2]);
	ft_printf_fd(fd, "#%d\n", str[3]);
	t_char	*ch;

	ch = (t_char *)str;
	ft_printf_fd(fd, "--------\n*%c\n", ch->key);
	ft_printf_fd(fd, "*%d\n", ch->tmp1);
	ft_printf_fd(fd, "*%d\n", ch->tmp2);
}

void	ft_recorder(int master, int logfile)
{
	struct timeval	tmp;
	struct timeval	ref;
	t_char			key;
	char			c;
	int				fd;

	fd = open("rec", O_WRONLY|O_CREAT, 0777);
	gettimeofday(&ref, NULL);
	while (1)
	{
		if (read(1, &c, 1) <= 0)
			break ;
		gettimeofday(&tmp, NULL);
		key.key = c;
		key.tmp1 = tmp.tv_sec - ref.tv_sec;
		key.tmp2 = tmp.tv_usec / 10000;
		write(master, &c, 1);
		write(logfile, (char *)&key, 4);
		ft_print((char *)&key, fd);
	}
}
