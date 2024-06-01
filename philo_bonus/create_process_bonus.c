/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_process_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 19:49:37 by ozahidi           #+#    #+#             */
/*   Updated: 2024/06/01 19:58:34 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_clean(t_data *data)
{
	sem_close(data->enter);
	sem_close(data->protect);
	sem_close(data->print_lock);
	sem_close(data->forks);
	sem_close(data->start);
	sem_close(data->fasting);
	sem_unlink("/forks");
	sem_unlink("/print_lock");
	sem_unlink("/start");
	sem_unlink("/fasting");
	sem_unlink("/enter");
	sem_unlink("/protect");
}

void	init_start(sem_t *start)
{
	sem_unlink("/start");
	start = sem_open("/start", O_CREAT | O_EXCL, 0644, 0);
	if (start == NULL)
	{
		printf("Error: sem_open\n");
		exit(1);
	}
}

void	create_processes(t_philo *philo)
{
	int	i;
	int	pid;

	i = 0;
	init_start(philo->data->start);
	while (i < philo->data->number_of_philo)
	{
		philo[i].id_p = fork();
		if (philo[i].id_p == 0)
			start_routine(&philo[i]);
		if (philo[i].id_p < 0)
			return ;
		i++;
	}
	while (i-- > 0)
		sem_post(philo->data->start);
	while (waitpid(0, NULL, 0) > 0)
	{
		i = 0;
		while (i < philo->data->number_of_philo)
			kill(philo[i++].id_p, SIGKILL);
	}
	ft_clean(philo->data);
}
