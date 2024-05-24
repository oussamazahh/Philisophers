/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_note.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 21:37:23 by ozahidi           #+#    #+#             */
/*   Updated: 2024/05/24 10:38:46 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
