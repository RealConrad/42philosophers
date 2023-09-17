/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:11:27 by cwenz             #+#    #+#             */
/*   Updated: 2023/09/17 13:14:40 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	should_philosopher_die(t_philosopher *philosopher);
static int	has_eaten_enough_times(t_philosopher *philosopher);

void	monitor_philosophers(t_simulation_state *simulation_context, int argc)
{
	t_philosopher	*philosopher;

	philosopher = simulation_context->philosphers;
	simulation_context->num_philo_finished_eating = 0;
	while (true)
	{
		if (argc == 6)
		{
			(void)has_eaten_enough_times;
		}
		if (should_philosopher_die(philosopher) != SUCCESS)
			return ;
		
		philosopher = philosopher->next;
	}
}

static int	has_eaten_enough_times(t_philosopher *philosopher)
{
	(void)philosopher;
	return (SUCCESS);
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
