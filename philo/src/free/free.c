/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:49:56 by cwenz             #+#    #+#             */
/*   Updated: 2023/10/03 16:59:35 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	free_memory(t_simulation_state *simulation_context, const char *error_msg, bool display_error)
{
	t_philosopher	*philosopher;
	t_philosopher	*next_philosopher;
	int				i;

	i = 0;
	philosopher = simulation_context->philosphers;
	if (display_error)
		printf("Error:\n%s\n", error_msg);
	pthread_mutex_destroy(&simulation_context->shared_mutex);
	while (i < philosopher->sim_data.philo_count)
	{
		pthread_mutex_destroy(&simulation_context->forks[i].mutex);
		i++;
	}
	free(simulation_context->forks);
	while (true)
	{
		next_philosopher = philosopher->next;
		free(philosopher);
		philosopher = next_philosopher;
		if (philosopher == simulation_context->philosphers)
			return ;
	}
}
