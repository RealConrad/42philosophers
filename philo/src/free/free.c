/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:49:56 by cwenz             #+#    #+#             */
/*   Updated: 2023/10/13 13:52:53 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
 * @brief Frees memory and destroys all mutexes
 * @param simulation_context The context which holds all simulation related
 * 	data.
 */
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
