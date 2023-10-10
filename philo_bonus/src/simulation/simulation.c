/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 17:14:04 by cwenz             #+#    #+#             */
/*   Updated: 2023/10/10 03:10:11 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

static void	begin_simulation(t_philosopher *philosopher);
static void	handle_simulation(t_philosopher *philosopher);

int	create_philosopher_processes(t_simulation_state *simulation_context)
{
	t_philosopher	*philosopher;

	philosopher = simulation_context->philosphers;
	sem_wait(simulation_context->sim_data.print);
	sem_wait(simulation_context->sim_data.death);
	simulation_context->start_time_ms = get_current_time();
	while (true)
	{
		philosopher->pid = fork();
		if (philosopher->pid < 0)
			return (display_error(ERR_FORK_INITIALIZATION), ERROR);
		else if (philosopher->pid == 0)
			begin_simulation(philosopher);
		philosopher = philosopher->next;
		if (philosopher == simulation_context->philosphers)
			break ;
	}
	sem_post(simulation_context->sim_data.print);
	return (SUCCESS);
}

static void	begin_simulation(t_philosopher *philosopher)
{
	pthread_t	t1;

	sem_wait(philosopher->sim_data->print);
	sem_post(philosopher->sim_data->print);

	philosopher->time_since_last_meal = get_current_time();
	if (pthread_create(&t1, NULL, *monitor_philosopher, philosopher) != SUCCESS)
		return ;
	pthread_detach(t1);
	
	handle_simulation(philosopher);
}

static void	handle_simulation(t_philosopher *philosopher)
{
	philosopher_think(philosopher);
	if (philosopher->index % 2 == ODD)
		wait_for_duration(3);
	while (!philosopher->exit_sim)
	{
		philosopher_eat(philosopher);
		philosopher_sleep(philosopher);
		philosopher_think(philosopher);
	}
}


	// if (philosopher->index % 2 == ODD)
	// {
	// 	philosopher_eat(philosopher);
	// 	philosopher_sleep(philosopher);
	// 	philosopher_think(philosopher);
	// }
	// else
	// {
	// 	philosopher_sleep(philosopher);
	// 	philosopher_think(philosopher);
	// }