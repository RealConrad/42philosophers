/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 13:16:23 by cwenz             #+#    #+#             */
/*   Updated: 2023/09/06 14:18:20 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	init_philo_linked_list(t_simulation_state *simulation_context, char **argv);
static void add_philosopher_to_linked_list(t_simulation_state *simulation_context,
	t_philosopher *node);

int	init_philos(t_simulation_state *simulation_context, int argc, char **argv)
{
	if (!check_input(argc, argv))
		return (free_simulation(simulation_context, "Invalid arguments.", true), ERROR);
	
	simulation_context->forks = malloc(((int)atol(argv[0]) + 1) * sizeof(t_fork));
	if (!simulation_context->forks)
		return (free_simulation(simulation_context, "Failed to allocate memory for forks.", true),  ERROR);

	if (init_philo_linked_list(simulation_context, argv) != SUCCESS)
		return (free_simulation(simulation_context, "Failed to initialize philosopher linked list.", true),  ERROR);
	return (SUCCESS);
}

static int	init_philo_linked_list(t_simulation_state *simulation_context, char **argv)
{
	t_philosopher	*new_philosopher;
	int				i;

	i = 0;
	while (i < (int)atol(argv[0]))
	{
		new_philosopher = malloc(sizeof(t_philosopher));
		if (!new_philosopher)
			return (ERROR);
		if (init_mutex(simulation_context, i) != SUCCESS)
			return (ERROR);
		if (assign_new_philosopher_data(simulation_context, new_philosopher, i, argv) != SUCCESS)
			return (ERROR);
		add_philosopher_to_linked_list(simulation_context, new_philosopher);
		if (pthread_create(&new_philosopher->thread, NULL, *begin_simulation, new_philosopher) != SUCCESS)
			return (detach_threads(simulation_context), ERROR);
		i++;
	}
	return (SUCCESS);
}

static void add_philosopher_to_linked_list(t_simulation_state *simulation_context, t_philosopher *node)
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
		simulation_context->philosphers->prev = node;
	}
}
