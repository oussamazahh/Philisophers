/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 19:34:46 by ozahidi           #+#    #+#             */
/*   Updated: 2024/06/29 14:02:37 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_data(t_data **data, char **av, int ac)
{
	(*data) = malloc(sizeof(t_data));
	if (!data)
		return (1);
	(*data)->number_of_philo = ft_atoi(av[1]);
	(*data)->number_of_fork = ft_atoi(av[1]);
	(*data)->time_die = ft_atoi(av[2]);
	(*data)->time_eat = ft_atoi(av[3]);
	(*data)->time_sleep = ft_atoi(av[4]);
	(*data)->time = get_current_time();
	if (ac == 6)
		(*data)->nt_eat = ft_atoi(av[5]);
	else
		(*data)->nt_eat = -1;
	(*data)->kill = 0;
	pthread_mutex_init(&(*data)->check, NULL);
	pthread_mutex_init(&(*data)->secure, NULL);
	pthread_mutex_init(&(*data)->eat_secure, NULL);
	pthread_mutex_init(&(*data)->print_lock, NULL);
	(*data)->forks = malloc(sizeof(t_fork) * ((*data)->number_of_fork));
	if (!((*data)->forks))
		return (1);
	return (0);
}
