/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 18:11:23 by cwenz             #+#    #+#             */
/*   Updated: 2023/09/16 20:50:30 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	update_number_of_times_eaten(t_philosopher *philosopher)
{
	lock_eat_counter_mutex(philosopher);
	philosopher->number_of_times_eaten++;
	unlock_eat_counter_mutex(philosopher);
}

int	check_if_eaten_enough(t_philosopher *philosopher)
{
	lock_eat_counter_mutex(philosopher);
	if (philosopher->number_of_times_eaten == philosopher->sim_data->required_eat_times)
		return (0);
	unlock_eat_counter_mutex(philosopher);
	return (1);
}