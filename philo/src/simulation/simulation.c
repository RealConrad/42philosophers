/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:06:01 by cwenz             #+#    #+#             */
/*   Updated: 2023/10/03 16:58:41 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	handle_odd_total(t_philosopher *philosopher);
static void	handle_even_total(t_philosopher *philosopher);

void	*begin_simulation(void *arg)
{
	t_philosopher	*philosopher;
	bool			is_even;
	long long		time;

	philosopher = (t_philosopher *)arg;
	is_even = philosopher->sim_data.philo_count % 2 == EVEN;
	pthread_mutex_lock(philosopher->shared_mutex);
	pthread_mutex_unlock(philosopher->shared_mutex);
	time = get_current_time();
	philosopher->start_time_ms = time;
	philosopher->time_since_last_meal = time;
	if (is_even)
		handle_even_total(philosopher);
	else
		handle_odd_total(philosopher);
	return (NULL);
}

static void	handle_even_total(t_philosopher *philosopher)
{
	while (true)
	{
		if (check_philo_sim_exit(philosopher))
			return ;
		if (philosopher->index % 2 == EVEN)
		{
			philosopher_eat(philosopher);
			philosopher_sleep(philosopher);

			pthread_mutex_lock(philosopher->shared_mutex);
			print_philosopher_state(philosopher, THINKING);
			pthread_mutex_unlock(philosopher->shared_mutex);
		}
		else
		{
			philosopher_sleep(philosopher);
			philosopher_eat(philosopher);

			pthread_mutex_lock(philosopher->shared_mutex);
			print_philosopher_state(philosopher, THINKING);
			pthread_mutex_unlock(philosopher->shared_mutex);
		}
	}
}

static void	handle_odd_total(t_philosopher *philosopher)
{
	(void)philosopher;
}
