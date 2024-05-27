/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_message_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 21:20:28 by ozahidi           #+#    #+#             */
/*   Updated: 2024/05/26 21:39:49 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	display_message(t_philo *philo, char *value)
{
	int	k;

	sem_wait(philo->data->check);
	k = philo->data->kill;
	if (k == 1)
		return (1);
	printf("%ld %d %s\n", get_current_time()
		- philo->data->time, philo->id, value);
	sem_post(philo->data->check);
	return (0);
}
