/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 12:53:24 by cwenz             #+#    #+#             */
/*   Updated: 2023/10/06 17:01:30 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static bool	check_numeric(const char *str);

long	atol(const char *str)
{
	long	num;
	int		i;

	i = 0;
	num = 0;
	while (str[i])
	{
		num = 10 * num + (str[i] - '0');
		i++;
	}
	return (num);
}

bool	check_input(int argc, char **argv)
{
	int	i;

	i = 0;
	if (atol(argv[0]) == 0)
		return (false);
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
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
		i++;
	}
	return (true);
}
