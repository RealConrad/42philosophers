/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 16:15:46 by cwenz             #+#    #+#             */
/*   Updated: 2023/10/03 14:55:06 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	update_number_of_times_eaten(t_philosopher *philosopher);
static void	update_last_meal_time(t_philosopher *philosopher);

void	philosopher_eat(t_philosopher *philosopher)
{
	lock_forks(philosopher);
	pthread_mutex_lock(philosopher->print_mutex);
	print_philosopher_state(philosopher, EATING);
	pthread_mutex_unlock(philosopher->print_mutex);
	update_last_meal_time(philosopher);

	// if (check_philo_sim_exit(philosopher))
	// 	return (unlock_forks(philosopher));

	wait_for_duration(philosopher->sim_data.time_to_eat);
	update_number_of_times_eaten(philosopher);
	unlock_forks(philosopher);
}

void	philosopher_sleep(t_philosopher *philosopher)
{
	pthread_mutex_lock(philosopher->print_mutex);
	print_philosopher_state(philosopher, SLEEPING);
	pthread_mutex_unlock(philosopher->print_mutex);

	// if (check_philo_sim_exit(philosopher))
	// 	return ;
	wait_for_duration(philosopher->sim_data.time_to_sleep);
}

static void	update_number_of_times_eaten(t_philosopher *philosopher)
{
	pthread_mutex_lock(&philosopher->philo_mutex);
	philosopher->eat_count++;
	pthread_mutex_unlock(&philosopher->philo_mutex);
}

static void	update_last_meal_time(t_philosopher *philosopher)
{
	pthread_mutex_lock(&philosopher->philo_mutex);
	philosopher->time_since_last_meal = get_current_time();
	pthread_mutex_unlock(&philosopher->philo_mutex);
}
