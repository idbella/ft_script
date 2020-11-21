/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_script.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 23:07:26 by sid-bell          #+#    #+#             */
/*   Updated: 2019/11/11 10:06:56 by sid-bell         ###   ########.fr       */
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
#include <sys/time.h>
# define OUT "typescript"
# define FLAGS "adFpqrk"

typedef struct termios	t_term;

typedef struct	s_char
{
	int				key;
	int				tmp1;
	int				tmp2;
}				t_char;

typedef struct	s_params
{
	char	flags[127];
	t_term	term;
	char	*command;
	char	*logfile;
	char	**env;
	char	**argv;
}				t_params;

char			*ft_ptsname(int master, char *name);
int				ft_openpty(int *master, int *slave);
char			ft_grantpt(int master);
int				ft_unlockpt(int master);
int				ft_tcgetattr(int fd, struct termios *term);
int				ft_tcsetattr(int fd, struct termios *term);
void			ft_ptyfork(int slave, char *shell);
char			*ft_getloginshell(char **env);
void			ft_setup(struct termios *copy);
void			ft_unsetup(struct termios *copy);
int				ft_openfile(char *file);
char			ft_exist(char *file);
void			ft_getflags(char **argv);
t_params		*ft_getter(t_params *p);
void			ft_recorder(int fd, int logfile);
#endif
