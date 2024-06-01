/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_message_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 21:20:28 by ozahidi           #+#    #+#             */
/*   Updated: 2024/06/01 20:27:29 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	display_message(t_philo *philo, char *value)
{
	sem_wait(philo->data->print_lock);
	printf("%ld %d %s\n", get_current_time() - philo->data->time, philo->id,
		value);
	sem_post(philo->data->print_lock);
	return (0);
}
