/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_treads_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:05:20 by ozahidi           #+#    #+#             */
/*   Updated: 2024/06/01 20:27:00 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	create_thread(pthread_t *monitor, void *(*death_scanner)(void *),
		t_philo *philo)
{
	int	check;

	check = 0;
	check = pthread_create(monitor, NULL, death_scanner, philo);
	if (check == -1)
	{
		printf("Error: pthread_create\n");
		exit(1);
	}
	pthread_detach(*monitor);
}
