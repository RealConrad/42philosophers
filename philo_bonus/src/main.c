/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 12:46:03 by cwenz             #+#    #+#             */
/*   Updated: 2023/10/10 03:54:34 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

static void	*monitor_eat_count(void *arg);

int	main(int argc, char **argv)
{
	t_simulation_state	simulation_context;
	pthread_t			t1;

	sem_unlink("/philo_sem_1");
	sem_unlink("/philo_sem_2");
	if (argc != 5 && argc != 6)
		return (display_error(ERR_INVALID_ARG), ERROR);
		
	if (init_sim_data(&simulation_context.sim_data, --argc, ++argv) != SUCCESS)
		return (ERROR);
	if (init_philos(&simulation_context) != SUCCESS)
		return (ERROR);
	if (create_philosopher_processes(&simulation_context) != SUCCESS)
		return (ERROR);

	sem_wait(simulation_context.sim_data.exit_program);
	if (simulation_context.sim_data.required_eat_times)
		pthread_create(&t1, NULL, *monitor_eat_count, &simulation_context);
	sem_wait(simulation_context.sim_data.exit_program);
	if (simulation_context.sim_data.required_eat_times)
		pthread_detach(t1);
	kill_and_free(&simulation_context);
	return (SUCCESS);
}

static void	*monitor_eat_count(void *arg)
{
	t_simulation_state *simulation_context;
	int					eat_counter;

	simulation_context = (t_simulation_state *)arg;
	eat_counter = 0;
	while (eat_counter < simulation_context->sim_data.philo_count)
	{
		sem_wait(simulation_context->sim_data.is_done_eating);
		eat_counter++;
	}
	sem_wait(simulation_context->sim_data.print);
	sem_post(simulation_context->sim_data.exit_program);
	return (NULL);
}
