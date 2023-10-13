/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 19:05:02 by cwenz             #+#    #+#             */
/*   Updated: 2023/10/13 10:47:49 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
 * @brief Joins all threads in a safe manner.
 * @param simulation_context Holds all the philosopher threads.
 */
void	join_threads(t_simulation_state *simulation_context)
{
	t_philosopher	*temp;

	temp = simulation_context->philosphers;
	while (true)
	{
		pthread_join(temp->thread, NULL);
		temp = temp->next;
		if (temp == simulation_context->philosphers)
			return ;
	}
}

/**
 * @brief Checks if the philosopher should exit out the simulation.
 * @param philosopher The philosopher to check.
 * @return True if the philosopher should exit, otherwise false.
 */
bool	check_philo_sim_exit(t_philosopher *philosopher)
{
	bool	sim_exit_value;

	pthread_mutex_lock(&philosopher->philo_mutex);
	sim_exit_value = philosopher->exit_sim;
	pthread_mutex_unlock(&philosopher->philo_mutex);
	return (sim_exit_value);
}

/**
 * @brief Changes every `philosopher->exit_sim` to true.
 * @param simulation_context The context that holds all philosophers.
 */
void	exit_all_threads(t_simulation_state *simulation_context)
{
	t_philosopher	*philosopher;

	philosopher = simulation_context->philosphers;
	while (true)
	{
		pthread_mutex_lock(&philosopher->philo_mutex);
		philosopher->exit_sim = true;
		pthread_mutex_unlock(&philosopher->philo_mutex);
		philosopher = philosopher->next;
		if (philosopher == simulation_context->philosphers)
			return ;
	}
}

/**
 * @brief Prints out an error statement to the console based on error_type.
 * @param error_type The type of error to output to the console.
 */
void	display_error(t_error_type error_type)
{
	if (error_type == ERR_MUTEX_INITIALIZATION)
		printf("Error:\nFailed to initialize mutexes.\n");
	else if (error_type == ERR_INVALID_ARG)
		printf("Error:\nInvalid command line arguments.\n");
	else if (error_type == ERR_MEMORY_ALLOCATION)
		printf("Error:\nMalloc call failed.\n");
	else if (error_type == ERR_THREAD_CREATION)
		printf("Error:\nFailed to create threads.\n");
}

/**
** @brief Allocates a block of memory for an array of elements, initializes 
** the memory to zero, and returns a pointer to the first element 
** of the allocated space
** @param count Number of elements to allocate memory
** @param size Size for each element
** @return A pointer to the allocated memory or NULL if not found
*/
void	*ft_calloc(size_t count, size_t size)
{
	void			*p;
	size_t			total;
	size_t			i;
	unsigned char	*ch;

	total = count * size;
	if (count && (total / count) != size)
		return (NULL);
	p = malloc(total);
	if (!p)
		return (NULL);
	ch = (unsigned char *)p;
	i = 0;
	while (i < total)
	{
		ch[i] = 0;
		i++;
	}
	return (p);
}
