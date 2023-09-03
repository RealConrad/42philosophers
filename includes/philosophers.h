/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:14:28 by cwenz             #+#    #+#             */
/*   Updated: 2023/09/03 13:02:01 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef enum e_philosopher_state {
	EATING,
	THINKING,
	SLEEPING,
	DEATH
}	t_philosopher_state;

typedef	struct s_philosopher {
	struct s_philosopher	*next;
	struct s_philosopher	*prev;
	t_philosopher_state		state;
	int						index;
}	t_philosopher;

typedef struct s_simulation_state {
	t_philosopher	*philosphers;
	int				philosopher_count;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				required_eat_times; // optional
	
}	t_simulation_state;

#endif /* PHILOSOPHERS_H */