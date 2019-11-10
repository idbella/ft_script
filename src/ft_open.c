/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 13:51:19 by sid-bell          #+#    #+#             */
/*   Updated: 2019/11/10 16:31:53 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_script.h"

char	ft_exist(char *file)
{
	if (access(file, F_OK))
	{
		ft_printf_fd(2, "script: %s: No such file or directory\n", file);
		return (0);
	}
	if (access(file, X_OK))
	{
		ft_printf_fd(2, "script: %s: Permission denied\n", file);
		return (0);
	}
	return (1);
}

int		ft_openfile(char *file)
{
	int			fd;
	int			mode;
	t_params	*params;

	params = ft_getter(0);
	mode = O_WRONLY | O_CREAT | O_TRUNC;
	if (params->flags[(int)'a'])
		mode = O_WRONLY | O_CREAT | O_APPEND;
	if ((fd = open(file, mode, 0644)) < 0)
	{
		ft_printf_fd(2, "script: %s: Permission denied\n", file);
		_Exit(1);
	}
	return (fd);
}
