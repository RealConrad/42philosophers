/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:39:15 by cwenz             #+#    #+#             */
/*   Updated: 2023/09/05 16:30:26 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


int	main(int argc, char **argv)
{
	t_simulation_state	simulation_context;

	if (argc != 5 && argc != 6)
		return (printf("Invalid number of arguments.\n"), ERROR);
	// Initialize philo's into linked list and setup mutex
	if (init_philos(&simulation_context, --argc, ++argv) != SUCCESS)
		return (ERROR);
	join_threads(&simulation_context);

	return (SUCCESS);
}
