/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 13:52:46 by cwenz             #+#    #+#             */
/*   Updated: 2023/09/03 16:06:13 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_error_message(const char *msg)
{
	printf("Error:\n%s\n", msg);
}

long	atol(const char *str)
{
	long	num;
	int		i;
	
	i = 0;
	num = 0;
	while(str[i])
	{
		num = 10 * num + (str[i] - '0');
		i++;
	}
	return (num);
}

void print_list(t_simulation_state *philo)
{
	t_philosopher *temp = philo->philosphers;

	while (true)
	{
		printf("Philo %d ::: Prev: %d - Next: %d\n", temp->index, temp->prev->index, temp->next->index);
		temp = temp->next;
		if (temp == philo->philosphers)
			break ;
	}
}