/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:37:26 by cwenz             #+#    #+#             */
/*   Updated: 2023/09/11 14:37:28 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	update_time_since_last_meal(t_philosopher *philosopher)
{
	lock_time_mutex(philosopher);
	philosopher->time_since_last_meal = get_current_time();
	unlock_time_mutex(philosopher);
}

void	lock_time_mutex(t_philosopher *philosopher)
{
	pthread_mutex_lock(&philosopher->time_since_last_meal_mutex);
}

void	unlock_time_mutex(t_philosopher *philosopher)
{
	pthread_mutex_unlock(&philosopher->time_since_last_meal_mutex);
}
