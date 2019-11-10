# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sid-bell <sid-bell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/09 22:46:45 by sid-bell          #+#    #+#              #
#    Updated: 2019/11/10 00:36:59 by sid-bell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=ft_script

OBJ=src/main.o\
src/wrappers/grantpt.o\
src/wrappers/openpty.o\
src/wrappers/ptsname.o\
src/wrappers/tcgetattr.o\
src/wrappers/tcsetattr.o\
src/wrappers/unlockpt.o

CFLAGS= -Isrc/ -Wall -Wextra -Werror
all: libft $(NAME)

$(NAME):$(OBJ)
	gcc $(OBJ) -o $(NAME) src/libft/libft.a

libft:
	make -C src/libft
clean:
	rm -rf $(OBJ)