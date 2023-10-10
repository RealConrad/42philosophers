/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:14:28 by cwenz             #+#    #+#             */
/*   Updated: 2023/10/10 04:51:32 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_BONUS_H
# define PHILOSOPHERS_BONUS_H

// fix
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <limits.h>
# include <sys/time.h>
# include <semaphore.h>
# include <fcntl.h>
# include <signal.h>

/* --------------------------------- Macros --------------------------------- */
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

/* -------------------------------- Typedefs -------------------------------- */
typedef enum e_philosopher_state {
	IDLE,
	TAKEN_FORK,
	EATING,
	THINKING,
	SLEEPING,
	FINISHED_EATING,
	DEATH
}	t_philosopher_state;

typedef enum e_error_type {
	ERR_MUTEX_INITIALIZATION,
	ERR_THREAD_CREATION,
	ERR_INVALID_ARG,
	ERR_MEMORY_ALLOCATION,
	ERR_FORK_INITIALIZATION,
}	t_error_type;

typedef struct s_simulation_data {
	sem_t	*forks;
	sem_t	*print;
	sem_t	*is_done_eating;
	sem_t	*exit_program;
	long	philo_count;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	required_eat_times;
}	t_simulation_data;

typedef struct s_philosopher {
	struct s_philosopher	*next;
	struct s_philosopher	*prev;
	t_simulation_data		*sim_data;
	sem_t					*philo_sem;
	char					*sem_name;
	pid_t					pid;
	int						index;
	int						eat_count;
	bool					exit_sim;
	long long				time_since_last_meal;
	long long				*start_time_ms;
}	t_philosopher;

typedef struct s_simulation_state {
	t_philosopher		*philosphers;
	t_simulation_data	sim_data;
	long long			start_time_ms;
}	t_simulation_state;

/* ------------------------------- Simulaiton ------------------------------- */
int			create_philosopher_processes(
				t_simulation_state *simulation_context);
void		philosopher_think(t_philosopher *philosopher);
void		philosopher_sleep(t_philosopher *philosopher);
void		philosopher_eat(t_philosopher *philosopher);
void		*monitor_philosopher(void *arg);
void		update_philo_eat_data(t_philosopher *philosopher);
void		philosopher_normal_routine(t_philosopher *philosopher);

/* ---------------------------------- Print --------------------------------- */
void		print_philosopher_state(t_philosopher *philosopher,
				t_philosopher_state state);

/* ---------------------------------- Init ---------------------------------- */
int			init_sim_data(t_simulation_data *simulation_data, int argc,
				char **argv);
int			init_philos(t_simulation_state *simulaiton_context);

/* ---------------------------------- Free ---------------------------------- */
void		kill_and_free(t_simulation_state *simulaiton_context);

/* ---------------------------------- Time ---------------------------------- */
void		wait_for_duration(long wait_time);
long long	get_time_difference(long long start_time_ms);
long long	get_current_time(void);

/* ---------------------------------- Error --------------------------------- */
void		display_error(t_error_type error_type);

/* ---------------------------------- Utils --------------------------------- */
long		atol(const char *str);
bool		check_input(int argc, char **argv);
char		*strjoin(const char *str, int index);

#endif /* PHILOSOPHERS_BONUS_H */