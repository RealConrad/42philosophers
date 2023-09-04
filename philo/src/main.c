/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:39:15 by cwenz             #+#    #+#             */
/*   Updated: 2023/09/04 14:21:12 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


int	main(int argc, char **argv)
{
	t_simulation_state	*simulation_context;

	if (argc != 5 && argc != 6)
		return (print_error_message("Invalid number of arguments."), ERROR);
	simulation_context = malloc(sizeof(t_simulation_state));
	if (!simulation_context)
		return (print_error_message("Allocation failed."), ERROR);

	// Initialize philo's into linked list and setup mutex
	if (init_philos(&simulation_context, --argc, ++argv) != SUCCESS)
		return (ERROR);
	// Join threads
	join_threads(&simulation_context);
	return (SUCCESS);
}
