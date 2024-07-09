/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_treads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:05:20 by ozahidi           #+#    #+#             */
/*   Updated: 2024/07/09 21:50:21 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	set_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->l_fork->fork);
	if (display_message(philo, "has taken a fork"))
		return (1);
	pthread_mutex_lock(&philo->r_fork->fork);
	if (display_message(philo, "has taken a fork"))
		return (1);
	if (display_message(philo, "is eating"))
		return (1);
	last_meal(philo, 1);
	if (ft_sleep(philo, philo->data->time_eat))
		return (1);
	eat_meal(philo, 1);
	pthread_mutex_unlock(&philo->l_fork->fork);
	pthread_mutex_unlock(&philo->r_fork->fork);
	return (0);
}

long	last_meal(t_philo *philo, int update)
{
	long	result;

	result = 0;
	pthread_mutex_lock(&philo->data->secure);
	if (update)
		philo->last_meal = get_current_time();
	else
		result = philo->last_meal;
	pthread_mutex_unlock(&philo->data->secure);
	return (result);
}

int	eat_meal(t_philo *philo, int update)
{
	int	result;

	result = 0;
	pthread_mutex_lock(&philo->data->eat_secure);
	if (update)
		philo->eat++;
	else
		result = philo->eat;
	pthread_mutex_unlock(&philo->data->eat_secure);
	return (result);
}

void	*routine(void *pram)
{
	t_philo	*philo;

	philo = (t_philo *)pram;
	if (philo->id % 2 == 0)
	{
		if (display_message(philo, "is sleeping"))
			return (NULL);
		if (ft_sleep(philo, philo->data->time_sleep))
			return (NULL);
	}
	while (1)
	{
		if (set_eat(philo))
			return (NULL);
		if (display_message(philo, "is sleeping"))
			return (NULL);
		if (ft_sleep(philo, philo->data->time_sleep))
			return (NULL);
		if (display_message(philo, "is thinking"))
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
