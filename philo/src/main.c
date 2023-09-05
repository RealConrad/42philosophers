/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:39:15 by cwenz             #+#    #+#             */
/*   Updated: 2023/09/05 12:44:17 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


int	main(int argc, char **argv)
{
	t_simulation_state	*simulation_context;

	if (argc != 5 && argc != 6)
		return (printf("Invalid number of arguments.\n"), ERROR);
	simulation_context = malloc(sizeof(t_simulation_state));
	if (!simulation_context)
		return (free_simulation(&simulation_context, "Allocation failed.", true), ERROR);

	// Initialize philo's into linked list and setup mutex
	if (init_philos(&simulation_context, --argc, ++argv) != SUCCESS)
		return (ERROR);
	join_threads(&simulation_context);

	return (SUCCESS);
}
