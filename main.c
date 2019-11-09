/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 20:12:08 by sid-bell          #+#    #+#             */
/*   Updated: 2019/11/09 18:05:26 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <fcntl.h>
#include <util.h>
#include <termios.h>
#include <sys/stat.h>
#include <sys/ioctl.h>

int main()
{
	int             master;
	int             slave;
	char            name[128];
	pid_t           pid;
	char            *line;

	
	if ((master = open("/dev/ptmx", O_RDWR)) < 0)
	{
		ft_printf_fd(2, "cannot create a new pty master\n");
		return (1);
	}
	
	if (ioctl(master, TIOCPTYGNAME, name) < 0)
	{
		ft_printf_fd(2, "cannot get pty slave's name\n");
		return (1);
	}
   
	if (ioctl(master, TIOCPTYGRANT) < 0)
	{
		 ft_printf_fd(2, "cannot grant pty master's permissions\n");
		 return (1);
	}

	if (ioctl(master, TIOCPTYUNLK) < 0)
	{
		 ft_printf_fd(2, "cannot grant pty master's permissions\n");
		 return (1);
	}
	if (!(pid = fork()))
	{
		dup2(0, 10);
		setsid();
		if ((slave = open(name, O_RDWR)) < 0)
			exit(0);
		if (ioctl(slave, TIOCSCTTY) < 0)
		{
			ft_printf_fd(10, "cannot grant pty master's permissions\n");
			return (1);
		}
		dup2(slave, 0);
		dup2(slave, 1);
		dup2(slave, 2);
		char *arg[2] = {"sh", NULL};
		execv("/bin/bash", arg);
		dprintf(10, "error\n");
	}
	char c;
	if (!fork())
	{
		while (read(0, &c, 1) > 0)
		{
			write(master, &c, 1);
		}
		printf("failed \n");
	}
	struct termios term;
	tcgetattr(0, &term);
	term.c_lflag &= ~ECHO;
	term.c_lflag &= ISIG;
	term.c_lflag &= ~ICANON;
	tcsetattr(0, TCSANOW, &term);
	int fd = open("scr", O_WRONLY | O_CREAT | O_TRUNC, 644);
	while (read(master, &c, 1) > 0)
	{
		ft_printf_fd(1, "%c", c);
		write(fd, &c, 1);
	}
	printf("failed \n");
	close(master);
	term.c_lflag &= ECHO;
	tcsetattr(0, TCSANOW, &term);
	return (0);
}
