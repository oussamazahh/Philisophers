/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_table_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:24:36 by ozahidi           #+#    #+#             */
/*   Updated: 2024/05/30 12:37:28 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"


t_philo*	create_table(t_data *data, char **av, int ac)
{
	int	i;
	t_philo *philo;

	i = 1;
	philo = malloc(sizeof(t_philo) * data->number_of_philo);
	if (!philo)
		return (NULL);
	while (i <= data->number_of_philo)
	{
		(philo[i - 1]).eat = 0;
		(philo[i - 1]).id = i;
		(philo[i - 1]).data = data;
		(philo[i - 1]).eat = philo->data->nt_eat;
		i++;
	}
	return (philo);
}
