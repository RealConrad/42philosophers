/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:06:01 by cwenz             #+#    #+#             */
/*   Updated: 2023/10/06 14:45:50 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	handle_simulation(t_philosopher *philosopher);

void	*begin_simulation(void *arg)
{
	t_philosopher	*philosopher;

	philosopher = (t_philosopher *)arg;
	pthread_mutex_lock(philosopher->shared_mutex);
	pthread_mutex_unlock(philosopher->shared_mutex);
	handle_simulation(philosopher);
	return (NULL);
}

static void	handle_simulation(t_philosopher *philosopher)
{
	pthread_mutex_lock(philosopher->shared_mutex);
	print_philosopher_state(philosopher, THINKING);
	pthread_mutex_unlock(philosopher->shared_mutex);
	if (philosopher->index % 2 == ODD)
	{
		philosopher_eat(philosopher);
		philosopher_sleep(philosopher);
		pthread_mutex_lock(philosopher->shared_mutex);
		print_philosopher_state(philosopher, THINKING);
		pthread_mutex_unlock(philosopher->shared_mutex);
	}
	else
	{
		philosopher_sleep(philosopher);
		pthread_mutex_lock(philosopher->shared_mutex);
		print_philosopher_state(philosopher, THINKING);
		pthread_mutex_unlock(philosopher->shared_mutex);
	}
	
	while (true)
	{
		if (check_philo_sim_exit(philosopher))
		{
			printf("Philo[%d] EXITING!!!\n", philosopher->index);
			return ;
		}
		philosopher_eat(philosopher);
		philosopher_sleep(philosopher);
		pthread_mutex_lock(philosopher->shared_mutex);
		print_philosopher_state(philosopher, THINKING);
		pthread_mutex_unlock(philosopher->shared_mutex);
	}
}

// static void	handle_simulation(t_philosopher *philosopher)
// {
// 	pthread_mutex_lock(philosopher->shared_mutex);
// 	print_philosopher_state(philosopher, THINKING);
// 	pthread_mutex_unlock(philosopher->shared_mutex);
// 	while (true)
// 	{
// 		if (check_philo_sim_exit(philosopher))
// 			return ;
// 		if (philosopher->index % 2 == ODD)
// 		{
// 			philosopher_eat(philosopher);
// 			philosopher_sleep(philosopher);
// 			pthread_mutex_lock(philosopher->shared_mutex);
// 			print_philosopher_state(philosopher, THINKING);
// 			pthread_mutex_unlock(philosopher->shared_mutex);
// 		}
// 		else
// 		{
// 			philosopher_sleep(philosopher);
// 			philosopher_eat(philosopher);
// 			pthread_mutex_lock(philosopher->shared_mutex);
// 			print_philosopher_state(philosopher, THINKING);
// 			pthread_mutex_unlock(philosopher->shared_mutex);
// 		}
// 	}
// }
