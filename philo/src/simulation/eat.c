/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 18:11:23 by cwenz             #+#    #+#             */
/*   Updated: 2023/09/29 13:44:44 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	check_if_eaten_enough(t_philosopher *philosopher);

void	update_number_of_times_eaten(t_philosopher *philosopher)
{
	philosopher->number_of_times_eaten++;
	if (!philosopher->has_finished_eating)
	{
		lock_has_eaten_flag(philosopher);
		check_if_eaten_enough(philosopher);
		unlock_has_eaten_flag(philosopher);
	}
}

static void	check_if_eaten_enough(t_philosopher *philosopher)
{
	if (philosopher->sim_data->required_eat_times && philosopher->number_of_times_eaten >= philosopher->sim_data->required_eat_times)
		philosopher->has_finished_eating = true;
}
