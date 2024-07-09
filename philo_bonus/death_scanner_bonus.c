/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_scanner_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 20:03:33 by ozahidi           #+#    #+#             */
/*   Updated: 2024/06/29 14:15:10 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*death_scanner(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		sem_wait(philo->data->fasting);
		if (get_current_time() - last_meal(philo, 0) >= philo->data->time_die)
		{
			sem_wait(philo->data->print_lock);
			printf("\e[31m%ld %d %s\n", get_current_time() - philo->data->time,
				philo->id, "is dead");
			sem_post(philo->data->fasting);
			exit(0);
		}
		sem_post(philo->data->fasting);
	}
	return (NULL);
}
