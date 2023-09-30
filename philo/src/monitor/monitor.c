/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 13:36:24 by cwenz             #+#    #+#             */
/*   Updated: 2023/09/30 17:32:53 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	monitor_philosophers(t_simulation_state *simulation_context)
{
	t_philosopher	*temp;

	temp = simulation_context->philosphers;
	pthread_mutex_unlock(&simulation_context->start_mutex);
	while (true)
	{
		temp = temp->next;
	}
}
