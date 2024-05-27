/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_table_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:24:36 by ozahidi           #+#    #+#             */
/*   Updated: 2024/05/27 17:32:34 by ozahidi          ###   ########.fr       */
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
		(philo[i - 1]).last_meal = get_current_time();
		(philo[i - 1]).eat = 0;
		(philo[i - 1]).take = 0;
		(philo[i - 1]).sleep = 1;
		(philo[i - 1]).die = 0;
		(philo[i - 1]).id = i;
		(philo[i - 1]).data = data;
		i++;
	}
	return (philo);
}
