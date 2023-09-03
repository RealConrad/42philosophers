/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 13:44:24 by cwenz             #+#    #+#             */
/*   Updated: 2023/09/03 14:39:33 by cwenz            ###   ########.fr       */
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
