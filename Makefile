# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/22 15:16:09 by cwenz             #+#    #+#              #
#    Updated: 2023/08/23 09:27:31 by cwenz            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
NAME			:= philo

# Compiler and flags
CC				:= cc
CFLAGS			:= -Wall -Werror -Wextra -pthread
INCLUDES		:= -I./includes

# Directories
BUILD_DIR		:= .build

# Source
SRC_DIR			:= ./src/

SRC_FILES		:= main.c

SRC 			+= $(addprefix $(SRC_DIR), $(SRC_FILES))

# Objects
## patsubst replaces %.c with $(BUILD_DIR)/.o for every file in $(SRC),
OBJS			:= $(patsubst %.c, $(BUILD_DIR)/%.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(NAME)
	@echo $(GREEN)"PHILOSOPHERS: Compiled successfully"$(DEFAULT)

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@if [ -d $(BUILD_DIR) ]; then \
		rm -r $(BUILD_DIR); \
	fi
	@echo $(RED)"Removing object files"$(DEFAULT)

fclean: clean
	@rm -f $(NAME)
	@echo $(RED)"Removing program"$(DEFAULT)

re: fclean all

.PHONY: all $(NAME) clean fclean re

# Colours to make it look nice :)
DEFAULT			= "\033[39m"
GREEN			= "\033[32m"
RED				= "\033[31m"