/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getflags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 14:22:31 by sid-bell          #+#    #+#             */
/*   Updated: 2019/11/10 16:22:06 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_script.h"

void	ft_fillflags(t_params *params, char **argv, int index)
{
	int i;
	int	flag;

	i = 1;
	while (argv[index][i])
	{
		flag = argv[index][i];
		if (ft_strchr(FLAGS, flag))
			params->flags[flag] = 1;
		else
		{
			ft_printf_fd(2, "script: illegal option -- %c\n", flag);
			ft_printf_fd(2,
			"usage: script [-adpqr] [file [command ...]]\n");
			_Exit(1);
		}
		i++;
	}
}

void	ft_getflags(char **argv)
{
	t_params	*params;
	int			index;
	char		stop;

	stop = 0;
	params = ft_getter(0);
	index = 0;
	while (argv[index])
	{
		if (ft_strequ(argv[index], "--"))
			stop = 1;
		else if (!stop && argv[index][0] == '-')
			ft_fillflags(params, argv, index);
		else if (!params->logfile)
			params->logfile = argv[index];
		else if (!params->command)
		{
			params->command = argv[index];
			params->argv = argv + index;
			return ;
		}
		index++;
	}
}
