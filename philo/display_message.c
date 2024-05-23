/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_message.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 21:20:28 by ozahidi           #+#    #+#             */
/*   Updated: 2024/05/23 21:21:10 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	display_message(t_philo *philo, int value)
{
	int	k;

	pthread_mutex_lock(&philo->data->check);
	k = philo->data->kill;
	if (k == 1)
	{
		printf("%ld %d died\n", get_current_time() - philo->data->time,
			philo->id);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->check);
	if (value == EAT)
		printf("%ld %d is eating\n", get_current_time() - philo->data->time,
			philo->id);
	else if (value == SLEEP)
		printf("%ld %d is sleeping\n", get_current_time() - philo->data->time,
			philo->id);
	else if (value == THINK)
		printf("%ld %d is thinking\n", get_current_time() - philo->data->time,
			philo->id);
	else if (value == TAKE)
		printf("%ld %d has taken a fork\n", get_current_time()
			- philo->data->time, philo->id);
	return (0);
}
