/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 17:37:03 by cwenz             #+#    #+#             */
/*   Updated: 2023/09/29 18:07:27 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	handle_even_total_philosophers(t_philosopher *philosopher);
static void	handle_odd_total_philosophers(t_philosopher *philosopher);

void	*begin_simulation(void *arg)
{
	t_philosopher	*philosopher;
	int				is_even;

	philosopher = (t_philosopher *)arg;
	is_even = philosopher->sim_data->philo_count % 2 == EVEN;
	if (is_even)
		handle_even_total_philosophers(philosopher);
	else
		handle_odd_total_philosophers(philosopher);
	return (NULL);
}


static void	handle_even_total_philosophers(t_philosopher *philosopher)
{
	while (true)
	{
		if (philosopher->index % 2 == EVEN)
		{
			philosopher_eat(philosopher);
			philosopher_sleep(philosopher);
			philosopher_think(philosopher);
		}
		else
		{
			philosopher_sleep(philosopher);
			philosopher_eat(philosopher);
			philosopher_think(philosopher);
		}
	}
}

static void	handle_odd_total_philosophers(t_philosopher *philosopher)
{
	(void)philosopher;
}
