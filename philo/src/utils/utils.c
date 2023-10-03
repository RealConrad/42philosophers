/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 19:05:02 by cwenz             #+#    #+#             */
/*   Updated: 2023/10/03 16:51:21 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	detach_threads(t_simulation_state *simulation_context)
{
	t_philosopher *temp;

	temp = simulation_context->philosphers;
	while (true)
	{
		temp = temp->next;
		if (temp->thread)
			pthread_detach(temp->thread);
		if (temp == simulation_context->philosphers)
			break;
	}
}

void	join_threads(t_simulation_state *simulation_context)
{
	t_philosopher	*temp;

	temp = simulation_context->philosphers;
	while (true)
	{
		printf("Philo[%d] joining...\n", temp->index);
		if (temp->thread)
			pthread_join(temp->thread, NULL);
		temp = temp->next;
		if (temp == simulation_context->philosphers)
			return ;
	}
}

bool	check_philo_sim_exit(t_philosopher *philosopher)
{
	bool	sim_exit_value;
	
	pthread_mutex_lock(&philosopher->exit_sim_mutex);
	sim_exit_value = philosopher->exit_sim;
	pthread_mutex_unlock(&philosopher->exit_sim_mutex);
	return (sim_exit_value);
}

void	exit_all_threads(t_simulation_state *simulation_context)
{
	t_philosopher	*philosopher;

	philosopher = simulation_context->philosphers;
	while (true)
	{
		pthread_mutex_lock(&philosopher->exit_sim_mutex);
		philosopher->exit_sim = true;
		pthread_mutex_unlock(&philosopher->exit_sim_mutex);
		philosopher = philosopher->next;
		if (philosopher == simulation_context->philosphers)
			return ;
	}
}
