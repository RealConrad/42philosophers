/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 17:14:04 by cwenz             #+#    #+#             */
/*   Updated: 2023/10/10 10:59:24 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

static void	begin_simulation(t_philosopher *philosopher);
static void	handle_one_philosopher(t_philosopher *philosopher);
static void	handle_simulation(t_philosopher *philosopher);

int	create_philosopher_processes(t_simulation_state *simulation_context)
{
	t_philosopher	*philosopher;

	philosopher = simulation_context->philosphers;
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
	// sem_post(simulation_context->sim_data.print);
	return (SUCCESS);
}

static void	begin_simulation(t_philosopher *philosopher)
{
	pthread_t	t1;

	if (pthread_create(&t1, NULL, *monitor_philosopher, philosopher) != SUCCESS)
		return ;
	// pthread_detach(t1);
	if (philosopher->sim_data->philo_count == 1)
		handle_one_philosopher(philosopher);
	else
		handle_simulation(philosopher);
}

static void	handle_simulation(t_philosopher *philosopher)
{
	philosopher_think(philosopher);
	if (philosopher->index % 2 == ODD)
		wait_for_duration(1);
	while (!philosopher->exit_sim)
	{
		philosopher_eat(philosopher);
		philosopher_sleep(philosopher);
		philosopher_think(philosopher);
	}
}

static void	handle_one_philosopher(t_philosopher *philosopher)
{
	sem_wait(philosopher->sim_data->print);
	print_philosopher_state(philosopher, THINKING);
	print_philosopher_state(philosopher, TAKEN_FORK);
	wait_for_duration(philosopher->sim_data->time_to_die + 1);
	sem_post(philosopher->sim_data->print);
}
