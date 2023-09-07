/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:23:49 by cwenz             #+#    #+#             */
/*   Updated: 2023/09/07 17:34:55 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philosopher_try_eat(t_philosopher *philosopher)
{
	if (can_philosopher_eat(philosopher))
	{
		lock_forks(philosopher);
		philosopher->state = EATING;
		print_philosopher_state(philosopher);
		sleep(2);
		unlock_forks(philosopher);
	}
}

void	philosopher_sleep(t_philosopher *philosopher)
{
	philosopher->state = SLEEPING;
	print_philosopher_state(philosopher);
	sleep(1);
}

void	philosopher_think(t_philosopher *philosopher)
{
	philosopher->state = THINKING;
	print_philosopher_state(philosopher);
	sleep(1);
}
