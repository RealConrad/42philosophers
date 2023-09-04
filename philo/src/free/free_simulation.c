/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_simulation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:03:03 by cwenz             #+#    #+#             */
/*   Updated: 2023/09/04 15:08:37 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	free_simulation(t_simulation_state **simulation_context, char *msg)
{
	(void)simulation_context;
	printf("Error:\n%s\n", msg);
}
