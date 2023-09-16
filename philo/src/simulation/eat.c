/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 18:11:23 by cwenz             #+#    #+#             */
/*   Updated: 2023/09/16 18:12:57 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	update_number_of_times_eaten(t_philosopher *philosopher)
{
	lock_eat_counter_mutex(philosopher);
	philosopher->number_of_times_eaten++;
	unlock_eat_counter_mutex(philosopher);
}