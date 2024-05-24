/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_mutex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:39:32 by ozahidi           #+#    #+#             */
/*   Updated: 2024/05/24 10:43:02 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_mutex(t_philo *philo)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&philo->data->check);
	while (i < philo->data->number_of_philo)
	{
		pthread_detach(philo[i].philo);
		pthread_mutex_destroy(&philo[i].l_fork->fork);
		pthread_mutex_destroy(&philo[i].r_fork->fork);
		pthread_mutex_destroy(&philo->data->forks[i].fork);
		i++;
	}
}
