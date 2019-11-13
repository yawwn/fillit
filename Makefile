# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgalazza <hgalazza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/05 14:49:32 by hgalazza          #+#    #+#              #
#    Updated: 2019/11/12 16:15:02 by hgalazza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIB_SRCS = ./libft/libft.a
OBJS = *.o
SRCS = main.c ft_check.c def_of_piece.c free_node.c min_size_field.c name_to_coord.c \
		prep_pieces.c save_piece.c check_collision.c field_generation.c shifters.c \
		piece_manipulation.c
LIB = make -C ./libft/

all: $(NAME)

$(NAME):
			@$(LIB)
			@$(CC) $(CFLAGS) -c $(SRCS)
			@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIB_SRCS)

clean:
			@rm -rf $(OBJS)
			@make -C ./libft/ clean

fclean: clean
			@rm -rf $(NAME)
			@make -C ./libft/ fclean

re: fclean all