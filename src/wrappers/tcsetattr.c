/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcsetattr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 01:32:33 by sid-bell          #+#    #+#             */
/*   Updated: 2019/11/10 09:56:54 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_script.h"

int	ft_tcsetattr(int fd, struct termios *term)
{
	if (ioctl(fd, TIOCSETA, term) < 0)
	{
		ft_printf_fd(2, "cant set termios attributes\n");
		return (0);
	}
	return (1);
}
