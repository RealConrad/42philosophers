/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 12:53:24 by cwenz             #+#    #+#             */
/*   Updated: 2023/10/13 10:51:12 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static bool	check_numeric(const char *str);

/**
 * @brief Converts a given string to a long.
 * @param str The string to convert.
 * @return The number converted to a long.
 */
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

/**
 * @brief Checks if the command line arugments are correct.
 * @param argc The number of command line arugments
 * @param argv An array of the command line arguments
 * @return True if the input is correct, otherwise false.
 */
bool	check_input(int argc, char **argv)
{
	int	i;

	i = 0;
	if (atol(argv[0]) == 0)
		return (false);
	if (argv[4] && atol(argv[4]) == 0)
		return (false);
	while (i < argc)
	{
		if (!check_numeric(argv[i]) || atol(argv[i]) > INT_MAX)
			return (false);
		i++;
	}
	return (true);
}

/**
 * @brief Checks if the given string only contains numeric characters.
 * @param str The string to check.
 * @return True if the string only contains numeric characters, otherwise false.
 */
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
