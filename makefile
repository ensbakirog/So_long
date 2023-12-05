# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebakirog <ebakirog@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/29 06:07:15 by ebakirog          #+#    #+#              #
#    Updated: 2023/10/29 06:07:17 by ebakirog         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := so_long

CC := gcc

CFLAGS := -Wall -Wextra -Werror -Iheaders/

SOURCE := so_long.c read_map.c check_control.c draw_img.c key_handle.c
GETNEXTLINE := libraries/get_next_line/*c
LIBFT := libraries/libft/ft_*.c
FTPRINTF := libraries/ft_printf/*c
LIBRARY := -Lminilibx -lmlx -framework OpenGL -framework AppKit
MINILIBX := minilibx/

all:
	make -C $(MINILIBX)
	$(CC) $(CFLAGS) $(SOURCE) $(FTPRINTF) $(LIBFT) $(GETNEXTLINE) $(LIBRARY) -o $(NAME)

clean:
	@rm -f  *.o

fclean: clean
		make clean -C $(MINILIBX)
		rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re