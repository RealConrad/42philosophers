/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:18:51 by cwenz             #+#    #+#             */
/*   Updated: 2023/09/07 17:21:49 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	lock_forks(t_philosopher *philosopher)
{
	if (philosopher->index % 2 == EVEN)
	{
		lock_left_fork(philosopher);
		lock_right_fork(philosopher);
	}
	else
	{
		lock_right_fork(philosopher);
		lock_left_fork(philosopher);
	}
	philosopher->left_fork->in_use = true;
	philosopher->right_fork->in_use = true;
}

void	unlock_forks(t_philosopher *philosopher)
{
	if (philosopher->index % 2 == EVEN)
	{
		unlock_left_fork(philosopher);
		unlock_right_fork(philosopher);
	}
	else
	{
		unlock_right_fork(philosopher);
		unlock_left_fork(philosopher);
	}
	philosopher->left_fork->in_use = false;
	philosopher->right_fork->in_use = false;
}
