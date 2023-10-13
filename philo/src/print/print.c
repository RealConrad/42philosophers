/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:30:58 by cwenz             #+#    #+#             */
/*   Updated: 2023/10/13 13:34:30 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
 * @brief rints out the current state of a specified philosopher to the standard output.
 * 
 * This function is thread-safe, as it locks the philosopher's mutex before accessing
 * or modifying the philosopher's state, and unlocks the mutex before returning.
 * @param philosopher The philosopher whose state is being printed.
 * @param state The given state to be printed.
 */
void	print_philosopher_state(t_philosopher *philosopher,
	t_philosopher_state state)
{
	pthread_mutex_lock(&philosopher->philo_mutex);
	if (state == TAKEN_FORK && !philosopher->exit_sim)
		printf("%lld %d %s\n",
			get_time_difference(*(philosopher->start_time_ms)),
			philosopher->index, FORK_TEXT);
	else if (state == EATING && !philosopher->exit_sim)
		printf("%lld %d %s\n",
			get_time_difference(*(philosopher->start_time_ms)),
			philosopher->index, EATING_TEXT);
	else if (state == THINKING && !philosopher->exit_sim)
		printf("%lld %d %s\n",
			get_time_difference(*(philosopher->start_time_ms)),
			philosopher->index, THINKING_TEXT);
	else if (state == SLEEPING && !philosopher->exit_sim)
		printf("%lld %d %s\n",
			get_time_difference(*(philosopher->start_time_ms)),
			philosopher->index, SLEEP_TEXT);
	else if (state == DEATH && !philosopher->exit_sim)
		printf("%lld %d %s\n",
			get_time_difference(*(philosopher->start_time_ms)),
			philosopher->index, DEATH_TEXT);
	pthread_mutex_unlock(&philosopher->philo_mutex);
}
