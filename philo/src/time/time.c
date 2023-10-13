/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:09:26 by cwenz             #+#    #+#             */
/*   Updated: 2023/10/13 13:54:53 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
 * @brief Waits for wait_time in ms
 * @param wait_time The time in ms to wait
 */
void	wait_for_duration(long wait_time)
{
	long long	start_time;
	long long	elapsed_time;

	start_time = get_current_time();
	while (true)
	{
		elapsed_time = get_current_time() - start_time;
		if (elapsed_time >= wait_time)
			return ;
		usleep(100);
	}
}

/**
 * @brief Calculates the time difference in milliseconds from
 * 	the specified start time to the current time.
 * @param start_time_ms The time in milliseconds from which the time
 * 	is calculated.
 * @return The time difference in milliseconds from the
 * 	current time - start_time_ms.
 */
long long	get_time_difference(long long start_time_ms)
{
	long long	current_time_ms;

	current_time_ms = get_current_time();
	return (current_time_ms - start_time_ms);
}

/**
 * @brief Gets the current time in milliseconds since the Unix epoch (1970).
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
	struct timeval		current_time;
	long long			result;

	gettimeofday(&current_time, NULL);
	result = (current_time.tv_sec * 1000) + ((current_time.tv_usec) / 1000);
	return (result);
}
