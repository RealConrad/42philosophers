/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 12:46:03 by cwenz             #+#    #+#             */
/*   Updated: 2023/10/06 14:40:42 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


int	main(int argc, char **argv)
{
	t_simulation_state	simulation_context = {0};

	if (argc != 5 && argc != 6)
		return (printf("Invalid number of arguments.\n"), ERROR);
	if (init_philos(&simulation_context, --argc, ++argv) != SUCCESS)
		return (ERROR);
	monitor_philosophers(&simulation_context);
	exit_all_threads(&simulation_context);
	pthread_mutex_unlock(&simulation_context.shared_mutex);
	join_threads(&simulation_context);
	free_memory(&simulation_context, "", false);
	// system("leaks philo");
	// printf("\n\n\033[32mFinished simulation!\n\033[0m");
	return (SUCCESS);
}


// int g = 0;

// void* threadFunc(void* arg) {
// 	(void)arg;
//     g++;
//     return NULL;
// }

// int main() {
//     pthread_t t1, t2;
//     pthread_create(&t1, NULL, threadFunc, NULL);
//     pthread_create(&t2, NULL, threadFunc, NULL);
//     pthread_join(t1, NULL);
//     pthread_join(t2, NULL);
//     printf("g = %d\n", g);
//     return 0;
// }
