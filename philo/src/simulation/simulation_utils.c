/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 16:15:46 by cwenz             #+#    #+#             */
/*   Updated: 2023/10/01 16:52:00 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philosopher_eat(t_philosopher *philosopher)
{
	lock_forks(philosopher);
	print_philosopher_state(philosopher, EATING);
	
	update_number_of_times_eaten(philosopher);
	
	wait_for_duration(philosopher->sim_data.time_to_eat);
	unlock_forks(philosopher);
}

void	philosopher_sleep(t_philosopher *philosopher)
{
	print_philosopher_state(philosopher, SLEEPING);
	wait_for_duration(philosopher->sim_data.time_to_sleep);
}

void	update_number_of_times_eaten(t_philosopher *philosopher)
{
	pthread_mutex_lock(&philosopher->eat_count_mutex);
	philosopher->eat_count++;
	pthread_mutex_unlock(&philosopher->eat_count_mutex);
}