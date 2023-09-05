/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 13:44:24 by cwenz             #+#    #+#             */
/*   Updated: 2023/09/05 16:32:48 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static bool	check_numeric(const char *str);

bool	check_input(int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (!check_numeric(argv[i]) || atol(argv[i]) > INT_MAX)
			return (false);
		i++;
	}
	return (true);
}

static bool	check_numeric(const char *str)
{
	int	i;
	
	i = 0;
	while(str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
		i++;
	}
	return (true);
}

int	init_mutex(t_simulation_state *simulation_context, int index)
{
	if (pthread_mutex_init(&simulation_context->forks[index].mutex, NULL) != SUCCESS)
		return (ERROR);
	simulation_context->forks[index].id = index;
	simulation_context->forks[index].in_use = false;
	return (SUCCESS);
}

void	assign_new_philosopher(t_simulation_state *simulation_context, t_philosopher *new_philosopher, int index)
{
	new_philosopher->index = index;
	new_philosopher->time_since_last_meal = 0;
	new_philosopher->left_fork = &simulation_context->forks[index];
	new_philosopher->right_fork = &simulation_context->forks[(index + 1) % simulation_context->philo_count];
}