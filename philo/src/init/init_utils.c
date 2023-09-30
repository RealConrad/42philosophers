/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 13:08:32 by cwenz             #+#    #+#             */
/*   Updated: 2023/09/30 14:04:29 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void add_philosopher_to_linked_list(t_simulation_state *simulation_context, t_philosopher *node)
{
	t_philosopher *tail;

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
		simulation_context->philosphers->prev = node;
	}
}

int	init_forks(t_simulation_state *simulation_context, char **argv)
{
	int	i;

	i = 0;
	simulation_context->forks = malloc(atol(argv[0]) * sizeof(t_fork));
	if (!simulation_context->forks)
		return (ERROR);
	
	while (i < atol(argv[0]))
	{
		pthread_mutex_init(&simulation_context->forks[i].mutex, NULL);
		i++;
	}
	return (SUCCESS);
}