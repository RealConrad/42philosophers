/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 13:52:46 by cwenz             #+#    #+#             */
/*   Updated: 2023/09/11 15:10:13 by cwenz            ###   ########.fr       */
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
	printf("\n\nJoined all threads\n");
}

int	detach_threads(t_simulation_state *simulation_context)
{
	t_philosopher *temp;

	temp = simulation_context->philosphers;
	while (true)
	{
		break;
		temp = temp->next;
		if (!pthread_detach(temp->thread))
			return (ERROR);
		if (temp == simulation_context->philosphers)
			break;
	}
	return (SUCCESS);
}

void	print_philosopher_state(t_philosopher *philosopher)
{
	long long	time;

	time = get_time_difference(philosopher->start_time_ms);
	if (philosopher->state == TAKEN_FORK)
		printf("%lld Philosopher %d %s\n", time, philosopher->index, FORK_TEXT);
	else if (philosopher->state == EATING)
		printf("%lld Philosopher %d %s\n", time, philosopher->index, EATING_TEXT);
	else if (philosopher->state == THINKING)
		printf("%lld Philosopher %d %s\n", time, philosopher->index, THINKING_TEXT);
	else if (philosopher->state == SLEEPING)
		printf("%lld Philosopher %d %s\n", time, philosopher->index, SLEEP_TEXT);
	else if (philosopher->state == DEATH)
		printf("%lld Philosopher %d %s\n", time, philosopher->index, DEATH_TEXT);
}
