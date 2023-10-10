# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/22 15:16:09 by cwenz             #+#    #+#              #
#    Updated: 2023/10/10 11:01:37 by cwenz            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
NAME			:= philo_bonus

# Compiler and flags
#-fsanitize=thread
CC				:= cc
CFLAGS			:= -Wall -Werror -Wextra -pthread -fsanitize=thread
INCLUDES		:= -I./includes_bonus
# Directories
BUILD_DIR		:= .build

# Source
SRC_DIR			:= ./src/
MONITOR_DIR		:= ./src/monitor/
PRINT_DIR		:= ./src/print/
INIT_DIR		:= ./src/init/
TIME_DIR		:= ./src/time/
UTIL_DIR		:= ./src/utils/
SIM_DIR			:= ./src/simulation/
FREE_DIR		:= ./src/free/

SRC_FILES		:= main.c
MONITOR_FILES	:= monitor.c
PRINT_FILES		:= print.c
TIME_FILES		:= time.c
FREE_FILES		:= free.c
INIT_FILES		:= init_philo.c init_sim_data.c
UTIL_FILES		:= input_utils.c utils.c
SIM_FILES		:= simulation.c simulation_utils.c

SRC 			+= $(addprefix $(SRC_DIR), $(SRC_FILES))
SRC 			+= $(addprefix $(MONITOR_DIR), $(MONITOR_FILES))
SRC 			+= $(addprefix $(PRINT_DIR), $(PRINT_FILES))
SRC 			+= $(addprefix $(TIME_DIR), $(TIME_FILES))
SRC 			+= $(addprefix $(UTIL_DIR), $(UTIL_FILES))
SRC 			+= $(addprefix $(INIT_DIR), $(INIT_FILES))
SRC 			+= $(addprefix $(SIM_DIR), $(SIM_FILES))
SRC 			+= $(addprefix $(FREE_DIR), $(FREE_FILES))

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

norm:
	norminette -R ForbiddenSourceHeaders

.PHONY: all clean fclean re norm

# Colours to make it look nice :)
DEFAULT			= "\033[39m"
GREEN			= "\033[32m"
RED				= "\033[31m"