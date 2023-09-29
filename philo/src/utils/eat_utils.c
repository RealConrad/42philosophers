/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 18:04:03 by cwenz             #+#    #+#             */
/*   Updated: 2023/09/29 13:42:19 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	lock_has_eaten_flag(t_philosopher *philosopher)
{
	pthread_mutex_lock(&philosopher->has_finished_eating_mutex);
}

void	unlock_has_eaten_flag(t_philosopher *philosopher)
{
	pthread_mutex_unlock(&philosopher->has_finished_eating_mutex);
}
