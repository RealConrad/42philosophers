/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 18:11:23 by cwenz             #+#    #+#             */
/*   Updated: 2023/09/17 13:14:03 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	update_number_of_times_eaten(t_philosopher *philosopher)
{
	philosopher->number_of_times_eaten++;
}

int	check_if_eaten_enough(t_philosopher *philosopher)
{
	if (philosopher->sim_data->required_eat_times && philosopher->number_of_times_eaten == philosopher->sim_data->required_eat_times)
	{
		change_philosopher_state(philosopher, FINISHED_EATING);
		return (0);
	}
	return (1);
}