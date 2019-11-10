# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sid-bell <sid-bell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/09 22:46:45 by sid-bell          #+#    #+#              #
#    Updated: 2019/11/10 15:02:17 by sid-bell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=ft_script

OBJ=src/main.o\
src/wrappers/grantpt.o\
src/wrappers/openpty.o\
src/wrappers/ptsname.o\
src/wrappers/tcgetattr.o\
src/wrappers/tcsetattr.o\
src/wrappers/unlockpt.o\
src/ft_ptyfork.o\
src/ft_loginshell.o\
src/ft_open.o\
src/ft_termios.o\
src/ft_getflags.o

CFLAGS= -g -Isrc/ -Wall -Wextra -Werror
all: libft $(NAME)

$(NAME):$(OBJ)
	gcc -g $(OBJ) $(CFLAGS) -o $(NAME) src/libft/libft.a

libft:
	make -C src/libft
clean:
	make -C src/libft clean
	rm -rf $(OBJ)
fclean: clean
	make -C src/libft/ fclean
	rm -rf $(NAME)