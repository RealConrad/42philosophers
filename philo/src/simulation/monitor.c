/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:11:27 by cwenz             #+#    #+#             */
/*   Updated: 2023/09/13 15:35:12 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"



void	monitor_philosophers(t_simulation_state *simulation_context)
{
	t_philosopher	*philosopher;
	long long		time;

	(void) simulation_context;
	philosopher = simulation_context->philosphers;
	while (true)
	{
		lock_time_mutex(philosopher);
		time = get_time_difference(philosopher->time_since_last_meal);
		if (time > philosopher->sim_data->time_to_die)
		{
			change_philosopher_state(philosopher, DEATH);
			print_philosopher_state(philosopher);
			exit(0);
		}
		unlock_time_mutex(philosopher);
		philosopher = philosopher->next;
	}
}
