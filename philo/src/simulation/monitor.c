/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:11:27 by cwenz             #+#    #+#             */
/*   Updated: 2023/09/18 16:42:27 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	should_philosopher_die(t_philosopher *philosopher);

void	monitor_philosophers(t_simulation_state *simulation_context, int argc)
{
	t_philosopher	*philosopher;

	philosopher = simulation_context->philosphers;
	simulation_context->num_philo_finished_eating = 0;
	while (true)
	{
		if (argc == 6)
		{
			lock_philosopher_state(philosopher);
			if (philosopher->state == FINISHED_EATING)
				simulation_context->num_philo_finished_eating++;
			if (simulation_context->num_philo_finished_eating >= philosopher->sim_data->philo_count)
				return ;
			unlock_philosopher_state(philosopher);
		}
		if (should_philosopher_die(philosopher) != SUCCESS)
			return ;
		
		philosopher = philosopher->next;
	}
}

static int	should_philosopher_die(t_philosopher *philosopher)
{
	long long	time;

	lock_time_mutex(philosopher);
	time = get_time_difference(philosopher->time_since_last_meal);
	if (time > philosopher->sim_data->time_to_die)
	{
		change_philosopher_state(philosopher, DEATH);
		print_philosopher_state(philosopher);
		return (ERROR);
	}
	unlock_time_mutex(philosopher);
	return (SUCCESS);
}
