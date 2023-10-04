/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 16:15:46 by cwenz             #+#    #+#             */
/*   Updated: 2023/10/03 18:26:26 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	update_philo_eat_data(t_philosopher *philosopher);

void	philosopher_eat(t_philosopher *philosopher)
{
	lock_forks(philosopher);
	
	pthread_mutex_lock(philosopher->shared_mutex);
	print_philosopher_state(philosopher, EATING);
	pthread_mutex_unlock(philosopher->shared_mutex);
	
	update_philo_eat_data(philosopher);
	wait_for_duration(philosopher->sim_data.time_to_eat);
	unlock_forks(philosopher);
}

void	philosopher_sleep(t_philosopher *philosopher)
{
	pthread_mutex_lock(philosopher->shared_mutex);
	print_philosopher_state(philosopher, SLEEPING);
	pthread_mutex_unlock(philosopher->shared_mutex);

	wait_for_duration(philosopher->sim_data.time_to_sleep);
}

static void	update_philo_eat_data(t_philosopher *philosopher)
{
	pthread_mutex_lock(&philosopher->philo_mutex);
	philosopher->eat_count++;
	philosopher->time_since_last_meal = get_current_time();
	pthread_mutex_unlock(&philosopher->philo_mutex);
}
