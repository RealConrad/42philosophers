/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 13:08:32 by cwenz             #+#    #+#             */
/*   Updated: 2023/10/06 16:35:49 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	add_philosopher_to_linked_list(t_simulation_state *simulation_context,
		t_philosopher *node)
{
	t_philosopher	*tail;

	if (!simulation_context->philosphers)
	{
		node->next = node;
		node->prev = node;
		simulation_context->philosphers = node;
	}
	else
	{
		tail = simulation_context->philosphers->prev;
		tail->next = node;
		node->prev = tail;
		node->next = simulation_context->philosphers;
		node->right_fork = tail->left_fork;
		if (node->index == node->sim_data.philo_count)
			node->next->right_fork = node->left_fork;
		simulation_context->philosphers->prev = node;
	}
}
