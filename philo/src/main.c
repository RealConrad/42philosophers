/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 12:46:03 by cwenz             #+#    #+#             */
/*   Updated: 2023/10/02 15:40:19 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_simulation_state	simulation_context = {0};

	if (argc != 5 && argc != 6)
		return (printf("Invalid number of arguments.\n"), ERROR);
	if (init_philos(&simulation_context, --argc, ++argv) != SUCCESS)
		return (ERROR);

	monitor_philosophers(&simulation_context);
	join_threads(&simulation_context);
	pthread_mutex_unlock(&simulation_context.print_mutex);
	printf("exit sim %d ? %s\n", simulation_context.philosphers->index, simulation_context.philosphers->exit_sim == true ? "true":"false");
	return (SUCCESS);
}
