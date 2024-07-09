/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_process_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 19:49:37 by ozahidi           #+#    #+#             */
/*   Updated: 2024/06/28 19:23:38 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_clean(t_data *data)
{
	sem_close(data->print_lock);
	sem_close(data->forks);
	sem_close(data->fasting);
	sem_unlink("/forks");
	sem_unlink("/print_lock");
	sem_unlink("/fasting");
}

void	create_processes(t_philo *philo)
{
	int	i;

	i = 0;
	philo->data->time = get_current_time();
	while (i < philo->data->number_of_philo)
	{
		philo[i].id_p = fork();
		if (philo[i].id_p == 0)
			philo_routine(&philo[i], philo[i].data);
		if (philo[i].id_p < 0)
			return ;
		i++;
	}
	i = 0;
	if (waitpid(0, NULL, 0) > 0)
	{
		i = 0;
		while (i < philo->data->number_of_philo)
			kill(philo[i++].id_p, SIGKILL);
	}
	ft_clean(philo->data);
}
