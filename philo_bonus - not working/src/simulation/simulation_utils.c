/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 16:15:46 by cwenz             #+#    #+#             */
/*   Updated: 2023/10/11 14:31:29 by cwenz            ###   ########.fr       */
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

	sem_wait(philosopher->philo_sem);
	philosopher->eat_count++;
	philosopher->time_since_last_meal = get_current_time();
	if (philosopher->sim_data->required_eat_times && philosopher->eat_count == philosopher->sim_data->required_eat_times)
		sem_post(philosopher->sim_data->is_done_eating);
	sem_post(philosopher->philo_sem);

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

void	philosopher_think(t_philosopher *philosopher)
{
	sem_wait(philosopher->sim_data->print);
	print_philosopher_state(philosopher, THINKING);
	sem_post(philosopher->sim_data->print);
}
