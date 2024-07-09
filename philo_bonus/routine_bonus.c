/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 20:02:04 by ozahidi           #+#    #+#             */
/*   Updated: 2024/07/09 22:27:10 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	help_philo(t_philo *philo)
{
	pthread_t	monitor;

	create_thread(&monitor, death_scanner, philo);
	if (philo->data->number_of_philo == 1)
	{
		sem_wait(philo->data->forks);
		display_message(philo, "has taken a fork");
	}
	else if (philo->id > philo->data->number_of_philo / 2)
	{
		display_message(philo, "is sleeping");
		ft_sleep(philo, philo->data->time_sleep);
	}
}

long	last_meal(t_philo *philo, int update)
{
	long	result;

	result = 0;
	sem_wait(philo->data->protect_meal);
	if (update)
		philo->last_meal = get_current_time();
	else
		result = philo->last_meal;
	sem_post(philo->data->protect_meal);
	return (result);
}

int	eat_set_get(t_philo *philo, int update)
{
	int	result;

	result = 0;
	sem_wait(philo->data->protect_eat);
	if (update)
		philo->eat--;
	else
		result = philo->eat;
	sem_post(philo->data->protect_eat);
	return (result);
}

int	philo_routine(t_philo *philo, t_data *data)
{
	last_meal(philo, 1);
	help_philo(philo);
	while (1)
	{
		sem_wait(philo->data->forks);
		display_message(philo, "has taken a fork");
		sem_wait(philo->data->forks);
		display_message(philo, "has taken a fork");
		display_message(philo, "is eating");
		sem_wait(philo->data->protect_meal);
		last_meal(philo, 1);
		sem_post(philo->data->protect_meal);
		ft_sleep(philo, philo->data->time_eat);
		eat_set_get(philo, 1);
		sem_post(philo->data->forks);
		sem_post(philo->data->forks);
		display_message(philo, "is sleeping");
		ft_sleep(philo, philo->data->time_sleep);
		display_message(philo, "is thinking");
		if ((philo->id == data->number_of_philo
				|| philo->id == data->number_of_philo - 1) && philo->id % 2 == 1
			&& eat_set_get(philo, 0) == 0)
			exit(1);
	}
	exit(0);
}
