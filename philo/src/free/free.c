/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:49:56 by cwenz             #+#    #+#             */
/*   Updated: 2023/10/06 16:33:00 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	free_memory(t_simulation_state *simulation_context)
{
	t_philosopher	*philosopher;
	t_philosopher	*next_philosopher;

	philosopher = simulation_context->philosphers;
	pthread_mutex_destroy(&simulation_context->shared_mutex);
	while (true)
	{
		next_philosopher = philosopher->next;
		pthread_mutex_destroy(philosopher->left_fork);
		pthread_mutex_destroy(&philosopher->philo_mutex);
		free(philosopher->left_fork);
		free(philosopher);
		philosopher = next_philosopher;
		if (philosopher == simulation_context->philosphers)
			return ;
	}
}
