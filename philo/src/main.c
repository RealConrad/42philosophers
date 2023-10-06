/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 12:46:03 by cwenz             #+#    #+#             */
/*   Updated: 2023/10/06 16:59:06 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_simulation_state	simulation_context = {0};

	if (argc != 5 && argc != 6)
		return (display_error(ERR_INVALID_ARG), ERROR);
	if (init_philos(&simulation_context, --argc, ++argv) != SUCCESS)
		return (ERROR);
	monitor_philosophers(&simulation_context);
	exit_all_threads(&simulation_context);
	pthread_mutex_unlock(&simulation_context.shared_mutex);
	join_threads(&simulation_context);
	free_memory(&simulation_context);
	// printf("\n\n\033[32mFinished simulation!\n\033[0m");
	return (SUCCESS);
}
