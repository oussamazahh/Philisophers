/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_message.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 21:20:28 by ozahidi           #+#    #+#             */
/*   Updated: 2024/05/24 17:12:42 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	display_message(t_philo *philo, char *value)
{
	int	k;

	pthread_mutex_lock(&philo->data->check);
	k = philo->data->kill;
	if (k == 1)
		return (1);
	printf("%ld %d %s\n", get_current_time()
		- philo->data->time, philo->id, value);
	pthread_mutex_unlock(&philo->data->check);
	return (0);
}
