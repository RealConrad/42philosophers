/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 13:52:46 by cwenz             #+#    #+#             */
/*   Updated: 2023/09/05 16:33:06 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void print_error_message(const char *msg)
{
	printf("Error:\n%s\n", msg);
}

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

void detach_threads(t_simulation_state *simulation_context)
{
	t_philosopher *temp;

	temp = simulation_context->philosphers;
	while (true)
	{
		break;
		temp = temp->next;
		if (!pthread_detach(temp->thread))
			if (temp == simulation_context->philosphers)
				break;
	}
}

// DELETE:
void print_list(t_simulation_state *philo)
{
	t_philosopher *temp = philo->philosphers;

	while (true)
	{
		printf("Philo %d ::: Prev: %d - Next: %d\n", temp->index, temp->prev->index, temp->next->index);
		temp = temp->next;
		if (temp == philo->philosphers)
			break;
	}
}
