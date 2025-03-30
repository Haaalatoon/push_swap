# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hrhilane <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/29 00:31:00 by hrhilane          #+#    #+#              #
#    Updated: 2025/03/29 00:31:40 by hrhilane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project Name
NAME		= push_swap

# Directories
INC_DIR		= inc/
SRC_DIR		= src/
OBJ_DIR		= obj/

# Compiler Settings
CC		= cc
CFLAGS		= -Wall -Werror -Wextra -I$(INC_DIR)
RM		= rm -rf

# Source Files
ARGS_MANIPULATION		= args_manipulation/args_manipulation.c \
		  args_manipulation/libft_functions.c

INITIALIZATION	= initialization/init_a_to_b.c \
		  initialization/init_b_to_a.c

OPERATIONS	= operations/push_ops.c \
		  operations/rev_rotate_ops.c \
		  operations/rotate_ops.c \
		  operations/swap_ops.c

PARSING		= parsing/ft_split.c \
		  parsing/input_validation.c

SORTING		= sorting/sort_stacks.c \
		  sorting/sort_three.c

STACK		= stack/stack_operations.c \
		  stack/stack_utils.c

MAIN		= push_swap.c

# Combine all sources
SRCS		= $(addprefix $(SRC_DIR), $(HELPERS) $(INITIALIZATION) \
		  $(OPERATIONS) $(PARSING) $(SORTING) $(STACK) $(ARGS_MANIPULATION)) \
		  $(MAIN)
OBJS	=	$(SRCS:%.c=$(OBJ_DIR)%.o)

# Colors
GREEN	= \033[0;32m
RED		= \033[0;31m
NC		= \033[0m

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)✅ Push_swap compiled successfully!$(NC)"

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ_DIR)
	@echo "$(RED)🧹 Object files removed$(NC)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)🧼 Full cleanup complete$(NC)"

re: fclean all
	@echo "$(GREEN)♻️  Project rebuilt$(NC)"

.PHONY: all clean fclean re
