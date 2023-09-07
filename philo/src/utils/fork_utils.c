/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:31:48 by cwenz             #+#    #+#             */
/*   Updated: 2023/09/07 17:19:01 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	lock_left_fork(t_philosopher *philosopher)
{
	pthread_mutex_lock(&philosopher->left_fork->mutex);
}

void	lock_right_fork(t_philosopher *philosopher)
{
	pthread_mutex_lock(&philosopher->right_fork->mutex);	
}

void	unlock_left_fork(t_philosopher *philosopher)
{
	pthread_mutex_unlock(&philosopher->left_fork->mutex);
}

void	unlock_right_fork(t_philosopher *philosopher)
{
	pthread_mutex_unlock(&philosopher->right_fork->mutex);
}
