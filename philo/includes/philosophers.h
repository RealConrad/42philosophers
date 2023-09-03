/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:14:28 by cwenz             #+#    #+#             */
/*   Updated: 2023/09/03 15:49:04 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <limits.h>

# define SUCCESS 0
# define ERROR -1 

typedef enum e_philosopher_state {
	TAKING_FORK,
	EATING,
	THINKING,
	SLEEPING,
	DEATH
}	t_philosopher_state;

typedef struct s_philosopher {
	struct s_philosopher	*next;
	struct s_philosopher	*prev;
	t_philosopher_state		state;
	int						index;
}	t_philosopher;

typedef struct s_simulation_state {
	t_philosopher	*philosphers;
	int				philo_count;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				required_eat_times;
}	t_simulation_state;

/* Init */
int		init_philosophers(t_simulation_state **simulation_context, int argc, char **argv);
bool	check_input(int argc, char **argv);

/* Utils */
void	print_error_message(const char *msg);
long	atol(const char *str);
void print_list(t_simulation_state *philo); // delete!


#endif /* PHILOSOPHERS_H */