/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grantpt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 23:05:21 by sid-bell          #+#    #+#             */
/*   Updated: 2019/11/10 00:32:12 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_script.h"

char	ft_grantpt(int master)
{
	if (ioctl(master, TIOCPTYGRANT) < 0)
	{
		 ft_printf_fd(2, "cannot grant pty master's permissions\n");
		 return (0);
	}
	return (1);
}
