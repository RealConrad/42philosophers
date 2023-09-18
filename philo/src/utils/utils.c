/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 13:52:46 by cwenz             #+#    #+#             */
/*   Updated: 2023/09/18 16:50:05 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


long atol(const char *str)
{
	long num;
	int i;

	i = 0;
	num = 0;
	while (str[i])
	{
		num = 10 * num + (str[i] - '0');
		i++;
	}
	return (num);
}

void join_threads(t_simulation_state *simulation_context)
{
	t_philosopher *temp;

	temp = simulation_context->philosphers;
	while (true)
	{
		pthread_join(temp->thread, NULL);
		temp = temp->next;
		if (temp == simulation_context->philosphers)
			break;
	}
}

void	detach_threads(t_simulation_state *simulation_context)
{
	t_philosopher *temp;

	temp = simulation_context->philosphers;
	while (true)
	{
		temp = temp->next;
		printf("---------------Philo [%d] ate: %d\n", temp->index, temp->number_of_times_eaten);
		if (temp->thread)
			pthread_detach(temp->thread);
		if (temp == simulation_context->philosphers)
			break;
	}
}

void	print_philosopher_state(t_philosopher *philosopher)
{
	long long	time;

	time = get_time_difference(philosopher->start_time_ms);
	if (philosopher->state == TAKEN_FORK)
		printf("%lld %d %s\n", time, philosopher->index, FORK_TEXT);
	else if (philosopher->state == EATING)
		printf("%lld %d %s\n", time, philosopher->index, EATING_TEXT);
	else if (philosopher->state == THINKING)
		printf("%lld %d %s\n", time, philosopher->index, THINKING_TEXT);
	else if (philosopher->state == SLEEPING)
		printf("%lld %d %s\n", time, philosopher->index, SLEEP_TEXT);
	else if (philosopher->state == DEATH)
		printf("%lld %d %s\n", time, philosopher->index, DEATH_TEXT);
}
