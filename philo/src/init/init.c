/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 12:49:03 by cwenz             #+#    #+#             */
/*   Updated: 2023/10/06 16:21:19 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	init_philo_mutexes(t_philosopher *philosopher,
				t_simulation_state *simulation_context);
static int	assign_new_philosopher_data(t_simulation_state *simulation_context,
				t_philosopher *philosopher, char **argv);
static int	init_philo_linked_list(t_simulation_state *simulation_context,
				char **argv);
static int	create_threads(t_simulation_state *simulation_context);

int	init_philos(t_simulation_state *simulation_context, int argc, char **argv)
{
	if (!check_input(argc, argv))
		return (ERROR);
	if (init_philo_linked_list(simulation_context, argv) != SUCCESS)
		return (ERROR);
	return (SUCCESS);
}

static int	init_philo_linked_list(t_simulation_state *simulation_context,
				char **argv)
{
	t_philosopher	*philosopher;
	int				i;

	i = 1;
	pthread_mutex_init(&simulation_context->shared_mutex, NULL);
	pthread_mutex_lock(&simulation_context->shared_mutex);
	simulation_context->start_time_ms = 0;
	while (i <= (int)atol(argv[0]))
	{
		philosopher = malloc(sizeof(t_philosopher));
		if (!philosopher)
			return (ERROR);
		philosopher->index = i;
		if (assign_new_philosopher_data(simulation_context, philosopher, argv)
			!= SUCCESS)
			return (ERROR);
		add_philosopher_to_linked_list(simulation_context, philosopher);
		i++;
	}
	if (create_threads(simulation_context) != SUCCESS)
		return (ERROR);
	return (SUCCESS);
}

static int	assign_new_philosopher_data(t_simulation_state *simulation_context,
				t_philosopher *philosopher, char **argv)
{
	philosopher->sim_data.philo_count = atol(argv[0]);
	philosopher->sim_data.time_to_die = atol(argv[1]);
	philosopher->sim_data.time_to_eat = atol(argv[2]);
	philosopher->sim_data.time_to_sleep = atol(argv[3]);
	if (argv[4])
		philosopher->sim_data.required_eat_times = atol(argv[4]);
	philosopher->eat_count = 0;
	philosopher->start_time_ms = &simulation_context->start_time_ms;
	philosopher->exit_sim = false;
	philosopher->eaten_enough = false;
	philosopher->time_since_last_meal = get_current_time();
	init_philo_mutexes(philosopher, simulation_context);
	return (SUCCESS);
}

static int	init_philo_mutexes(t_philosopher *philosopher,
				t_simulation_state *simulation_context)
{
	if (pthread_mutex_init(&philosopher->philo_mutex, NULL) != SUCCESS)
		return (ERROR);
	philosopher->shared_mutex = &simulation_context->shared_mutex;
	return (SUCCESS);
}

static int	create_threads(t_simulation_state *simulation_context)
{
	t_philosopher	*philosopher;

	philosopher = simulation_context->philosphers;
	while (true)
	{
		if (pthread_create(&philosopher->thread, NULL,
				*begin_simulation, philosopher)
			!= SUCCESS)
			return (ERROR);
		philosopher = philosopher->next;
		if (philosopher == simulation_context->philosphers)
			return (SUCCESS);
	}
	return (SUCCESS);
}
