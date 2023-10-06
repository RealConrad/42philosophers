/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 19:05:02 by cwenz             #+#    #+#             */
/*   Updated: 2023/10/06 16:53:14 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	join_threads(t_simulation_state *simulation_context)
{
	t_philosopher	*temp;

	temp = simulation_context->philosphers;
	while (true)
	{
		pthread_join(temp->thread, NULL);
		temp = temp->next;
		if (temp == simulation_context->philosphers)
			return ;
	}
}

bool	check_philo_sim_exit(t_philosopher *philosopher)
{
	bool	sim_exit_value;

	pthread_mutex_lock(&philosopher->philo_mutex);
	sim_exit_value = philosopher->exit_sim;
	pthread_mutex_unlock(&philosopher->philo_mutex);
	return (sim_exit_value);
}

void	exit_all_threads(t_simulation_state *simulation_context)
{
	t_philosopher	*philosopher;

	philosopher = simulation_context->philosphers;
	while (true)
	{
		pthread_mutex_lock(&philosopher->philo_mutex);
		philosopher->exit_sim = true;
		pthread_mutex_unlock(&philosopher->philo_mutex);
		philosopher = philosopher->next;
		if (philosopher == simulation_context->philosphers)
			return ;
	}
}

void	display_error(t_error_type error_type)
{
	if (error_type == ERR_MUTEX_INITIALIZATION)
		printf("Error:\nFailed to initialize mutexes.\n");
	else if (error_type == ERR_INVALID_ARG)
		printf("Error:\nInvalid command line arguments.\n");
	else if (error_type == ERR_MEMORY_ALLOCATION)
		printf("Error:\nMalloc call failed.\n");
	else if (error_type == ERR_THREAD_CREATION)
		printf("Error:\nFailed to create threads.\n");
}
