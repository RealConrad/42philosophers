/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 13:52:46 by cwenz             #+#    #+#             */
/*   Updated: 2023/09/07 11:30:03 by cwenz            ###   ########.fr       */
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

void	print_philosopher_state(t_philosopher *philisopher)
{
	if (philisopher->state == TAKEN_FORK)
		printf("Philosopher %d %s\n", philisopher->index, FORK_TEXT);
	else if (philisopher->state == EATING)
		printf("Philosopher %d %s\n", philisopher->index, EATING_TEXT);
	else if (philisopher->state == THINKING)
		printf("Philosopher %d %s\n", philisopher->index, THINKING_TEXT);
	else if (philisopher->state == SLEEPING)
		printf("Philosopher %d %s\n", philisopher->index, SLEEP_TEXT);
	else if (philisopher->state == DEATH)
		printf("Philosopher %d %s\n", philisopher->index, DEATH_TEXT);
}

int	get_state_time(t_philosopher *philosopher)
{
	if (philosopher->state == EATING)
		return (philosopher->sim_data->time_to_eat);
	else if (philosopher->state == SLEEPING)
		return (philosopher->sim_data->time_to_sleep);
	return (0);
}
