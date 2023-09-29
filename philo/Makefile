# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/22 15:16:09 by cwenz             #+#    #+#              #
#    Updated: 2023/09/29 16:55:05 by cwenz            ###   ########.fr        #
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
INIT_DIR		:= ./src/init/
UTIL_DIR		:= ./src/utils/
SIM_DIR			:= ./src/simulation/
FREE_DIR		:= ./src/free/
TIME_DIR		:= ./src/time/

SRC_FILES		:= main.c
INIT_FILES		:= init.c init_utils.c
SIM_FILES		:= start_simulation.c fork.c simulation_utils.c monitor.c eat.c
TIME_FILES		:= time.c
UTIL_FILES		:= utils.c fork_utils.c state_utils.c time_utils.c eat_utils.c
FREE_FILES		:= free_simulation.c

SRC 			+= $(addprefix $(SRC_DIR), $(SRC_FILES))
SRC 			+= $(addprefix $(INIT_DIR), $(INIT_FILES))
SRC 			+= $(addprefix $(UTIL_DIR), $(UTIL_FILES))
SRC 			+= $(addprefix $(FREE_DIR), $(FREE_FILES))
SRC 			+= $(addprefix $(SIM_DIR), $(SIM_FILES))
SRC 			+= $(addprefix $(TIME_DIR), $(TIME_FILES))

# Objects
## patsubst replaces %.c with $(BUILD_DIR)/.o for every file in $(SRC),
OBJS			:= $(patsubst %.c, $(BUILD_DIR)/%.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(NAME)
	@echo $(GREEN)"PHILOSOPHERS: Compiled successfully 〈◕﹏◕〉 ¯\_(ツ)_/¯"$(DEFAULT)

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
	@echo $(RED)"Removing $(NAME)"$(DEFAULT)

re: fclean all

.PHONY: all clean fclean re

# Colours to make it look nice :)
DEFAULT			= "\033[39m"
GREEN			= "\033[32m"
RED				= "\033[31m"