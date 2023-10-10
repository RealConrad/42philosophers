/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 17:30:50 by cwenz             #+#    #+#             */
/*   Updated: 2023/10/10 04:57:20 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	kill_and_free(t_simulation_state *simulaiton_context)
{
	t_philosopher	*philosopher;
	t_philosopher	*next_philosopher;

	philosopher = simulaiton_context->philosphers;
	sem_close(philosopher->sim_data->forks);
	sem_close(philosopher->sim_data->print);
	sem_close(philosopher->sim_data->is_done_eating);
	sem_close(philosopher->sim_data->exit_program);
	
	sem_unlink("/forks");
	sem_unlink("/print");
	sem_unlink("/is_done_eating");
	sem_unlink("/exit_program");
	// printf("\033[31m\n\n------- KILLING PROCESSES! --------\n\033[0m \n");
	while (true)
	{
		next_philosopher = philosopher->next;
		kill(philosopher->pid, SIGKILL);
		sem_close(philosopher->philo_sem);
		sem_unlink(philosopher->sem_name);
		free(philosopher->sem_name);
		free(philosopher);

		philosopher = next_philosopher;
		if (philosopher == simulaiton_context->philosphers)
			return ;
	}
}
