/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 20:12:08 by sid-bell          #+#    #+#             */
/*   Updated: 2019/11/10 17:41:55 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_script.h"

t_params	*ft_getter(t_params *p)
{
	static t_params *params;

	if (p)
		params = p;
	return (params);
}

void		ft_copy_stdin_to_master(int master, int logfile)
{
	char c;

	if (!fork())
	{
		while (read(0, &c, 1) > 0)
		{
			if (ft_getter(0)->flags[(int)'r'] || ft_getter(0)->flags[(int)'k'])
				write(logfile, &c, 1);
			write(master, &c, 1);
		}
		_Exit(0);
	}
}

void		ft_log(t_params *params, int logfile, int master)
{
	char c;

	while (read(master, &c, 1) > 0)
	{
		ft_printf_fd(1, "%c", c);
		write(logfile, &c, 1);
	}
	if (!params->flags[(int)'q'])
	{
		ft_printf_fd(logfile,
			"\nScript done, output file is %s\n", params->logfile);
		ft_printf_fd(1,
			"\nScript done, output file is %s\n", params->logfile);
	}
	close(master);
}

void		ft_init(t_params *params, char **argv, char **env)
{
	char	*args[2];

	ft_bzero(params->flags, 127);
	params->env = env;
	params->logfile = NULL;
	params->command = NULL;
	ft_getflags(argv + 1);
	if (!params->logfile)
		params->logfile = "typescript";
	if (!params->command)
		params->command = ft_getloginshell(env);
	if (!params->argv)
	{
		args[0] = params->command;
		args[1] = NULL;
	}
}

int			main(int argc, char **argv, char **env)
{
	t_params		params;
	int				master;
	int				slave;
	int				logfile;

	ft_getter(&params);
	ft_init(&params, argv, env);
	argc = 0;
	logfile = ft_openfile(params.logfile);
	if (!ft_openpty(&master, &slave))
		_Exit(1);
	if (ft_exist(params.command))
	{
		ft_ptyfork(slave, params.command);
		ft_setup(&params.term);
		ft_copy_stdin_to_master(master, logfile);
		ft_log(&params, logfile, master);
		ft_unsetup(&params.term);
	}
	return (0);
}
