/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 13:16:23 by cwenz             #+#    #+#             */
/*   Updated: 2023/09/04 15:22:35 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static bool	init_philo_linked_list(t_simulation_state **simulation_context);
static void	add_node_to_end(t_simulation_state **simulation_context, t_philosopher *node);

int	init_philos(t_simulation_state **simulation_context, int argc, char **argv)
{
	int			i;

	i = 0;
	if (!check_input(argc, argv))
		return (free_simulation(simulation_context, "Invalid arguments."), ERROR);
	(*simulation_context)->philo_count = (int)atol(argv[0]);
	(*simulation_context)->time_to_die = (int)atol(argv[1]);
	(*simulation_context)->time_to_eat = (int)atol(argv[2]);
	(*simulation_context)->time_to_sleep = (int)atol(argv[3]);
	if (argv[4])
		(*simulation_context)->required_eat_times = (int)atol(argv[4]);

	// Allocate for mutexes (forks)
	(*simulation_context)->forks = malloc((*simulation_context)->philo_count * sizeof(t_fork));
	if (!(*simulation_context)->forks)
		return (print_error_message("Allocation failed for forks."), ERROR);

	// Add philo's into linked list
	if (!init_philo_linked_list(simulation_context))
		return (print_error_message("Failed to initialize philosophers."), ERROR);
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
		new_philosopher->time_since_last_meal = 0;
		
		// create mutex
		pthread_mutex_init(&(*simulation_context)->forks[i].mutex, NULL);
		(*simulation_context)->forks[i].id = i;
		(*simulation_context)->forks[i].in_use = false;
		new_philosopher->left_fork = &(*simulation_context)->forks[i];
		new_philosopher->right_fork = &(*simulation_context)->forks[(i + 1) % (*simulation_context)->philo_count];

		if (!(*simulation_context)->philosphers)
		{
			new_philosopher->next = new_philosopher;
			new_philosopher->prev = new_philosopher;
			(*simulation_context)->philosphers = new_philosopher;
		}
		else
			add_node_to_end(simulation_context, new_philosopher);
		if (pthread_create(&new_philosopher->thread, NULL, *begin_simulation, NULL) != 0)
			return (detach_threads(simulation_context), ERROR);
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
