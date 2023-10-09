/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:30:58 by cwenz             #+#    #+#             */
/*   Updated: 2023/10/10 01:44:56 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	print_philosopher_state(t_philosopher *philosopher,
	t_philosopher_state state)
{
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
		printf("\033[31m%lld %d %s\n\033[0m",
			get_time_difference(*(philosopher->start_time_ms)),
			philosopher->index, DEATH_TEXT);
}
