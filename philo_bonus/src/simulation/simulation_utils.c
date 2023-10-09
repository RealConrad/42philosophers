/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 16:15:46 by cwenz             #+#    #+#             */
/*   Updated: 2023/10/10 00:38:27 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	philosopher_eat(t_philosopher *philosopher)
{
	sem_wait(philosopher->sim_data->forks);

	sem_wait(philosopher->sim_data->print);
	print_philosopher_state(philosopher, TAKEN_FORK);
	print_philosopher_state(philosopher, TAKEN_FORK);
	print_philosopher_state(philosopher, EATING);
	sem_post(philosopher->sim_data->print);

	philosopher->eat_count++;
	philosopher->time_since_last_meal = get_current_time();
	
	wait_for_duration(philosopher->sim_data->time_to_eat);

	sem_post(philosopher->sim_data->forks);
}

void	philosopher_sleep(t_philosopher *philosopher)
{
	sem_wait(philosopher->sim_data->print);
	print_philosopher_state(philosopher, SLEEPING);
	sem_post(philosopher->sim_data->print);

	wait_for_duration(philosopher->sim_data->time_to_sleep);
}

void	update_philo_eat_data(t_philosopher *philosopher)
{
	// printf("Waiting...\n");
	// printf("Locked in function %s\n", philosopher->sem_name);
	philosopher->eat_count++;
	philosopher->time_since_last_meal = get_current_time();
	// printf("Unlocking in function %s\n", philosopher->sem_name);
}

void	philosopher_think(t_philosopher *philosopher)
{
	sem_wait(philosopher->sim_data->print);
	print_philosopher_state(philosopher, THINKING);
	sem_post(philosopher->sim_data->print);
}

void	philosopher_normal_routine(t_philosopher *philosopher)
{
	philosopher_eat(philosopher);
	philosopher_sleep(philosopher);
	philosopher_think(philosopher);
}
