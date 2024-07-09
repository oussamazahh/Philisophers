/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_data_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 19:34:46 by ozahidi           #+#    #+#             */
/*   Updated: 2024/07/09 22:17:54 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	create_semaphores(t_data *data)
{
	sem_unlink("/fasting");
	sem_unlink("/print_lock");
	sem_unlink("/forks");
	sem_unlink("/lock");
	sem_unlink("/protect_meal");
	sem_unlink("/protect_eat");
	data->protect_meal = sem_open("/protect_meal", O_CREAT | O_EXCL, 
			0644, data->number_of_fork);
	data->lock = sem_open("/lock", O_CREAT | O_EXCL, 0644, 0);
	data->fasting = sem_open("/fasting", O_CREAT | O_EXCL, 0644, 1);
	data->protect_eat = sem_open("/protect_eat", O_CREAT | O_EXCL, 0644, 1);
	data->print_lock = sem_open("/print_lock", O_CREAT | O_EXCL, 0644, 1);
	data->forks = sem_open("/forks", O_CREAT, 0644, data->number_of_fork);
	if (data->fasting == NULL || data->print_lock == NULL 
		|| data->forks == NULL || data->lock == NULL)
	{
		printf("Error: sem_open\n");
		exit(1);
	}
}

t_data	*create_data(char **av, int ac)
{
	int		i;
	t_data	*data;

	i = 0;
	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->number_of_philo = ft_atoi(av[1]);
	data->number_of_fork = ft_atoi(av[1]);
	data->time_die = ft_atoi(av[2]);
	data->time_eat = ft_atoi(av[3]);
	data->time_sleep = ft_atoi(av[4]);
	data->time = get_current_time();
	if (ac == 6)
		data->nt_eat = ft_atoi(av[5]);
	else
		data->nt_eat = -1;
	create_semaphores(data);
	return (data);
}
