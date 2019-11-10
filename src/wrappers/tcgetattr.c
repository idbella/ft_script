/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcgetattr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 01:14:09 by sid-bell          #+#    #+#             */
/*   Updated: 2019/11/10 01:32:05 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_script.h"

int	ft_tcgetattr(int fd, struct termios *term)
{
	if (ioctl(fd, TIOCGETA, term) < 0)
	{
		ft_printf_fd(2, "cant get termios attributes\n");
		return (0);
	}
	return (1);
}
