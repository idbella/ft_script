/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 21:41:22 by sid-bell          #+#    #+#             */
/*   Updated: 2019/02/02 14:44:39 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nbrlen(long int n)
{
	int lenght;

	lenght = n <= 0 ? 1 : 0;
	while (n)
	{
		lenght++;
		n /= 10;
	}
	return (lenght);
}
