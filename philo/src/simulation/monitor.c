/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:11:27 by cwenz             #+#    #+#             */
/*   Updated: 2023/09/29 18:08:52 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	should_philosopher_die(t_philosopher *philosopher);

void	monitor_philosophers(t_simulation_state *simulation_context, int argc)
{
	t_philosopher	*philosopher;
	long			philo_count;

	philosopher = simulation_context->philosphers;
	simulation_context->num_philo_finished_eating = 0;
	philo_count = philosopher->sim_data->philo_count;
	while (true)
	{
		if (argc == 6)
		{
			lock_has_eaten_flag(philosopher);
			if (philosopher->has_finished_eating && !philosopher->has_counted_philo)
			{
				simulation_context->num_philo_finished_eating++;
				philosopher->has_counted_philo = true;
			}
			unlock_has_eaten_flag(philosopher);
			if (simulation_context->num_philo_finished_eating >= philo_count)
				return ;
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
