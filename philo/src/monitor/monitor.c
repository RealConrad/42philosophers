/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 13:36:24 by cwenz             #+#    #+#             */
/*   Updated: 2023/10/01 17:39:11 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	check_eat_count(t_philosopher *philosopher, t_simulation_state *simulation_context);

void	monitor_philosophers(t_simulation_state *simulation_context)
{
	t_philosopher	*temp;

	temp = simulation_context->philosphers;
	simulation_context->num_finished_eating = 0;
	pthread_mutex_unlock(&simulation_context->start_mutex);
	while (true)
	{
		if (temp->sim_data.required_eat_times && check_eat_count(temp, simulation_context) != SUCCESS)
		{
			pthread_mutex_lock(&simulation_context->print_mutex);
			return ;
		}
		// if (temp->time_since_last_meal > temp->sim_data.time_to_die)
		// {
		// 	pthread_mutex_lock(&simulation_context->print_mutex);
		// 	return ;
		// }
		temp = temp->next;
	}
}

static int	check_eat_count(t_philosopher *philosopher, t_simulation_state *simulation_context)
{
	pthread_mutex_lock(&philosopher->eat_count_mutex);
	if (philosopher->eat_count == philosopher->sim_data.required_eat_times && !philosopher->eaten_enough)
	{
		philosopher->eaten_enough = true;
		simulation_context->num_finished_eating++;
		if (simulation_context->num_finished_eating == philosopher->sim_data.philo_count)
			return (ERROR);
	}
	pthread_mutex_unlock(&philosopher->eat_count_mutex);
	return (SUCCESS);
}
