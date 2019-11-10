/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptyfork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 09:36:47 by sid-bell          #+#    #+#             */
/*   Updated: 2019/11/10 17:45:37 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_script.h"
#include <unistd.h>
#include <errno.h>

void	ft_ptyfork(int slave, char *command)
{
	pid_t			pid;
	t_params		*params;
	struct winsize	win;

	params = ft_getter(0);
	if (!(pid = fork()))
	{
		ioctl(0, TIOCGWINSZ, &win);
		setsid();
		if (ioctl(slave, TIOCSCTTY) < 0)
		{
			ft_printf_fd(2, "cannot set slave as a controlling terminal\n");
			_Exit(1);
		}
		ioctl(slave, TIOCSWINSZ, &win);
		dup2(slave, 0);
		dup2(slave, 1);
		dup2(slave, 2);
		if (!params->flags[(int)'q'])
			ft_printf_fd(1, "Script started, output file is %s\n",
			params->logfile);
		execve(command, params->argv, params->env);
		ft_printf_fd(10, "error %s\n", command);
		_Exit(0);
	}
}
