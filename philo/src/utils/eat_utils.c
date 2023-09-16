/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 18:04:03 by cwenz             #+#    #+#             */
/*   Updated: 2023/09/16 18:05:35 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	lock_eat_counter_mutex(t_philosopher *philosopher)
{
	pthread_mutex_lock(&philosopher->number_of_times_eaten_mutex);
}

void	unlock_eat_counter_mutex(t_philosopher *philosopher)
{
	pthread_mutex_unlock(&philosopher->number_of_times_eaten_mutex);
}
