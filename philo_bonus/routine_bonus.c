/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 20:02:04 by ozahidi           #+#    #+#             */
/*   Updated: 2024/06/01 20:08:51 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	philo_routine(t_philo *philo, t_data *data)
{
	pthread_t	monitor;

	philo->last_meal = get_current_time();
	philo->data->time = get_current_time();
	create_thread(&monitor, death_scanner, philo);
	while (philo->eat != 0)
	{
		display_message(philo, "is thinking");
		sem_wait(philo->data->forks);
		sem_wait(philo->data->forks);
		display_message(philo, "has taken a fork");
		display_message(philo, "has taken a fork");
		display_message(philo, "is eating");
		ft_sleep(philo, philo->data->time_eat);
		philo->last_meal = get_current_time();
		philo->eat--;
		sem_post(philo->data->forks);
		sem_post(philo->data->forks);
		display_message(philo, "is sleeping");
		ft_sleep(philo, philo->data->time_sleep);
	}
	exit(0);
}

void	start_routine(t_philo *philo)
{
	sem_wait(philo->data->start);
	philo_routine(philo, philo->data);
}
