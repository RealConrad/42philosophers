/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 19:05:02 by cwenz             #+#    #+#             */
/*   Updated: 2023/10/09 14:29:08 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

static int	num_length(int num);

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

char	*strjoin(const char *str, int index)
{
	int		i;
	int		len;
	char	*result;
	int		index_len;
	
	i = 0;
	len = 0;
	index_len = num_length(index);
	while (str[len])
		len++;
	result = malloc(len + index_len + 1);
	if (!result)
		return (NULL);
	while (str[i])
	{
		result[i] = str[i];
		i++;
	}
	result[i + index_len] = '\0';
	while (index_len--)
	{
		result[i + index_len] = (index % 10) + '0';
		index /= 10;	
	}
	return (result);
}

static int	num_length(int num)
{
	int	num_len;

	num_len = 0;
	if (num == 0)
		return (0);
	while (num > 0)
	{
		num /= 10;
		num_len++;
	}
	return (num_len);
}
