/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 13:16:23 by cwenz             #+#    #+#             */
/*   Updated: 2023/09/03 16:05:22 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static bool	init_philo_linked_list(t_simulation_state **simulation_context);
static void	add_node_to_end(t_simulation_state **simulation_context, t_philosopher *node);

int	init_philosophers(t_simulation_state **simulation_context, int argc, char **argv)
{
	int	i;

	i = 0;
	if (!check_input(argc, argv))
	{
		print_error_message("Invalid arguments.");
		return (ERROR);
	}
	(*simulation_context)->philo_count = (int)atol(argv[0]);
	(*simulation_context)->time_to_die = (int)atol(argv[1]);
	(*simulation_context)->time_to_eat = (int)atol(argv[2]);
	(*simulation_context)->time_to_sleep = (int)atol(argv[3]);
	if (argv[4])
		(*simulation_context)->required_eat_times = (int)atol(argv[4]);

	if (!init_philo_linked_list(simulation_context))
	{
		print_error_message("Failed to initialize philosophers into linked list.");
		return (ERROR);
	}
	return (SUCCESS);
}

static bool	init_philo_linked_list(t_simulation_state **simulation_context)
{
	t_philosopher	*new_philosopher;
	int				i;

	i = 0;
	while (i < (*simulation_context)->philo_count)
	{
		new_philosopher = malloc(sizeof(t_philosopher));
		if (!new_philosopher)
			return (false);
		new_philosopher->index = i;
		if (!(*simulation_context)->philosphers)
		{
			new_philosopher->next = new_philosopher;
			new_philosopher->prev = new_philosopher;
			(*simulation_context)->philosphers = new_philosopher;
		}
		else
			add_node_to_end(simulation_context, new_philosopher);
		i++;
	}
	return (true);
}

static void	add_node_to_end(t_simulation_state **simulation_context, t_philosopher *node)
{
	t_philosopher	*tail;

	tail = (*simulation_context)->philosphers->prev;
	tail->next = node;
	node->prev = tail;
	node->next = (*simulation_context)->philosphers;
	(*simulation_context)->philosphers->prev = node;
}
