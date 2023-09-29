/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 13:44:24 by cwenz             #+#    #+#             */
/*   Updated: 2023/09/29 14:36:08 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static bool	check_numeric(const char *str);
static int	init_philosopher_mutexes(t_philosopher *philosopher);

bool	check_input(int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (!check_numeric(argv[i]) || atol(argv[i]) > INT_MAX)
			return (false);
		i++;
	}
	return (true);
}

static bool	check_numeric(const char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
		i++;
	}
	return (true);
}

int	init_mutex(t_simulation_state *simulation_context, int index)
{
	if (pthread_mutex_init(&simulation_context->forks[index].mutex, NULL) != SUCCESS)
		return (ERROR);
	simulation_context->forks[index].id = index;
	return (SUCCESS);
}

int	assign_new_philosopher_data(t_simulation_state *simulation_context, t_philosopher *new_philosopher, int index, char **argv)
{
	new_philosopher->sim_data = malloc(sizeof(t_simulation_data));
	if (!new_philosopher->sim_data)
		return (ERROR);
	new_philosopher->sim_data->philo_count = atol(argv[0]);
	new_philosopher->sim_data->time_to_die = atol(argv[1]);
	new_philosopher->sim_data->time_to_eat = atol(argv[2]);
	new_philosopher->sim_data->time_to_sleep = atol(argv[3]);
	if (argv[4])
		new_philosopher->sim_data->required_eat_times = atol(argv[4]);
	new_philosopher->state = IDLE;
	new_philosopher->number_of_times_eaten = 0;
	new_philosopher->index = index;
	new_philosopher->time_since_last_meal = get_current_time();
	new_philosopher->has_finished_eating = false;
	new_philosopher->has_counted_philo = false;
	new_philosopher->left_fork = &simulation_context->forks[index];
	new_philosopher->right_fork = &simulation_context->forks[(index + 1) % new_philosopher->sim_data->philo_count];
	if (init_philosopher_mutexes(new_philosopher) != SUCCESS)
		return (ERROR);
	return (SUCCESS);
}

static int	init_philosopher_mutexes(t_philosopher *philosopher)
{
	if (pthread_mutex_init(&philosopher->time_since_last_meal_mutex, NULL) != SUCCESS)
		return (ERROR);
	if (pthread_mutex_init(&philosopher->state_change_mutex, NULL) != SUCCESS)
		return (ERROR);
	if (philosopher->sim_data->required_eat_times && pthread_mutex_init(&philosopher->has_finished_eating_mutex, NULL) != SUCCESS)
		return (ERROR);
	return (SUCCESS);
}
