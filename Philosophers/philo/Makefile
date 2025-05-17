# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcunha-l <rcunha-l@student.42.lu>          #+#  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025-05-05 19:43:36 by rcunha-l          #+#    #+#              #
#    Updated: 2025-05-17 19:30:32 by rcunha-l         ###   ########.lu        #
#                                                                              #
# **************************************************************************** #

#Variables

NAME		:= philo

SRC_DIR		:= src/
OBJ_DIR		:= obj/
CC			:= gcc
CFLAGS		:= -g -Wall -Werror -Wextra
#CFLAGS		:= -g -Werror
#FSANITIZE	:= -fsanitize=thread
FSANITIZE	:= 
NOFLAGS		:= -g
RM			:= rm -f

HEADER 			:= -I$(INC)
PTHREAD			= -pthread

# Colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

#Sources

SRC_FILES	=	main \
				utils \
				threading \
				threads_utils \
				parsing

SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
DEPS 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .d, $(SRC_FILES)))
INCS		= 	$(addprefix $(INCLUDE), $(addsuffix .h, $(INC_FILES)))
###

OBJF		=	.cache_exists

all:	
		@$(MAKE) $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INCS) | $(OBJF)
			@echo "🍩 $(YELLOW)Compiling: $< $(DEF_COLOR)"
			$(CC) $(CFLAGS) $(PTHREAD) -MMD -c $< -o $@	

-include 	${DEPS}
$(NAME):	$(OBJ) Makefile
			@$(CC) $(CFLAGS) $(PTHREAD) $(FSANITIZE) $(OBJ) $(PRINTF) -o $(NAME)		
			@echo "👉 $(BLUE)$(CC) $(CFLAGS) $(PTHREAD) $(FSANITIZE) $(OBJ) -o $(NAME)$(DEF_COLOR)"
			@echo "$(GREEN)✨ Philosophers Mandatory compiled!$(DEF_COLOR)"

bonus:		
			@$(MAKE) all
			
$(OBJF):
			@mkdir -p $(OBJ_DIR)
		

clean:
			$(RM) -rf $(OBJ_DIR)
			@echo "$(CYAN)Philosophers Mandatory object files cleaned!$(DEF_COLOR)"

fclean:		clean
			$(RM) -f $(NAME)
			@echo "$(CYAN)Philosophers Mandatory executable files cleaned!$(DEF_COLOR)"	

re:			fclean 
			@$(MAKE)	
			@echo "$(GREEN)Cleaned and rebuilt everything for Philosophers Mandatory!$(DEF_COLOR)"

norm:
			@norminette $(SRC) $(INCLUDE) | grep -v Norme -B1 || true

.PHONY:		all clean fclean re norm
