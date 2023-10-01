/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:30:58 by cwenz             #+#    #+#             */
/*   Updated: 2023/10/01 16:51:36 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_philosopher_state(t_philosopher *philosopher, t_philosopher_state state)
{
	pthread_mutex_lock(philosopher->print_mutex);
	if (state == TAKEN_FORK)
		printf("%lld %d %s\n", get_time_difference(philosopher->start_time_ms), philosopher->index, FORK_TEXT);
	else if (state == EATING)
		printf("%lld %d %s\n", get_time_difference(philosopher->start_time_ms), philosopher->index, EATING_TEXT);
	else if (state == THINKING)
		printf("%lld %d %s\n", get_time_difference(philosopher->start_time_ms), philosopher->index, THINKING_TEXT);
	else if (state == SLEEPING)
		printf("%lld %d %s\n", get_time_difference(philosopher->start_time_ms), philosopher->index, SLEEP_TEXT);
	else if (state == DEATH)
		printf("%lld %d %s\n", get_time_difference(philosopher->start_time_ms), philosopher->index, DEATH_TEXT);
	pthread_mutex_unlock(philosopher->print_mutex);
}