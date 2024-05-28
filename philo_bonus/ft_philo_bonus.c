/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:15:07 by ozahidi           #+#    #+#             */
/*   Updated: 2024/05/28 19:45:59 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*hdi_meaya(void *arg)
{
	t_philo	*philo;
	int	i;

	philo = (t_philo *)arg;
	while (1)
	{
		i = 0;
		sem_wait(philo->data->check);
		if (get_current_time() - philo->last_meal >= philo->data->time_die)
		{
			sem_wait(philo->data->death_note);
			printf("\e[31m%ld %d %s\n", get_current_time()
				- philo->data->time, philo->id, "is dead");
			exit(0);
		}
		sem_post(philo->data->check);
		if (philo->eat == philo->data->nt_eat && philo->data->nt_eat != -1)
		{
			sem_wait(philo->data->time_e);
			exit(0);
		}
	}
	return (NULL);
}

int	philo_routine(t_philo *philo, t_data *data)
{
	pthread_t	monitor;
	
	pthread_create(&monitor, NULL, hdi_meaya, philo);
	while (1)
	{
		display_message(philo, "is thinking");
		sem_wait(philo->data->forks);
		display_message(philo, "has taken a fork");
		sem_wait(philo->data->forks);
		display_message(philo, "has taken a fork");
		display_message(philo, "is eating");
		philo->last_meal = get_current_time();
		ft_sleep(philo, philo->data->time_eat);
		philo->eat++;
		sem_post(philo->data->forks);
		sem_post(philo->data->forks);
		display_message(philo, "is sleeping");
		ft_sleep(philo, philo->data->time_sleep);
	}
	return (0);
}

void	*create_processes(t_philo	*philo)
{
	t_data	*data;
	int	i;
	int	pid;

	i = 0;
	data = philo->data;
	while (i < data->number_of_philo)
	{
		philo[i].id_p = fork();
		if (philo[i].id_p == 0)
		{
			philo_routine(&philo[i], data);
		}
		if (philo[i].id_p < 0)
			return (NULL);
		i++;
	}
	i = 0;
	while (waitpid(0, NULL, 0) > 0)
	{
		i = 0;
		while(i < data->number_of_philo )
			kill(philo[i++].id_p, SIGKILL);
	}
	sem_post(data->death_note);
	sem_close(data->died);
	sem_close(data->forks);
	sem_close(data->death_note);
	sem_close(data->check);
	return (NULL);
}

void	thread_scanner(t_philo *philo, t_data *data)
{
	create_processes(philo);
}

int	main(int ac, char **av)
{
	t_philo	*philo;
	t_data	*data;

	if (ac != 5 && ac != 6)
	{
		printf("to run <<./philo_bonus>> flow next step:\n");
		printf("./phile [number_of_philosophers] ");
		printf("[time_to_die] [time_to_eat] [time_to_sleep]\n");
		printf("You can add [number_of_times_each_philosopher_must_eat]\n");
		return (1);
	}
	else
	{
		philo = NULL;
		if (check_arg(av, ac) == 1)
			return (printf("Error : incorrect argument\n"), 1);
		data = create_data(av, ac);
		philo = create_table(data, av, ac);
		thread_scanner(philo, data);
	}
}
