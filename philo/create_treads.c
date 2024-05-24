/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_treads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:05:20 by ozahidi           #+#    #+#             */
/*   Updated: 2024/05/24 10:43:14 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	set_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->l_fork->fork);
	if (display_message(philo, TAKE))
		return (1);
	pthread_mutex_lock(&philo->r_fork->fork);
	if (display_message(philo, TAKE))
		return (1);
	if (display_message(philo, EAT))
		return (1);
	if (ft_sleep(philo, philo->data->time_eat))
		return (1);
	if (get_current_time() - philo->last_meal > philo->data->time_die)
	{
		philo->data->kill = 1;
		return (1);
	}
	philo->eat++;
	philo->last_meal = get_current_time();
	pthread_mutex_unlock(&philo->l_fork->fork);
	pthread_mutex_unlock(&philo->r_fork->fork);
	return (0);
}

void	*routine(void *pram)
{
	t_philo	*philo;

	philo = (t_philo *)pram;
	if (philo->id % 2 == 0)
	{
		if (display_message(philo, THINK))
			return (NULL);
		usleep(100);
	}
	while (1)
	{
		if (set_eat(philo))
			return (NULL);
		if (display_message(philo, SLEEP))
			return (NULL);
		if (ft_sleep(philo, philo->data->time_sleep))
			return (NULL);
		if (display_message(philo, THINK))
			return (NULL);
	}
	return (NULL);
}

int	create_threads(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->data->number_of_philo)
	{
		if (pthread_create(&philo[i].philo, NULL, &routine, &philo[i]) == -1)
			return (1);
		i++;
	}
	if (_death_note(philo))
	{
		destroy_mutex(philo);
		return (1);
	}
	i = 0;
	while (i < philo->data->number_of_philo)
	{
		pthread_join(philo[i].philo, NULL);
		i++;
	}
	destroy_mutex(philo);
	return (0);
}
