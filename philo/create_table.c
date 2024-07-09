/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:24:36 by ozahidi           #+#    #+#             */
/*   Updated: 2024/07/09 22:00:16 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_table(t_philo **philo, t_data **data)
{
	int	i;

	i = 1;
	*philo = malloc(sizeof(t_philo) * (*data)->number_of_philo);
	if (!*philo)
		return (1);
	while (i <= (*data)->number_of_philo)
	{
		(*data)->forks[i - 1].id = i - 1;
		(*philo)[i - 1].id = i;
		(*philo)[i - 1].data = *data;
		(*philo)[i - 1].eat = 0;
		(*philo)[i - 1].sleep = 0;
		(*philo)[i - 1].die = 0;
		(*philo)[i - 1].take = 0;
		(*philo)[i - 1].last_meal = get_current_time();
		(*philo)[i - 1].l_fork = &(*data)->forks[i - 1];
		if (i == (*data)->number_of_philo)
			(*philo)[i - 1].r_fork = &(*data)->forks[0];
		else
			(*philo)[i - 1].r_fork = &(*data)->forks[i];
		pthread_mutex_init(&(*data)->forks[i - 1].fork, NULL);
		i++;
	}
	return (0);
}
