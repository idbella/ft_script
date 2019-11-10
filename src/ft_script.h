/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_script.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 23:07:26 by sid-bell          #+#    #+#             */
/*   Updated: 2019/11/10 01:50:49 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SCRIPT_H
# define FT_SCRIPT_H
# include "libft/libft.h"
# include <fcntl.h>
# include <termios.h>
# include <sys/stat.h>
# include <sys/ioctl.h>
# include <sys/syscall.h>

char	*ft_ptsname(int master, char *name);
int		ft_openpty(int *master, int *slave);
char	ft_grantpt(int master);
int		ft_unlockpt(int master);
int		ft_tcgetattr(int fd, struct termios *term);
int		ft_tcsetattr(int fd, struct termios *term);

#endif
