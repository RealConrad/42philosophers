/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:09:26 by cwenz             #+#    #+#             */
/*   Updated: 2023/09/07 15:08:44 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	wait_for_duraiton(t_philosopher *philosopher, struct timeval start_time_ms)
{
	struct timeval	end_time_ms;
	long			elapsed;
	int				desired_time_ms;
	
	desired_time_ms = get_state_time(philosopher);
	gettimeofday(&end_time_ms, NULL);
	elapsed = ((end_time_ms.tv_sec - start_time_ms.tv_sec) * 1000) + ((end_time_ms.tv_usec - start_time_ms.tv_usec) / 1000);
	
	// printf("\n\nTIME: %ld\n\n", (elapsed - desired_time_ms) * 1000);
	if (elapsed < desired_time_ms)
	{
		usleep((desired_time_ms - elapsed) * 1000);
	}
}

int	get_time(void)
{
	struct timeval	elasped_ms;
	int				result;

	gettimeofday(&elasped_ms, NULL);
	result = (elasped_ms.tv_sec * 1000) + (elasped_ms.tv_usec / 1000); 
	return (result);
}
