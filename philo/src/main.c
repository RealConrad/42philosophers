/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 12:46:03 by cwenz             #+#    #+#             */
/*   Updated: 2023/10/07 14:23:10 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/* 
Death Time (Even): time_to_eat + time_to_sleep + 10
Death Time (Odd): (time_to_eat * 2) + time_to_sleep + 10
*/
int	main(int argc, char **argv)
{
	t_simulation_state	simulation_context;

	if (argc != 5 && argc != 6)
		return (display_error(ERR_INVALID_ARG), ERROR);
	simulation_context.start_time_ms = 0;
	simulation_context.num_finished_eating = 0;
	simulation_context.philosphers = NULL;
	if (pthread_mutex_init(&simulation_context.shared_mutex, NULL) != SUCCESS)
		return (display_error(ERR_MUTEX_INITIALIZATION), ERROR);
	pthread_mutex_lock(&simulation_context.shared_mutex);
	if (init_philos(&simulation_context, --argc, ++argv) != SUCCESS)
	{
		pthread_mutex_unlock(&simulation_context.shared_mutex);
		pthread_mutex_destroy(&simulation_context.shared_mutex);
		return (ERROR);
	}
	monitor_philosophers(&simulation_context);
	exit_all_threads(&simulation_context);
	pthread_mutex_unlock(&simulation_context.shared_mutex);
	join_threads(&simulation_context);
	free_memory(&simulation_context);
	return (SUCCESS);
}
