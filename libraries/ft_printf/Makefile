# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebakirog <ebakirog@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/27 22:16:47 by ebakirog          #+#    #+#              #
#    Updated: 2023/07/27 22:16:49 by ebakirog         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a
SRC			=	ft_printf.c ft_printf_utils.c
OBJ			=	$(SRC:.c=.o)
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra
RM			=	rm -rf
AR			=	ar rcs

all:$(NAME)

$(NAME):$(OBJ)
	$(AR) $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
