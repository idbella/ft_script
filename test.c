/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 16:53:17 by sid-bell          #+#    #+#             */
/*   Updated: 2019/11/12 23:48:42 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include "src/ft_script.h"
#include <sys/mman.h>

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

void    ft_read(int fd)
{
    char    *ptr;
    t_char *c;
    char *line;
    struct stat st;
    int     i;
    int tmp;

    fstat(fd, &st);
    ft_putstr("start reading..\n");
    ptr = mmap(0, st.st_size, PROT_READ, MAP_SHARED, fd, 0);
    while (i < st.st_size / 4)
    {
        c = (t_char *)ptr;
        //ft_printf_fd(1, "\nsleeping for |%d| nad |%d|\n", c->tmp1, c->tmp2);
        if (c->tmp1 >= 0 || c->tmp2 >= 0)
        {
            tmp = c->tmp1 * 1000000 + c->tmp2;
            if (tmp > 100)
                usleep(tmp);
        }
        write(1, &c->key, 4);
        ptr += sizeof(t_char);
        i++;
    }
    ft_putstr("end reding..\n");
}

int main(int argc, char **argv)
{
    struct timeval tmp;
    struct timeval ref;
    int     c;
    struct termios copy;
    t_char key;
	int				fd;
    int             len;

	
    if (argc > 1)
    {fd = open("rec", O_RDWR|O_CREAT, 0777);
        ft_read(fd);
     exit(0);
    }
    fd = open("rec", O_RDWR|O_CREAT|O_TRUNC, 0777);
    ft_setup(&copy);
    gettimeofday(&ref, NULL);
    while (1)
    {
        len = read(1, &c, 4);
        if (c == '.')
            break;
        gettimeofday(&tmp, NULL);
        key.key = c;
        key.tmp1 =  tmp.tv_sec - ref.tv_sec;
        if (tmp.tv_sec == ref.tv_sec)
            key.tmp2 = tmp.tv_usec - ref.tv_usec;
        else
            key.tmp2 = tmp.tv_usec;
        write(fd, (char *)&key, sizeof(t_char));
        write(1, &c, len);
        ref.tv_sec = tmp.tv_sec;
        ref.tv_usec = tmp.tv_usec;
        c = 0;
    }
    tcsetattr(0, TCSANOW, &copy);
}
