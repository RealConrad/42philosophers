/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 17:37:03 by cwenz             #+#    #+#             */
/*   Updated: 2023/09/05 16:31:48 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int counter = 0;

void	*begin_simulation(void *arg)
{
	t_simulation_state	*simulation_context;
		
	printf("Philo thread %d\n", ++counter);
	(void)arg;
	
	simulation_context = (t_simulation_state *)arg;
	(void)simulation_context;
	return (NULL);
}