/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:14:28 by cwenz             #+#    #+#             */
/*   Updated: 2023/09/16 18:31:28 by cwenz            ###   ########.fr       */
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
	t_fork					*left_fork;
	t_fork					*right_fork;
	t_simulation_data		*sim_data;
	pthread_t				thread;
	t_philosopher_state		state;
	pthread_mutex_t			time_since_last_meal_mutex;
	pthread_mutex_t			number_of_times_eaten_mutex;
	int						index;
	int						number_of_times_eaten;
	long long				time_since_last_meal;
	long long				start_time_ms;
}	t_philosopher;

typedef struct s_simulation_state {
	t_philosopher	*philosphers;
	t_fork			*forks;
}	t_simulation_state;

/* ************************************************************************** */
/*                                 Simulation                                 */
/* ************************************************************************** */
void		*begin_simulation(void *arg);
bool		can_philosopher_eat(t_philosopher *philosopher);
void		lock_forks(t_philosopher *philosopher);
void		unlock_forks(t_philosopher *philosopher);
void		philosopher_sleep(t_philosopher *philosopher);
void		philosopher_think(t_philosopher *philosopher);
void		philosopher_try_eat(t_philosopher *philosopher);
void		monitor_philosophers(t_simulation_state *simulation_context, int argc);
void		update_number_of_times_eaten(t_philosopher *philosopher);

/* ************************************************************************** */
/*                                 Free                                       */
/* ************************************************************************** */
void		free_simulation(t_simulation_state *simulation_context, const char *msg, bool display_error);

/* ************************************************************************** */
/*                                 Initialize                                 */
/* ************************************************************************** */
int			init_philos(t_simulation_state *simulation_context, int argc, char **argv);
int			init_mutex(t_simulation_state *simulation_context, int index);
int			assign_new_philosopher_data(t_simulation_state *simulation_context, t_philosopher *new_philosopher, int index, char **argv);
bool		check_input(int argc, char **argv);

/* ************************************************************************** */
/*                                 Time                                       */
/* ************************************************************************** */
void		wait_for_duration(long wait_time);
long long	get_current_time(void);
long long	get_time_difference(long long start_time_ms);
void		lock_time_mutex(t_philosopher *philosopher);
void		unlock_time_mutex(t_philosopher *philosopher);
void		update_time_since_last_meal(t_philosopher *philosopher);

/* ************************************************************************** */
/*                                 Utils                                      */
/* ************************************************************************** */
long		atol(const char *str);
void		join_threads(t_simulation_state *simulation_context);
void		detach_threads(t_simulation_state *simulation_context);
void		print_philosopher_state(t_philosopher *philisopher);
void		change_philosopher_state(t_philosopher *philosopher, t_philosopher_state state);

/* ************************************************************************** */
/*                                 Fork Utils                                 */
/* ************************************************************************** */
void		lock_left_fork(t_philosopher *philosopher);
void		lock_right_fork(t_philosopher *philosopher);
void		unlock_left_fork(t_philosopher *philosopher);
void		unlock_right_fork(t_philosopher *philosopher);

/* ************************************************************************** */
/*                                 Eat Utils                                  */
/* ************************************************************************** */
void	lock_eat_counter_mutex(t_philosopher *philosopher);
void	unlock_eat_counter_mutex(t_philosopher *philosopher);

#endif /* PHILOSOPHERS_H */