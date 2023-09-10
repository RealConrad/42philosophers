/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:23:49 by cwenz             #+#    #+#             */
/*   Updated: 2023/09/10 12:37:50 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philosopher_try_eat(t_philosopher *philosopher)
{
	if (can_philosopher_eat(philosopher))
	{
		lock_forks(philosopher);
		change_philosopher_state(philosopher, EATING);
		print_philosopher_state(philosopher);
		wait_for_duration(philosopher->sim_data->time_to_eat);
		unlock_forks(philosopher);
	}
}

void	philosopher_sleep(t_philosopher *philosopher)
{
	change_philosopher_state(philosopher, SLEEPING);
	print_philosopher_state(philosopher);
	wait_for_duration(philosopher->sim_data->time_to_sleep);
}

void	philosopher_think(t_philosopher *philosopher)
{
	change_philosopher_state(philosopher, THINKING);
	print_philosopher_state(philosopher);
	wait_for_duration(philosopher->sim_data->time_to_sleep);
}