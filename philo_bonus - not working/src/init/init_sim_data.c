/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sim_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 14:56:36 by cwenz             #+#    #+#             */
/*   Updated: 2023/10/11 14:19:49 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	init_sim_data(t_simulation_data *simulation_data, int argc, char **argv)
{
	if (!check_input(argc, argv))
		return (display_error(ERR_INVALID_ARG), ERROR);
	simulation_data->philo_count = atol(argv[0]);
	simulation_data->time_to_die = atol(argv[1]);
	simulation_data->time_to_eat = atol(argv[2]);
	simulation_data->time_to_sleep = atol(argv[3]);
	if (argv[4])
		simulation_data->required_eat_times = atol(argv[4]);
	sem_unlink("/forks");
	sem_unlink("/print");
	sem_unlink("/is_done_eating");
	sem_unlink("/exit_program");
	simulation_data->forks = sem_open("/forks", O_CREAT, 0644, simulation_data->philo_count / 2);
	simulation_data->print = sem_open("/print", O_CREAT, 0644, 1);
	simulation_data->exit_program = sem_open("/exit_program", O_CREAT, 0644, 0);
	simulation_data->is_done_eating = sem_open("/is_done_eating", O_CREAT, 0644, 0);
	return (SUCCESS);
}
