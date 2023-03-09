##########################################################
#					FLAGS								#
##########################################################

NAME		:= minishell
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -Iincludes
LDLIBS		:= -lreadline
DEBUG		:= -g
LIBFT		:= includes/libft

##########################################################
#					PROGRAM`S SRCS						 #
##########################################################

SRCS		:= srcs/start.c \
			   srcs/lexer/lexer.c \
			   srcs/lexer/types.c

OBJS		:= $(SRCS:.c=.o)

#########################################################
#						COLORS							#
#########################################################

CLR_RMV	:= \033[0m
RED		:= \033[1;31m
GREEN	:= \033[1;32m
YELLOW	:= \033[1;33m
BLUE    := \033[1;34m
CYAN	:= \033[1;36m

########################################################
#						FUNCTIONS					   #
########################################################

all: $(NAME)

$(NAME): $(OBJS)
		@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
		@$(MAKE) -s -C $(LIBFT) all
		@ cp ./includes/libft/libft.a .
		@ cc -o $@ $^ libft.a $(LDLIBS)
		@ echo "$(GREEN)$(NAME) created ✔️"

clean:
	@ rm -rf $(OBJS) libft.a
	@ echo "$(RED)Cleaning up$(CLR_RMV)..."

fclean: clean
	@ rm -rf ${NAME}
	@ echo "$(CYAN)Removing libft$(CLR_RMV)..."
	@$(MAKE) -s -C $(LIBFT) fclean
	@ echo "$(RED)OBJS AND LIBFT REMOVED ✔️"

re: fclean all

.PHONY: all clean fclean re

