/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_treads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:05:20 by ozahidi           #+#    #+#             */
/*   Updated: 2024/05/23 21:18:59 by ozahidi          ###   ########.fr       */
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
	philo->eat++;
	ft_sleep(philo->data->time_eat);
	philo->last_meal = get_current_time();
	pthread_mutex_unlock(&philo->l_fork->fork);
	pthread_mutex_unlock(&philo->r_fork->fork);
	return (0);
}

int	help_death_note(t_philo *philo, int i, int *j, int *k)
{
	while (i < philo->data->number_of_philo)
	{
		if (get_current_time() - philo[i].last_meal > philo->data->time_die)
		{
			philo[i].data->kill = 1;
			display_message(&philo[i], DEAD);
			return (1);
		}
		if (philo->data->nt_eat != -1 && philo[*k].eat >= philo->data->nt_eat)
		{
			(*k)++;
			(*j)++;
		}
		if (*j == philo->data->number_of_philo)
		{
			philo[i].data->kill = 1;
			display_message(&philo[i], DEAD);
			return (1);
		}
		i++;
	}
	return (0);
}

int	_death_note(t_philo *philo)
{
	int	i;
	int	k;
	int	j;

	k = 0;
	j = 0;
	while (1)
	{
		i = 0;
		if (help_death_note(philo, i, &j, &k))
			return (1);
	}
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
		ft_sleep(100);
	}
	while (1)
	{
		if (set_eat(philo))
			return (NULL);
		if (display_message(philo, SLEEP))
			return (NULL);
		ft_sleep(philo->data->time_sleep);
		if (display_message(philo, THINK))
			return (NULL);
	}
	return (NULL);
}

int	create_treads(t_philo *philo)
{
	int	i;
	int	kill;

	i = 0;
	while (i < philo->data->number_of_philo)
	{
		if (pthread_create(&philo[i].philo, NULL, &routine, &philo[i]) == -1)
			return (1);
		i++;
	}
	if (_death_note(philo))
		return (1);
	i = 0;
	while (i < philo->data->number_of_philo)
	{
		pthread_join(philo[i].philo, NULL);
		i++;
	}
	return (0);
}
