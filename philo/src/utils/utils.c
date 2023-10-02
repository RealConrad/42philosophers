/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 19:05:02 by cwenz             #+#    #+#             */
/*   Updated: 2023/10/01 19:08:07 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	detach_threads(t_simulation_state *simulation_context)
{
	t_philosopher *temp;

	temp = simulation_context->philosphers;
	while (true)
	{
		// printf("--------------- Philo [%d] ate: %d\n", temp->index, temp->eat_count);
		temp = temp->next;
		if (temp->thread)
			pthread_detach(temp->thread);
		if (temp == simulation_context->philosphers)
			break;
	}
}
