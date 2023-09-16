/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 13:16:23 by cwenz             #+#    #+#             */
/*   Updated: 2023/09/16 17:28:57 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int init_philo_linked_list(t_simulation_state *simulation_context, char **argv);
static void add_philosopher_to_linked_list(t_simulation_state *simulation_context,
											t_philosopher *node);

int	init_philos(t_simulation_state *simulation_context, int argc, char **argv)
{
	if (!check_input(argc, argv))
		return (ERROR);

	simulation_context->forks = malloc((atol(argv[0]) + 1) * sizeof(t_fork));
	if (!simulation_context->forks)
		return (ERROR);

	if (init_philo_linked_list(simulation_context, argv) != SUCCESS)
		return (ERROR);
	return (SUCCESS);
}

static int	init_philo_linked_list(t_simulation_state *simulation_context, char **argv)
{
	t_philosopher 	*new_philosopher;
	long long		start_time_ms;
	int 			i;

	i = 0;
	start_time_ms = get_current_time();
	while (i < (int)atol(argv[0]))
	{
		new_philosopher = malloc(sizeof(t_philosopher));
		if (!new_philosopher)
			return (ERROR);
		new_philosopher->start_time_ms = start_time_ms;
		if (init_mutex(simulation_context, i) != SUCCESS)
			return (ERROR);
		if (assign_new_philosopher_data(simulation_context, new_philosopher, i, argv) != SUCCESS)
			return (ERROR);
		add_philosopher_to_linked_list(simulation_context, new_philosopher);
		if (pthread_create(&new_philosopher->thread, NULL, *begin_simulation, new_philosopher) != SUCCESS)
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}

static void add_philosopher_to_linked_list(t_simulation_state *simulation_context, t_philosopher *node)
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
