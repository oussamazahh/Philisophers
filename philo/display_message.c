/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_message.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 21:20:28 by ozahidi           #+#    #+#             */
/*   Updated: 2024/06/30 07:34:02 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	display_message(t_philo *philo, char *value)
{
	pthread_mutex_lock(&philo->data->print_lock);
	if (kill_philo(philo, 0) == 1)
		return (1);
	printf("%ld %d %s\n", get_current_time()
		- philo->data->time, philo->id, value);
	pthread_mutex_unlock(&philo->data->print_lock);
	return (0);
}
