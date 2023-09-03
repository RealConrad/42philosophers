/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:39:15 by cwenz             #+#    #+#             */
/*   Updated: 2023/09/03 17:29:38 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


int	main(int argc, char **argv)
{
	t_simulation_state	*simulation_context;

	if (argc != 5 && argc != 6)
	{
		print_error_message("Invalid number of arguments.");
		return (ERROR);
	}
	simulation_context = malloc(sizeof(t_simulation_state));
	if (!simulation_context)
	{
		print_error_message("Allocation failed.");
		return (ERROR);
	}
	if (init_philosophers(&simulation_context, --argc, ++argv) != SUCCESS)
		return (ERROR);
	// print_list(simulation_context);
	return (SUCCESS);
}
