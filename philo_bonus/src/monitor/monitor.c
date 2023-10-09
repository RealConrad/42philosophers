/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:08:15 by cwenz             #+#    #+#             */
/*   Updated: 2023/10/10 00:43:34 by cwenz            ###   ########.fr       */
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
			philosopher->exit_sim = true;
			break ;
		}
		usleep(100);
	}
	exit(0);
}

// static int	check_eat_count(t_philosopher *philosopher,
// 	t_simulation_state *simulation_context)
// {
// 	pthread_mutex_lock(&philosopher->philo_mutex);
// 	if (philosopher->eat_count == philosopher->sim_data.required_eat_times
// 		&& !philosopher->eaten_enough)
// 	{
// 		philosopher->eaten_enough = true;
// 		simulation_context->num_finished_eating++;
// 		if (simulation_context->num_finished_eating
// 			== philosopher->sim_data->philo_count)
// 		{
// 			// pthread_mutex_unlock(&philosopher->philo_mutex);
// 			return (ERROR);
// 		}
// 	}
// 	// pthread_mutex_unlock(&philosopher->philo_mutex);
// 	return (SUCCESS);
// }
