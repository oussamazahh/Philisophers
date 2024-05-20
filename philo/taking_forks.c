/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   taking_forks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 15:25:48 by ozahidi           #+#    #+#             */
/*   Updated: 2024/05/20 14:36:21 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int check_forks(int *forks, int nb_forks)
{
	int i;
	int nb;

	i = 0;
	nb = 0;
	while (i < nb_forks)
	{
		// printf ("nbr frks %d\n", nb_forks );
		if (forks[i] != 1)
			nb++;
		i++;
	}
	if (nb > 1)
		return (0);
	return (1);
}

int    taking(t_philo **philo)
{
	t_philo *tmp;
	int     i;
	int     *tab;

	tmp = *philo;
	i = 0;
	tab = tmp->data->forks;
;    while (i < tmp->data->number_of_fork)
	{
		if (tab[i] == 0 && i + 1 < tmp->data->number_of_fork)
		{
			if (tmp->l_fork == 1 && tmp->r_fork == 1)
				return (0);
			tmp->l_fork = 1;
			tmp->r_fork = 1;
			tmp->eat = 1;
			tab[i] = 1;
			tab[i + 1] = 1;
			printf("%ld %d taking fork\n", get_current_time() - tmp->data->time, tmp->id);
			return (1);
		}
		i++;
	}
	return (0);
}

void   print_think(t_philo *philo)
{
	while (philo)
	{
		if (philo->r_fork != 1 && philo->l_fork != 1)
			printf("%ld %d is thinking\n", get_current_time() - philo->data->time, philo->id);
		philo = philo->next;
	}
}

void *take_fork(void *p)
{
	t_philo *philo = (t_philo *)p;
	pthread_mutex_lock(&(philo)->data->mutex);
	while (!check_forks(philo->data->forks, philo->data->number_of_fork))
	{
		if (!taking(&philo))
			break ;
	}
	pthread_mutex_unlock(&(philo)->data->mutex);
	print_think(philo);
	return (0);
}

int create_threads(t_philo **philo)
{
	t_philo *tmp;
	int i;

	i = 0;
	tmp = *philo;
	pthread_mutex_init(&(*philo)->data->mutex, NULL);
	while (i < (*philo)->data->number_of_philo)
	{
		pthread_create(&(tmp->philo), NULL, take_fork, tmp);
		tmp = tmp->next;
		i++;
	}
	return (0);
}
int taking_forks(t_philo **philo)
{
	create_threads(philo);
	return (0);    
}
