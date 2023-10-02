/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 16:15:46 by cwenz             #+#    #+#             */
/*   Updated: 2023/10/01 18:34:21 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	update_number_of_times_eaten(t_philosopher *philosopher);
static void	update_last_meal_time(t_philosopher *philosopher);

void	philosopher_eat(t_philosopher *philosopher)
{
	lock_forks(philosopher);
	print_philosopher_state(philosopher, EATING);
	update_last_meal_time(philosopher);
	wait_for_duration(philosopher->sim_data.time_to_eat);
	update_number_of_times_eaten(philosopher);
	unlock_forks(philosopher);
}

void	philosopher_sleep(t_philosopher *philosopher)
{
	print_philosopher_state(philosopher, SLEEPING);
	wait_for_duration(philosopher->sim_data.time_to_sleep);
}

static void	update_number_of_times_eaten(t_philosopher *philosopher)
{
	pthread_mutex_lock(&philosopher->eat_count_mutex);
	philosopher->eat_count++;
	pthread_mutex_unlock(&philosopher->eat_count_mutex);
}

static void	update_last_meal_time(t_philosopher *philosopher)
{
	pthread_mutex_lock(&philosopher->time_since_last_meal_mutex);
	philosopher->time_since_last_meal = get_current_time();
	pthread_mutex_unlock(&philosopher->time_since_last_meal_mutex);
}
