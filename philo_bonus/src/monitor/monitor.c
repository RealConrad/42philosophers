/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:08:15 by cwenz             #+#    #+#             */
/*   Updated: 2023/10/11 14:17:19 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	*monitor_philosopher(void *arg)
{
	t_philosopher	*philosopher;

	philosopher = (t_philosopher *)arg;
	while (true)
	{
		sem_wait(philosopher->philo_sem);
		if (get_time_difference(philosopher->time_since_last_meal) > philosopher->sim_data->time_to_die)
		{
			philosopher->exit_sim = true;
			sem_post(philosopher->philo_sem);
			sem_wait(philosopher->sim_data->print);
			print_philosopher_state(philosopher, DEATH);
			sem_post(philosopher->sim_data->exit_program);
			exit(0);
		}
		sem_post(philosopher->philo_sem);
		usleep(100);
	}
	return (NULL);
}
