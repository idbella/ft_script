/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_termios.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 13:49:14 by sid-bell          #+#    #+#             */
/*   Updated: 2019/11/10 17:37:39 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_script.h"

void	ft_setup(struct termios *copy)
{
	struct termios	term;

	ft_tcgetattr(0, &term);
	ft_tcgetattr(0, copy);
	term.c_lflag &= ~ECHO;
	term.c_lflag &= ISIG;
	term.c_lflag &= ~ICANON;
	ft_tcsetattr(0, &term);
}

void	ft_unsetup(struct termios *copy)
{
	ft_tcsetattr(0, copy);
}
