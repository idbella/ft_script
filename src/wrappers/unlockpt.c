/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unlockpt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 00:20:03 by sid-bell          #+#    #+#             */
/*   Updated: 2019/11/10 00:40:32 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_script.h"

int		ft_unlockpt(int master)
{
	if (ioctl(master, TIOCPTYUNLK) < 0)
	{
		ft_printf_fd(2, "cannot unlock ptys\n");
		return (0);
	}
	return (1);
}
