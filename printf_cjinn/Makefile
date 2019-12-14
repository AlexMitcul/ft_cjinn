# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alisher <alisher@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/27 11:46:18 by cjinn             #+#    #+#              #
#    Updated: 2019/12/14 05:31:53 by alisher          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ./srcs/*.c ./libft/*.c

LFT = ./libft/*.a

OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror
HEADERS = includes/

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -c -I $(HEADERS) -I ./libft $(SRC)
	ar rc $(NAME) *.o
	ranlib $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)
	rm -f $(LFT)

re: fclean all
