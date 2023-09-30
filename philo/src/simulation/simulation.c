/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:06:01 by cwenz             #+#    #+#             */
/*   Updated: 2023/09/30 17:47:53 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	handle_odd_total(t_philosopher *philosopher);
static void	handle_even_total(t_philosopher *philosopher);

void	*begin_simulation(void *arg)
{
	t_philosopher	*philosopher;
	bool			is_even;

	philosopher = (t_philosopher *)arg;
	is_even = philosopher->sim_data.philo_count % 2 == EVEN;
	pthread_mutex_lock(philosopher->start_mutex);
	pthread_mutex_unlock(philosopher->start_mutex);
	philosopher->start_time_ms = get_current_time();
	if (is_even)
		handle_even_total(philosopher);
	else
		handle_odd_total(philosopher);
	return (NULL);
}

static void	handle_even_total(t_philosopher *philosopher)
{
	while (!philosopher->exit_sim)
	{
		if (philosopher->index % 2 == EVEN)
		{
			philosopher_eat(philosopher);
			philosopher_sleep(philosopher);
			print_philosopher_state(philosopher, THINKING);
		}
		else
		{
			philosopher_sleep(philosopher);
			philosopher_eat(philosopher);
			print_philosopher_state(philosopher, THINKING);
		}
	}
}

static void	handle_odd_total(t_philosopher *philosopher)
{
	(void)philosopher;
}
