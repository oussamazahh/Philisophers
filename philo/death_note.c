/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_note.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 21:37:23 by ozahidi           #+#    #+#             */
/*   Updated: 2024/07/09 22:02:16 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	kill_philo(t_philo *philo, int update)
{
	int	result;

	result = 0;
	pthread_mutex_lock(&philo->data->check);
	if (update)
		philo->data->kill = 1;
	else
		result = philo->data->kill;
	pthread_mutex_unlock(&philo->data->check);
	return (result);
}

void	extra_help(t_philo *philo, int i)
{
	kill_philo(&philo[i], 1);
	pthread_mutex_lock(&philo->data->print_lock);
	printf("\033[31m%ld %d died\n", get_current_time() - philo->data->time,
		philo->id);
}

int	help_death_note(t_philo *philo, int i, int *j, int *k)
{
	while (i < philo->data->number_of_philo)
	{
		if (get_current_time() - last_meal(&philo[i],
				0) >= philo->data->time_die)
		{
			extra_help(philo, i);
			return (1);
		}
		if (philo->data->nt_eat != -1 && eat_meal(&philo[*k],
				0) >= philo->data->nt_eat)
		{
			(*k)++;
			(*j)++;
		}
		if (*j == philo->data->number_of_philo)
		{
			kill_philo(&philo[i], 1);
			return (1);
		}
		i++;
	}
	return (0);
}

int	_death_note(void *param)
{
	int		i;
	int		k;
	int		j;
	t_philo	*philo;

	k = 0;
	j = 0;
	philo = (t_philo *)param;
	while (1)
	{
		i = 0;
		if (help_death_note(philo, i, &j, &k))
			return (1);
	}
	return (0);
}
