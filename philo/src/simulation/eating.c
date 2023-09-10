/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:46:21 by cwenz             #+#    #+#             */
/*   Updated: 2023/09/06 16:01:47 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	can_philosopher_eat(t_philosopher *philosopher)
{
	if (!philosopher->left_fork->in_use && !philosopher->right_fork->in_use)
		return (true);
	return (false);
}