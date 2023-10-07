/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:06:01 by cwenz             #+#    #+#             */
/*   Updated: 2023/10/07 15:19:45 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	handle_simulation(t_philosopher *philosopher);
static void	handle_one_philosopher(t_philosopher *philosopher);
static void	handle_three_philosophers(t_philosopher *philosopher);

void	*begin_simulation(void *arg)
{
	t_philosopher	*philosopher;

	philosopher = (t_philosopher *)arg;
	pthread_mutex_lock(philosopher->shared_mutex);
	pthread_mutex_unlock(philosopher->shared_mutex);
	philosopher->time_since_last_meal = get_current_time();
	if (philosopher->sim_data.philo_count == 1)
		handle_one_philosopher(philosopher);
	else if (philosopher->sim_data.philo_count == 3)
		handle_three_philosophers(philosopher);
	else
		handle_simulation(philosopher);
	return (NULL);
}

static void	handle_simulation(t_philosopher *philosopher)
{
	philosopher_think(philosopher);
	if (philosopher->index == 3)
		wait_for_duration(1);
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
	pthread_mutex_lock(philosopher->shared_mutex);
	print_philosopher_state(philosopher, TAKEN_FORK);
	pthread_mutex_unlock(philosopher->shared_mutex);
	wait_for_duration(philosopher->sim_data.time_to_die);
	pthread_mutex_unlock(philosopher->left_fork);
}

static void	handle_three_philosophers(t_philosopher *philosopher)
{
	philosopher_think(philosopher);
	if (philosopher->index == 3)
		wait_for_duration(5);
	while (true)
	{
		if (check_philo_sim_exit(philosopher))
			return ;
		if (philosopher->index == 1)
		{
			philosopher_eat(philosopher);
			philosopher_sleep(philosopher);
			philosopher_think(philosopher);
		}
		else if (philosopher->index == 2)
		{
			philosopher_sleep(philosopher);
			philosopher_think(philosopher);
			philosopher_eat(philosopher);
		}
		else if (philosopher->index == 3)
			philosopher_normal_routine(philosopher);
	}
}
