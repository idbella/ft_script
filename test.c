/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 16:53:17 by sid-bell          #+#    #+#             */
/*   Updated: 2019/11/10 17:11:50 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include "src/ft_script.h"
typedef struct s_char
{
    char    key;
    short   tmp1;
    char    tmp2;
}               t_char;

void	ft_setup(struct termios *copy)
{
	struct termios	term;

	tcgetattr(0, &term);
	tcgetattr(0, copy);
	term.c_lflag &= ~ECHO;
	term.c_lflag &= ISIG;
	term.c_lflag &= ~ICANON;
	tcsetattr(0,TCSANOW, &term);
}

int main()
{
    struct timeval tmp;
    struct timeval ref;
    char    c;
    struct termios copy;
    t_char key;

    ft_setup(&copy);
    gettimeofday(&ref, NULL);
    while (1)
    {
        read(1, &c, 1);
        if (c == '.')
            break;
        gettimeofday(&tmp, NULL);
        key.key = c;
        key.tmp1 =  tmp.tv_sec - ref.tv_sec;
        key.tmp2 = tmp.tv_usec/100000;
        printf("%c - %d - %d\n", key.key, key.tmp1, key.tmp2);
    }
    tcsetattr(0, TCSANOW, &copy);
}