# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/22 15:16:09 by cwenz             #+#    #+#              #
#    Updated: 2023/10/12 16:18:09 by cwenz            ###   ########.fr        #
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
TIME_DIR		:= ./src/time/
UTIL_DIR		:= ./src/utils/
MONITOR_DIR		:= ./src/monitor/
SIM_DIR			:= ./src/simulation/
PRINT_DIR		:= ./src/print/
FREE_DIR		:= ./src/free/

SRC_FILES		:= main.c
INIT_FILES		:= init.c init_utils.c
SIM_FILES		:= simulation.c simulation_utils.c forks.c
MONITOR_FILES	:= monitor.c
TIME_FILES		:= time.c
UTIL_FILES		:= input_utils.c utils.c
PRINT_FILES		:= print.c
FREE_FILES		:= free.c

SRC 			+= $(addprefix $(SRC_DIR), $(SRC_FILES))
SRC 			+= $(addprefix $(INIT_DIR), $(INIT_FILES))
SRC 			+= $(addprefix $(TIME_DIR), $(TIME_FILES))
SRC 			+= $(addprefix $(UTIL_DIR), $(UTIL_FILES))
SRC 			+= $(addprefix $(MONITOR_DIR), $(MONITOR_FILES))
SRC 			+= $(addprefix $(SIM_DIR), $(SIM_FILES))
SRC				+= $(addprefix $(PRINT_DIR), $(PRINT_FILES))
SRC				+= $(addprefix $(FREE_DIR), $(FREE_FILES))

# Objects
## patsubst replaces %.c with $(BUILD_DIR)/.o for every file in $(SRC),
OBJS			:= $(patsubst %.c, $(BUILD_DIR)/%.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(NAME)

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	@if [ -d $(BUILD_DIR) ]; then \
		rm -r $(BUILD_DIR); \
	fi

fclean: clean
	rm -f $(NAME)

re: fclean all

norm:
	norminette -R ForbiddenSourceHeaders

.PHONY: all clean fclean re norm

# Colours to make it look nice :)
DEFAULT			= "\033[39m"
GREEN			= "\033[32m"
RED				= "\033[31m"
