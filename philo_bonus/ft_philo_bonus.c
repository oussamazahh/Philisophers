/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:15:07 by ozahidi           #+#    #+#             */
/*   Updated: 2024/05/30 13:13:59 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*hdi_meaya(void *arg)
{
	t_philo	*philo;
	long 	start_time;

	philo = (t_philo *)arg;
	while (1)
	{
		sem_wait(philo->data->fasting);
		start_time = get_current_time();
		if (start_time - philo->last_meal >= philo->data->time_die)
		{
			sem_wait(philo->data->print_lock);
			printf("\e[31m%ld %d %s\n", get_current_time()
				- philo->data->time, philo->id, "is dead");
			sem_post(philo->data->fasting);
			exit(0);
		}
		sem_post(philo->data->fasting);
	}
	return (NULL);
}
// ./philo_bonus 20 300 60 60 2 
// ./philo_bonus 200 200 60 60 
int	philo_routine(t_philo *philo, t_data *data)
{
	pthread_t	monitor;
	sem_wait(philo->data->enter);
	philo->last_meal = get_current_time();
	philo->data->time = get_current_time();
	pthread_create(&monitor, NULL, hdi_meaya, philo);
	if (philo->eat != -1 )
	{
		while ((philo->eat != -1 && philo->eat > 0))
		{
			display_message(philo, "is thinking");
			sem_wait(philo->data->forks);
			sem_wait(philo->data->forks);
			display_message(philo, "has taken a fork");
			display_message(philo, "has taken a fork");
			display_message(philo, "is eating");
			philo->last_meal = get_current_time();
			ft_sleep(philo, philo->data->time_eat);
			if (philo->eat != -1)
				philo->eat--;
			sem_post(philo->data->forks);
			sem_post(philo->data->forks);
			display_message(philo, "is sleeping");
			ft_sleep(philo, philo->data->time_sleep);
			usleep(100);
		}
	}
	else
	{
		while (1)
		{
			display_message(philo, "is thinking");
			sem_wait(philo->data->forks);
			sem_wait(philo->data->forks);
			display_message(philo, "has taken a fork");
			display_message(philo, "has taken a fork");
			display_message(philo, "is eating");
			philo->last_meal = get_current_time();
			ft_sleep(philo, philo->data->time_eat);
			if (philo->eat != -1)
				philo->eat--;
			sem_post(philo->data->forks);
			sem_post(philo->data->forks);
			display_message(philo, "is sleeping");
			ft_sleep(philo, philo->data->time_sleep);
			usleep(100);
		}
	}
	sem_post(philo->data->enter);
	exit (0);
}

void	start_routine(t_philo	*philo)
{
	sem_wait(philo->data->start);
	philo_routine(philo, philo->data);
}
void	*create_processes(t_philo	*philo)
{
	t_data	*data;
	int	i;
	int	pid;
	

	i = 0;
	data = philo->data;
	sem_unlink("/enter");
	philo->data->enter = sem_open("/enter", O_CREAT | O_EXCL, 0644, philo->data->number_of_philo);
	if (philo->data->enter == NULL)
	{
		printf("Error: sem_open\n");
		exit(1);
	}
	sem_unlink("/start");
	philo->data->start = sem_open("/start", O_CREAT | O_EXCL, 0644, 0);
	if (philo->data->start == NULL)
	{
		printf("Error: sem_open\n");
		exit(1);
	}
	while (i < data->number_of_philo)
	{
		philo[i].id_p = fork();
		if (philo[i].id_p == 0)
		{
			start_routine(&philo[i]);
		}
		if (philo[i].id_p < 0)
			return (NULL);
		i++;
	}
	while (i-- > 0)
	{
		sem_post(philo->data->start);
	}
	while (waitpid(0, NULL, 0) > 0)
	{
		i = 0;
		while(i < data->number_of_philo)
		{
			kill(philo[i++].id_p, SIGKILL);
		}
	}
	sem_unlink("/forks");
	sem_unlink("/print_lock");
	sem_unlink("/start");
	sem_unlink("/fasting");
	sem_close(data->print_lock);
	sem_close(data->forks);
	sem_close(data->start);
	sem_close(data->fasting);
	return (NULL);
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
		create_processes(philo);
	}
}
