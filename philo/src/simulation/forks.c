/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 16:22:39 by cwenz             #+#    #+#             */
/*   Updated: 2023/10/13 13:31:06 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
 * @brief Locks the mutexes (forks) based on even-odd index.
 * 	There is also a sliht delay when locking odd-indexed philosophers forks.
 * 	For even indexed philosophers the left fork is locked and for odd indexed
 * 	philosophers the right fork is locked first.
 * @param philosopher The philosopher whoses forks should be locked.
 */
void	lock_forks(t_philosopher *philosopher)
{
	if (philosopher->index % 2 == EVEN)
	{
		pthread_mutex_lock(philosopher->left_fork);
		pthread_mutex_lock(philosopher->right_fork);
	}
	else
	{
		usleep(500);
		pthread_mutex_lock(philosopher->right_fork);
		pthread_mutex_lock(philosopher->left_fork);
	}
}

/**
 * @brief Unlocks the mutexes (forks) for the given philosopher.
 * @param philosopher The philosopher whose forks should be unlocked.
 */
void	unlock_forks(t_philosopher *philosopher)
{
	pthread_mutex_unlock(philosopher->left_fork);
	pthread_mutex_unlock(philosopher->right_fork);
}
