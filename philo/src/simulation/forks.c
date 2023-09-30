/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 16:22:39 by cwenz             #+#    #+#             */
/*   Updated: 2023/09/30 16:28:19 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	lock_forks(t_philosopher *philosopher)
{
	if (philosopher->index % 2 == EVEN)
	{
		pthread_mutex_lock(&philosopher->left_fork.mutex);
		pthread_mutex_lock(&philosopher->right_fork.mutex);
	}
	else
	{
		pthread_mutex_lock(&philosopher->right_fork.mutex);
		pthread_mutex_lock(&philosopher->left_fork.mutex);
	}
	print_philosopher_state(philosopher, TAKEN_FORK);
	print_philosopher_state(philosopher, TAKEN_FORK);
}

void	unlock_forks(t_philosopher *philosopher)
{
	if (philosopher->index % 2 == EVEN)
	{
		pthread_mutex_unlock(&philosopher->left_fork.mutex);
		pthread_mutex_unlock(&philosopher->right_fork.mutex);
	}
	else
	{
		pthread_mutex_unlock(&philosopher->right_fork.mutex);
		pthread_mutex_unlock(&philosopher->left_fork.mutex);
	}
}
