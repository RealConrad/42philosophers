/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 13:36:24 by cwenz             #+#    #+#             */
/*   Updated: 2023/10/13 13:45:02 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	check_eat_count(t_philosopher *philosopher,
				t_simulation_state *simulation_context);
static int	should_philosopher_die(t_philosopher *philosopher);

/**
 * @brief Monitors the philosophers to check if the simulation should end.
 * 
 * 	It unlocks a shared mutex which then allows each thread to start the
 * 	simulation.
 * @param simulation_context The simulation context which holds all simulaiton
 * 	related data as well as the philosophers.
 */
void	monitor_philosophers(t_simulation_state *simulation_context)
{
	t_philosopher	*philosopher;

	philosopher = simulation_context->philosphers;
	simulation_context->num_finished_eating = 0;
	simulation_context->start_time_ms = get_current_time();
	pthread_mutex_unlock(&simulation_context->shared_mutex);
	while (true)
	{
		if (philosopher->sim_data.required_eat_times
			&& check_eat_count(philosopher, simulation_context) != SUCCESS)
		{
			pthread_mutex_lock(&simulation_context->shared_mutex);
			return ;
		}
		if (should_philosopher_die(philosopher) != SUCCESS)
		{
			pthread_mutex_lock(&simulation_context->shared_mutex);
			print_philosopher_state(philosopher, DEATH);
			return ;
		}
		philosopher = philosopher->next;
	}
}

/**
 * @brief Checks if all philosophers have eaten atleast the required amount
 * 	of times. 
 * @param philosopher The philosopher to check if eaten enough.
 * @param simulation_context The context which holds the counter of the
 * 	total number of philosophers that have eaten enough.
 * @return True if the philosophers haven't eaten enough, false if all
 * 	philosophers
 */
static int	check_eat_count(t_philosopher *philosopher,
	t_simulation_state *simulation_context)
{
	pthread_mutex_lock(&philosopher->philo_mutex);
	if (philosopher->eat_count == philosopher->sim_data.required_eat_times
		&& !philosopher->eaten_enough)
	{
		philosopher->eaten_enough = true;
		simulation_context->num_finished_eating++;
		if (simulation_context->num_finished_eating
			== philosopher->sim_data.philo_count)
		{
			pthread_mutex_unlock(&philosopher->philo_mutex);
			return (ERROR);
		}
	}
	pthread_mutex_unlock(&philosopher->philo_mutex);
	return (SUCCESS);
}

/**
 * @brief Checks if the philosopher has starved.
 * @param philosopher The philosopher to check.
 * @return True if the philosopher has NOT starved, otherwise false.
 */
static int	should_philosopher_die(t_philosopher *philosopher)
{
	pthread_mutex_lock(&philosopher->philo_mutex);
	if (get_time_difference(philosopher->time_since_last_meal)
		> philosopher->sim_data.time_to_die)
	{
		pthread_mutex_unlock(&philosopher->philo_mutex);
		return (ERROR);
	}
	pthread_mutex_unlock(&philosopher->philo_mutex);
	return (SUCCESS);
}
