/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 13:16:23 by cwenz             #+#    #+#             */
/*   Updated: 2023/09/05 16:31:59 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	init_philo_linked_list(t_simulation_state *simulation_context);
static void	add_node_to_end(t_simulation_state *simulation_context, t_philosopher *node);

int	init_philos(t_simulation_state *simulation_context, int argc, char **argv)
{
	int			i;

	i = 0;
	if (!check_input(argc, argv))
		return (free_simulation(simulation_context, "Invalid arguments.", true), ERROR);
	simulation_context->philo_count = (int)atol(argv[0]);
	simulation_context->time_to_die = (int)atol(argv[1]);
	simulation_context->time_to_eat = (int)atol(argv[2]);
	simulation_context->time_to_sleep = (int)atol(argv[3]);
	if (argv[4])
		simulation_context->required_eat_times = (int)atol(argv[4]);

	// Allocate for mutexes (forks)
	simulation_context->forks = malloc((simulation_context->philo_count + 1) * sizeof(t_fork));
	if (!simulation_context->forks)
		return (free_simulation(simulation_context, "Failed to allocate for forks.", true), ERROR);
	// Add philo's into linked list
	if (init_philo_linked_list(simulation_context) != SUCCESS)
		return (free_simulation(simulation_context, "Failed to initialize philosopher linked list.", true),  ERROR);
	return (SUCCESS);
}

static int	init_philo_linked_list(t_simulation_state *simulation_context)
{
	t_philosopher	*new_philosopher;
	int				i;

	i = 0;
	while (i < simulation_context->philo_count)
	{
		new_philosopher = malloc(sizeof(t_philosopher));
		if (!new_philosopher)
			return (ERROR);
		if (init_mutex(simulation_context, i) != SUCCESS)
			return (ERROR);
		assign_new_philosopher(simulation_context, new_philosopher, i);
		if (!simulation_context->philosphers)
		{
			new_philosopher->next = new_philosopher;
			new_philosopher->prev = new_philosopher;
			simulation_context->philosphers = new_philosopher;
		}
		else
			add_node_to_end(simulation_context, new_philosopher);
		if (pthread_create(&new_philosopher->thread, NULL, *begin_simulation, NULL) != 0)
			return (detach_threads(&simulation_context), ERROR);
		i++;
	}
	return (SUCCESS);
}

static void	add_node_to_end(t_simulation_state *simulation_context, t_philosopher *node)
{
	t_philosopher	*tail;

	tail = simulation_context->philosphers->prev;
	tail->next = node;
	node->prev = tail;
	node->next = simulation_context->philosphers;
	simulation_context->philosphers->prev = node;
}
