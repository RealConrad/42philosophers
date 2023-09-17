/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:17:21 by cwenz             #+#    #+#             */
/*   Updated: 2023/09/17 13:24:20 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	change_philosopher_state(t_philosopher *philosopher, t_philosopher_state state)
{
	lock_philosopher_state(philosopher);
	philosopher->state = state;
	unlock_philosopher_state(philosopher);
}

void	lock_philosopher_state(t_philosopher *philosopher)
{
	pthread_mutex_lock(&philosopher->state_change_mutex);
}

void	unlock_philosopher_state(t_philosopher *philosopher)
{
	pthread_mutex_unlock(&philosopher->state_change_mutex);
}