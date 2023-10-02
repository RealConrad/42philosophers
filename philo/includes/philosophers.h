/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:14:28 by cwenz             #+#    #+#             */
/*   Updated: 2023/10/01 19:05:57 by cwenz            ###   ########.fr       */
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
# include <sys/time.h>

/* ************************************************************************** */
/*                                 Macro's                                    */
/* ************************************************************************** */
# define SUCCESS 0
# define ERROR -1
# define ATE_ENOUGH 2
# define EVEN 0
# define ODD 1
# define FORK_TEXT "has taken a fork"
# define EATING_TEXT "is eating"
# define SLEEP_TEXT "is sleeping"
# define THINKING_TEXT "is thinking"
# define DEATH_TEXT "died"

/* ************************************************************************** */
/*                                 Typedefs                                   */
/* ************************************************************************** */

typedef enum e_philosopher_state {
	IDLE,
	TAKEN_FORK,
	EATING,
	THINKING,
	SLEEPING,
	FINISHED_EATING,
	DEATH
}	t_philosopher_state;

typedef struct s_fork {
	pthread_mutex_t	mutex;
	int				id;
}	t_fork;

typedef struct s_simulation_data {
	long	philo_count;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	required_eat_times;
}	t_simulation_data;

typedef struct s_philosopher {
	struct s_philosopher	*next;
	struct s_philosopher	*prev;
	t_fork					left_fork;
	t_fork					right_fork;
	t_simulation_data		sim_data;
	pthread_t				thread;
	pthread_mutex_t			eat_count_mutex;
	pthread_mutex_t			*start_mutex;
	pthread_mutex_t			*print_mutex;
	pthread_mutex_t			time_since_last_meal_mutex;
	int						index;
	bool					exit_sim;
	bool					eaten_enough;
	int						eat_count;
	long long				time_since_last_meal;
	long long				start_time_ms;
}	t_philosopher;

typedef struct s_simulation_state {
	t_philosopher	*philosphers;
	t_fork			*forks;
	long			num_finished_eating;
	pthread_mutex_t	start_mutex;
	pthread_mutex_t	print_mutex;
}	t_simulation_state;


/* -------------------------------------------------------------------------- */
/*                                 Simulation                                 */
/* -------------------------------------------------------------------------- */

void		*begin_simulation(void *arg);
void		philosopher_eat(t_philosopher *philosopher);
void		philosopher_sleep(t_philosopher *philosopher);
void		lock_forks(t_philosopher *philosopher);
void		unlock_forks(t_philosopher *philosopher);

/* -------------------------------------------------------------------------- */
/*                                   Monitor                                  */
/* -------------------------------------------------------------------------- */

void		monitor_philosophers(t_simulation_state *simulation_context);

/* -------------------------------------------------------------------------- */
/*                                    Print                                   */
/* -------------------------------------------------------------------------- */
void		print_philosopher_state(t_philosopher *philosopher, t_philosopher_state state);

/* -------------------------------------------------------------------------- */
/*                                    Init                                    */
/* -------------------------------------------------------------------------- */

int			init_philos(t_simulation_state *simulation_context, int argc, char **argv);
void		add_philosopher_to_linked_list(t_simulation_state *simulation_context, t_philosopher *node);
int			init_forks(t_simulation_state *simulation_context, char **argv);

/* -------------------------------------------------------------------------- */
/*                                    Time                                    */
/* -------------------------------------------------------------------------- */

void		wait_for_duration(long wait_time);
long long	get_time_difference(long long start_time_ms);
long long	get_current_time(void);

/* -------------------------------------------------------------------------- */
/*                                    Utils                                   */
/* -------------------------------------------------------------------------- */

long		atol(const char *str);
bool		check_input(int argc, char **argv);

/* -------------------------------------------------------------------------- */
/*                                    Utils                                   */
/* -------------------------------------------------------------------------- */

void	detach_threads(t_simulation_state *simulation_context);

#endif /* PHILOSOPHERS_H */