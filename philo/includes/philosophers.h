/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:14:28 by cwenz             #+#    #+#             */
/*   Updated: 2023/09/04 15:12:53 by cwenz            ###   ########.fr       */
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

typedef struct s_fork {
	pthread_mutex_t	mutex;
	int				id;
	bool			in_use;
}	t_fork;

typedef struct s_philosopher {
	struct s_philosopher	*next;
	struct s_philosopher	*prev;
	t_fork					*left_fork;
	t_fork					*right_fork;
	pthread_t				thread;
	int						index;
	int						time_since_last_meal;
}	t_philosopher;

typedef struct s_simulation_state {
	t_philosopher	*philosphers;
	t_fork			*forks;
	int				philo_count;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				required_eat_times;
}	t_simulation_state;

/* Simulation */
void	*begin_simulation(void *arg);

/* Free */
void	free_simulation(t_simulation_state **simulation_context, char *msg);

/* Init */
int		init_philos(t_simulation_state **simulation_context, int argc, char **argv);
bool	check_input(int argc, char **argv);

/* Utils */
void	print_error_message(const char *msg);
long	atol(const char *str);
void	join_threads(t_simulation_state **simulation_context);
void	detach_threads(t_simulation_state **simulation_context);
void 	print_list(t_simulation_state *philo); // delete!

#endif /* PHILOSOPHERS_H */