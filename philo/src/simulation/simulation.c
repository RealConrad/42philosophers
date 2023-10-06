/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:06:01 by cwenz             #+#    #+#             */
/*   Updated: 2023/10/06 18:22:51 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	handle_simulation(t_philosopher *philosopher);
static void	handle_one_philosopher(t_philosopher *philosopher);

void	*begin_simulation(void *arg)
{
	t_philosopher	*philosopher;

	philosopher = (t_philosopher *)arg;
	pthread_mutex_lock(philosopher->shared_mutex);
	pthread_mutex_unlock(philosopher->shared_mutex);
	if (philosopher->sim_data.philo_count == 1)
		handle_one_philosopher(philosopher);
	else
		handle_simulation(philosopher);
	return (NULL);
}

static void	handle_simulation(t_philosopher *philosopher)
{
	philosopher_think(philosopher);
	if (philosopher->index % 2 == ODD)
	{
		philosopher_eat(philosopher); 
		philosopher_sleep(philosopher);
		philosopher_think(philosopher);
	}
	else
	{
		philosopher_sleep(philosopher);
		philosopher_think(philosopher);
	}
	while (true)
	{
		if (check_philo_sim_exit(philosopher))
			return ;
		philosopher_eat(philosopher);
		philosopher_sleep(philosopher);
		philosopher_think(philosopher);
	}
}

static void	handle_one_philosopher(t_philosopher *philosopher)
{
	philosopher_think(philosopher);
	pthread_mutex_lock(philosopher->left_fork);
	print_philosopher_state(philosopher, TAKEN_FORK);
	wait_for_duration(philosopher->sim_data.time_to_die);
	pthread_mutex_unlock(philosopher->left_fork);
}