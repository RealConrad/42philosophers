/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_simulation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:03:03 by cwenz             #+#    #+#             */
/*   Updated: 2023/09/16 15:03:30 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	free_philo_linked_list(t_philosopher *philosopher);

void	free_simulation(t_simulation_state *simulation_context, const char *msg, bool display_error)
{
	if (display_error)
		printf("Error:\n%s\n", msg);
	free_philo_linked_list(simulation_context->philosphers);
	free(simulation_context->forks);
}

static void	free_philo_linked_list(t_philosopher *philosopher)
{
	t_philosopher	*temp;
	
	temp = philosopher;
	while (true)
	{
		free(temp->sim_data);
		free(temp);
		temp = temp->next;
		if (temp == philosopher)
			break ;
	}
}
