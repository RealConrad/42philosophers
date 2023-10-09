/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 17:30:50 by cwenz             #+#    #+#             */
/*   Updated: 2023/10/10 01:53:36 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"


void	kill_philoospher_processes(t_simulation_state *simulaiton_context)
{
	(void)simulaiton_context;
	// kill_and_free(simulaiton_context);
	// int	status;
	// int	i;

	// i = 0;
	// while (i < simulaiton_context->sim_data.philo_count)
	// {
	// 	waitpid(-1, &status, 0);
	// 	// if (WIFEXITED(status) || WIFSIGNALED(status))
	// 	if (status != 0)
	// 	{
	// 		kill_and_free(simulaiton_context);
	// 		return ;
	// 	}
	// 	i++;
	// }
}

void	kill_and_free(t_simulation_state *simulaiton_context)
{
	t_philosopher	*philosopher;

	philosopher = simulaiton_context->philosphers;
	sem_close(philosopher->sim_data->forks);
	sem_close(philosopher->sim_data->print);
	
	sem_unlink("/forks");
	sem_unlink("/print");
	printf("\033[31m\n\n------- KILLING PROCESSES! --------\n\033[0m \n");
	while (true)
	{
		kill(philosopher->pid, SIGKILL);
		sem_close(philosopher->philo_sem);
		sem_unlink(philosopher->sem_name);
		free(philosopher->sem_name);
		free(philosopher);	
	
		philosopher = philosopher->next;
		if (philosopher->next == simulaiton_context->philosphers)
			return ;
	}
}
