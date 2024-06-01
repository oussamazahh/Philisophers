/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_data_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 19:34:46 by ozahidi           #+#    #+#             */
/*   Updated: 2024/06/01 20:25:19 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	create_semaphores(t_data *data)
{
	sem_unlink("/fasting");
	sem_unlink("/print_lock");
	sem_unlink("/forks");
	sem_unlink("/protect");
	sem_unlink("/enter");
	data->fasting = sem_open("/fasting", O_CREAT | O_EXCL, 0644, 1);
	data->print_lock = sem_open("/print_lock", O_CREAT | O_EXCL, 0644, 1);
	data->forks = sem_open("/forks", O_CREAT, 0644, data->number_of_fork);
	data->protect = sem_open("/protect", O_CREAT | O_EXCL, 0644,
			data->number_of_philo);
	data->enter = sem_open("/enter", O_CREAT | O_EXCL, 0644,
			data->number_of_philo);
	if (data->fasting == NULL || data->print_lock == NULL || data->forks == NULL
		|| data->protect == NULL || data->enter == NULL)
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
	data->kill = 0;
	data->id_kill = 0;
	if (ac == 6)
		data->nt_eat = ft_atoi(av[5]);
	else
		data->nt_eat = -1;
	create_semaphores(data);
	return (data);
}
