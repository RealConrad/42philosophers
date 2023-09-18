/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:39:15 by cwenz             #+#    #+#             */
/*   Updated: 2023/09/18 16:48:47 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_simulation_state	simulation_context = {0};

	if (argc != 5 && argc != 6)
		return (printf("Invalid number of arguments.\n"), ERROR);
	if (init_philos(&simulation_context, --argc, ++argv) != SUCCESS)
		return (free_simulation(&simulation_context, "Failed to initialize philosophers  ¯\\_(ツ)_/¯", true), ERROR);

	monitor_philosophers(&simulation_context, ++argc);
	detach_threads(&simulation_context);
	free_simulation(&simulation_context, "", false);
	// printf("Shutting down now.... ¯\\_(ツ)_/¯ \n");
	return (SUCCESS);
}
