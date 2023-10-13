/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 16:15:46 by cwenz             #+#    #+#             */
/*   Updated: 2023/10/13 13:27:56 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
 * @brief Handles philosophers eating. It locks the forks, calls the function
 * 	to update eating information, prints out philosopher states and waits for
 * 	`time_to_eat` and finally unlocks the forks.
 * @param philosopher The philisopher to eat.
 */
void	philosopher_eat(t_philosopher *philosopher)
{
	lock_forks(philosopher);
	pthread_mutex_lock(philosopher->shared_mutex);
	print_philosopher_state(philosopher, TAKEN_FORK);
	print_philosopher_state(philosopher, TAKEN_FORK);
	print_philosopher_state(philosopher, EATING);
	pthread_mutex_unlock(philosopher->shared_mutex);
	update_philo_eat_data(philosopher);
	wait_for_duration(philosopher->sim_data.time_to_eat);
	unlock_forks(philosopher);
}

/**
 * @brief Handles a philosopher sleeping. Prints out the sleeping state
 * 	and waits `time_to_sleep`
 * @param philosopher The philosopher to be sleeping
 */
void	philosopher_sleep(t_philosopher *philosopher)
{
	pthread_mutex_lock(philosopher->shared_mutex);
	print_philosopher_state(philosopher, SLEEPING);
	pthread_mutex_unlock(philosopher->shared_mutex);
	wait_for_duration(philosopher->sim_data.time_to_sleep);
}

/**
 * @brief Updates the number of times a philosopher has eaten and
 * 	saves the time when the philosopher started eating.
 * @param philosopher The philosopher whose eat information to be
 * 	updated.
 */
void	update_philo_eat_data(t_philosopher *philosopher)
{
	pthread_mutex_lock(&philosopher->philo_mutex);
	philosopher->eat_count++;
	philosopher->time_since_last_meal = get_current_time();
	pthread_mutex_unlock(&philosopher->philo_mutex);
}

/**
 * @brief Prints out the philosopher thinking state
 * @param philosopher The philosopher to be thinking
 */
void	philosopher_think(t_philosopher *philosopher)
{
	pthread_mutex_lock(philosopher->shared_mutex);
	print_philosopher_state(philosopher, THINKING);
	pthread_mutex_unlock(philosopher->shared_mutex);
}

void	philosopher_normal_routine(t_philosopher *philosopher)
{
	philosopher_eat(philosopher);
	philosopher_sleep(philosopher);
	philosopher_think(philosopher);
}
