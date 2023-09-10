/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:09:26 by cwenz             #+#    #+#             */
/*   Updated: 2023/09/10 14:42:06 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	wait_for_duration(long wait_time)
{
	long long	start_time;
	long long	elapsed_time;

	start_time = get_current_time();
	while(true)
	{
		elapsed_time = get_current_time() - start_time; 
		if (elapsed_time >= wait_time)
			return ;
		usleep(100);
	}
}

long long	get_time_difference(struct timeval start_time)
{
	struct timeval		end_time_ms;
	long long			result;

	gettimeofday(&end_time_ms, NULL);
	result = (end_time_ms.tv_sec - start_time.tv_sec) * 1000;
	result += (end_time_ms.tv_usec - start_time.tv_usec) / 1000;
	return (result);
}

/**
 * @brief    Gets the current time in milliseconds since the Unix epoch (1970).
 * 
 * This function uses the `gettimeofday` method to retrieve the current time
 * and then converts it to milliseconds
 *
 * @return   The current time in milliseconds since the Unix epoch.
 * 
 * @note  The accuracy of this function is dependent on the system's
 *        ability to provide high-resolution time stamps. The returned 
 *        value may wrap around or become inaccurate after long periods 
 *        of uptime.
 */
long long	get_current_time(void)
{
	struct timeval		elasped_ms;
	long long			result;

	gettimeofday(&elasped_ms, NULL);
	result = (elasped_ms.tv_sec * 1000) + (elasped_ms.tv_usec / 1000); 
	return (result);
}
