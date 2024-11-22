# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lloginov <lloginov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/08 11:55:01 by lloginov          #+#    #+#              #
#    Updated: 2024/11/22 14:16:32 by lloginov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = philo
CC = gcc
CFLAGS = -Wall -Wextra -Werror  #-fsanitize=address -g3 

SRC =   main.c\
		philo.c\
		philo_utils.c\
		algo.c\
		

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
