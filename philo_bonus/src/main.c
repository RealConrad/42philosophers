/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 12:46:03 by cwenz             #+#    #+#             */
/*   Updated: 2023/10/10 03:07:28 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	main(int argc, char **argv)
{
	t_simulation_state	simulation_context;

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

	sem_wait(simulation_context.sim_data.death);
	kill_and_free(&simulation_context);
	return (SUCCESS);
}
