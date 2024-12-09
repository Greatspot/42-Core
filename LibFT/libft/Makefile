# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcunha-l <rcunha-l@student.42luxembourg    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/22 20:43:09 by rcunha-l          #+#    #+#              #
#    Updated: 2024/11/01 18:58:51 by rcunha-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Function Files

STR_FUNCS = ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c \
            ft_strncmp.c ft_strnstr.c ft_strdup.c ft_substr.c ft_strjoin.c \
            ft_strtrim.c ft_split.c ft_strmapi.c ft_striteri.c

MEM_FUNCS = ft_bzero.c ft_memcpy.c ft_memset.c ft_memmove.c ft_memchr.c \
            ft_memcmp.c ft_calloc.c

CHAR_FUNCS = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
             ft_toupper.c ft_tolower.c

UTIL_FUNCS = ft_atoi.c ft_itoa.c

FD_FUNCS = ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

SRC_FILES = $(STR_FUNCS) $(MEM_FUNCS) $(CHAR_FUNCS) $(UTIL_FUNCS) $(FD_FUNCS)
OBJ_FILES = $(SRC_FILES:.c=.o)

# Bonus Files

BONUS_FUNCS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
              ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
              ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

BONUS_OBJS = $(BONUS_FUNCS:.c=.o)

# Compilation Variables

INCLUDES = ./
TARGET_LIB = libft.a
ARCHIVER = ar rc
COMPILER = cc
COMP_FLAGS = -Wall -Werror -Wextra -g
DEL = rm -f

# Colors
COLOR = \033[38;2;255;105;180m
RESET_COLOR = \033[0m

# Compilation Rules

.c.o:
	@echo "$(COLOR)Compiling $<...$(RESET_COLOR)"
	$(COMPILER) $(COMP_FLAGS) -c $< -o $@ -I $(INCLUDES)

$(TARGET_LIB): $(OBJ_FILES)
	@echo "$(COLOR)Creating library $(TARGET_LIB)...$(RESET_COLOR)"
	$(ARCHIVER) $(TARGET_LIB) $(OBJ_FILES)

# Main Targets

all: $(TARGET_LIB)

bonus: $(OBJ_FILES) $(BONUS_OBJS)
	@echo "$(COLOR)Adding bonus files to $(TARGET_LIB)...$(RESET_COLOR)"
	$(ARCHIVER) $(TARGET_LIB) $(OBJ_FILES) $(BONUS_OBJS)

so:
	@echo "$(COLOR)Creating shared library libft.so...$(RESET_COLOR)"
	$(COMPILER) -nostartfiles -fPIC $(COMP_FLAGS) $(SRC_FILES)
	$(COMPILER) -nostartfiles -shared -o libft.so $(OBJ_FILES) $(BONUS_OBJS)

# Cleaning

clean:
	@echo "$(COLOR)Cleaning object files...$(RESET_COLOR)"
	$(DEL) $(OBJ_FILES) $(BONUS_OBJS)

fclean: clean
	@echo "$(COLOR)Removing $(TARGET_LIB) and libft.so...$(RESET_COLOR)"
	$(DEL) $(TARGET_LIB)
	$(DEL) libft.so

re: fclean all

# Phony Targets

.PHONY: all bonus so clean fclean re