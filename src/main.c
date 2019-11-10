/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 20:12:08 by sid-bell          #+#    #+#             */
/*   Updated: 2019/11/10 01:52:08 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_script.h"

void	ft_ptyfork(int slave)
{
	pid_t     pid;

	if (!(pid = fork()))
	{
		dup2(0, 10);
		setsid();
		if (ioctl(slave, TIOCSCTTY) < 0)
		{
			ft_printf_fd(10, "cannot grant pty master's permissions\n");
			_Exit(1);
		}
		dup2(slave, 0);
		dup2(slave, 1);
		dup2(slave, 2);
		char *arg[2] = {"sh", NULL};
		execve("/bin/bash", arg, NULL);
		ft_printf_fd(10, "error\n");
	}
}



int main()
{
	int             master;
	int             slave;

	if (!ft_openpty(&master, &slave))
		_Exit(1);
	ft_ptyfork(slave);
	char c;
	if (!fork())
	{
		while (read(0, &c, 1) > 0)
		{
			write(master, &c, 1);
		}
		ft_printf_fd(2, "failed \n");
		exit(0);
	}
	struct termios term;
	struct termios cpterm;
	ft_tcgetattr(0, &term);
	ft_tcgetattr(0, &cpterm);
	term.c_lflag &= ~ECHO;
	term.c_lflag &= ISIG;
	term.c_lflag &= ~ICANON;
	ft_tcsetattr(0, &term);
	int fd = open("typescript", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	while (read(master, &c, 1) > 0)
	{
		ft_printf_fd(1, "%c", c);
		write(fd, &c, 1);
	}
	ft_printf_fd(2, "failed \n");
	close(master);
	ft_tcsetattr(0, &cpterm);
	return (0);
}
