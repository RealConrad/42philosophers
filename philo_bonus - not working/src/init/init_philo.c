/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 14:44:20 by cwenz             #+#    #+#             */
/*   Updated: 2023/10/10 10:49:45 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

static void	add_philosopher_to_linked_list(
				t_simulation_state *simulaiton_context,
				t_philosopher *philosopher);

int	init_philos(t_simulation_state *simulaiton_context)
{
	int				i;
	t_philosopher	*philosopher;

	i = 1;
	while (i <= (int)simulaiton_context->sim_data.philo_count)
	{
		philosopher = malloc(sizeof(t_philosopher));
		if (!philosopher)
			return (display_error(ERR_MEMORY_ALLOCATION), ERROR);
		philosopher->eat_count = 0;
		philosopher->pid = -1;
		philosopher->index = i;
		philosopher->sim_data = &simulaiton_context->sim_data;
		philosopher->start_time_ms = &simulaiton_context->start_time_ms;
		philosopher->time_since_last_meal = get_current_time();
		philosopher->exit_sim = false;
		philosopher->sem_name = strjoin("/philo_sem_", i);
		philosopher->philo_sem = sem_open(philosopher->sem_name, O_CREAT, 0644, 1);
		// if (!philosopher->philo_sem)
		// 	exit(0);
		add_philosopher_to_linked_list(simulaiton_context, philosopher);
		i++;
	}
	return (SUCCESS);
}

static void	add_philosopher_to_linked_list(
				t_simulation_state *simulaiton_context,
				t_philosopher *node)
{
	t_philosopher	*tail;

	if (!simulaiton_context->philosphers)
	{
		node->next = node;
		node->prev = node;
		simulaiton_context->philosphers = node;
	}
	else
	{
		tail = simulaiton_context->philosphers->prev;
		tail->next = node;
		node->prev = tail;
		node->next = simulaiton_context->philosphers;
		simulaiton_context->philosphers->prev = node;
	}
}
