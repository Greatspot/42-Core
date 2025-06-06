# BASIC
CC = cc -g
CFLAGS = -Wall -Wextra -Werror -g3
RM = rm -rf
GDB = gdb
VAL = valgrind --leak-check=full --track-origin=yes

#colors
RESET			:= \033[0m
GREEN			=	\e[32m
CYAN			:= \33[1;36m
YELLOW			=	\e[033m
BLUE			=	\e[34m
WHITE			=	\e[00m
RED				:= \033[1;31m
BOLD			:= \033[1;1m

# PUSH_SWAP
NAME = push_swap.a
SRCS =  ./algorithm/sort_small.c \
        ./algorithm/sort_simple.c \
        ./algorithm/sort_radix.c \
        ./functions/ft_atoi.c \
        ./functions/ft_isdigit.c \
        ./functions/ft_lstadd_back.c \
        ./functions/ft_lstadd_front.c \
        ./functions/ft_lstlast.c \
        ./functions/ft_lstnew.c \
        ./functions/ft_lstsize.c \
        ./functions/ft_memcpy.c \
        ./functions/ft_split.c \
        ./functions/ft_strchr.c \
        ./functions/ft_strdup.c \
        ./functions/ft_substr.c \
        ./operations/push.c \
        ./operations/reverse.c \
        ./operations/rotate.c \
        ./operations/swap.c \
        ./utilities/error.c \
        ./utilities/utilities.c \
        ./utilities/validation.c \
        ./push_swap.c

OBJSDIR = objects
OBJS = $(addprefix $(OBJSDIR)/,$(SRCS:.c=.o))

# MAKE RULES
all: $(NAME) push_swap

$(NAME): $(OBJS)
	@echo "$(GREEN)$(BOLD)Creating objects directory...$(RESET)"
	ar -rcs $(NAME) $(OBJS)
	@echo "$(GREEN)$(BOLD)Objects created!$(RESET)"
	
$(OBJSDIR)/%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

push_swap: $(OBJS) $(NAME)
	@echo "$(GREEN)$(BOLD)Creating executable...$(RESET)"
	$(CC) $(CFLAGS) $(OBJS) -o push_swap
	@echo "$(GREEN)$(BOLD)Executable created!$(RESET)"

clean:
	@echo "$(YELLOW)$(BOLD)Removing objects...$(RESET)"
	$(RM) $(OBJSDIR)
	@echo "$(YELLOW)$(BOLD)Objects removed!$(RESET)"

fclean: clean
	@echo "$(RED)$(BOLD)Removing executable...$(RESET)"
	$(RM) push_swap push_swap.a
	@echo "$(RED)$(BOLD)Executable removed!$(RESET)"

re: fclean all
	@echo "$(GREEN)$(BOLD)Recompiled successfully!$(RESET)"

.SILENT:
