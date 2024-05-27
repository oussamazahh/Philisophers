/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:15:07 by ozahidi           #+#    #+#             */
/*   Updated: 2024/05/27 21:49:39 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*hdi_meaya(void *arg)
{
	t_philo	*philo;
	t_data	*data;
	sem_t	*check;
	
	int	i;
	int	j;
	int k;

	j = 0;
	k = 0;
	philo = (t_philo *)arg;
	data = philo->data;
	
	check = data->check;
	while (1)
	{
		i = 0;
		sem_wait(check);
		if (get_current_time() - philo->last_meal > philo->data->time_die)
		{
			printf("\e[32m%ld %d %s\n", get_current_time()
				- philo->data->time, philo->id, "is dead");
			sem_post(check);
			exit(1);
		}
		if (philo->eat == philo->data->nt_eat && philo->data->nt_eat != -1)
		{
			sem_post(check);
			exit(1);
		}
		sem_post(check);
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
		ft_sleep(philo, philo->data->time_eat);
		philo->last_meal = get_current_time();
		philo->eat++;
		sem_post(philo->data->forks);
		sem_post(philo->data->forks);
		display_message(philo, "is sleeping");
		ft_sleep(philo, philo->data->time_sleep);
	}
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
	pid = waitpid(0, NULL, 0);
	i = 0;
	if (pid > 0)
	{
		while (i < data->number_of_philo)
		{
			if (philo[i].id_p != pid)
			{
				kill(philo[i].id_p, SIGKILL);
			}
			i++;
		}
	}
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
