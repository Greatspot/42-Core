# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcunha-l <rcunha-l@student.42luxembourg    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/23 17:52:44 by rcunha-l          #+#    #+#              #
#    Updated: 2025/01/23 17:52:44 by rcunha-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
CC			= gcc
FLAGS		= -Wall -Wextra -Werror
OBJ			= $(SRC:.c=.o)
SRC			= 	ft_calloc.c \
				ft_itoa.c \
				ft_memset.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_putstr_fd.c \
				ft_strcmp.c \
				ft_strjoin.c \
				ft_strlen.c \
				ft_strncmp.c \
				ft_putchar_fd.c \
				ft_strlcpy.c \
				ft_strlcat.c

all:		$(NAME)

$(NAME):	$(OBJ)
			ar rcs $@ $^

%.o:		%.c
			$(CC) $(FLAGS) -o $@ -c $<

clean:
			rm -rf $(OBJ)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
