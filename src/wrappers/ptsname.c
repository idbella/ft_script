/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptsname.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 23:05:29 by sid-bell          #+#    #+#             */
/*   Updated: 2019/11/10 00:42:17 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_script.h"

char    *ft_ptsname(int master, char *name)
{
	if (ioctl(master, TIOCPTYGNAME, name) < 0)
	{
		ft_printf_fd(2, "cannot get pty slave's name\n");
		return (NULL);
	}
	ft_printf_fd(1, "name = %s\n", name);
	return (name);
}
