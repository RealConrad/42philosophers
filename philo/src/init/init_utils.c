/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 13:08:32 by cwenz             #+#    #+#             */
/*   Updated: 2023/10/13 13:52:17 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
 * @brief Adds the given node to the end of the linked list
 * @param simulation_context The context which holds the linked list
 * @param node The node to be added to the end of the linked list
 */
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
