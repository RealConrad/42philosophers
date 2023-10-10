/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:08:15 by cwenz             #+#    #+#             */
/*   Updated: 2023/10/10 03:53:07 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	*monitor_philosopher(void *arg)
{
	t_philosopher	*philosopher;

	philosopher = (t_philosopher *)arg;
	while (true)
	{
		if (get_time_difference(philosopher->time_since_last_meal) > philosopher->sim_data->time_to_die)
		{
			sem_wait(philosopher->sim_data->print);
			print_philosopher_state(philosopher, DEATH);
			sem_wait(philosopher->philo_sem);
			philosopher->exit_sim = true;
			sem_post(philosopher->philo_sem);
			sem_post(philosopher->sim_data->exit_program);
			break ;
		}
		usleep(100);
	}
	return (NULL);
}
