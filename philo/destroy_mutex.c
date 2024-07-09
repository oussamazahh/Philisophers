/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_mutex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:39:32 by ozahidi           #+#    #+#             */
/*   Updated: 2024/07/05 09:01:41 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_mutex(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->data->number_of_philo)
	{
		pthread_detach(philo[i].philo);
		pthread_mutex_destroy(&philo[i].l_fork->fork);
		pthread_mutex_destroy(&philo[i].r_fork->fork);
		pthread_mutex_destroy(&philo->data->forks[i].fork);
		i++;
	}
	pthread_mutex_destroy(&philo->data->check);
	pthread_mutex_destroy(&philo->data->print_lock);
	pthread_mutex_destroy(&philo->data->eat_secure);
	pthread_mutex_destroy(&philo->data->secure);
	free(philo->data->forks);
	free(philo->data);
	free(philo);
}
