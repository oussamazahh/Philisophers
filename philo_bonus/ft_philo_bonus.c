/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:15:07 by ozahidi           #+#    #+#             */
/*   Updated: 2024/05/27 10:51:08 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	philo_routine(t_philo *philo, t_data *data)
{
	while (1)
	{
		sem_wait(philo->data->forks);
		if (display_message(philo, "has taken a fork"))
			exit (1);
		sem_wait(philo->data->forks);
		if (display_message(philo, "has taken a fork"))
			exit (1);
		if (philo->eat >= philo->data->nt_eat)
			break ;
		if (display_message(philo, "is eating"))
			exit (1);
		sem_wait(philo->data->check);
		// if (get_current_time() - philo->last_meal > philo->data->time_die)
		// 	break ;
		philo->last_meal = get_current_time();
		if (philo->eat != philo->data->nt_eat)
			philo->eat++;
		sem_post(philo->data->check);
		if (ft_sleep(philo, philo->data->time_eat))
			exit(1);
		sem_post(philo->data->forks);
		sem_post(philo->data->forks);
		if (display_message(philo, "is sleeping"))
			exit(1);
		if (ft_sleep(philo, philo->data->time_sleep))
			exit(1);
		if (display_message(philo, "is thinking"))
			exit(1);
	}
	exit(1);
}

void	*create_processes(t_philo	*philo)
{
	t_data	*data;
	int	i;

	i = 0;
	data = philo->data;
	while (i < data->number_of_philo)
	{
		philo[i].id_p = fork();
		if (philo[i].id_p == 0)
			if (philo_routine(&philo[i], data))
				break ;
		i++;
	}
	waitpid(-1, NULL, 0);
	i = 0;
	while (i < data->number_of_philo)
		kill(philo[i++].id_p, SIGKILL);
	return (NULL);
}
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
	sem_unlink("check2");
	check = sem_open("check2", O_CREAT, 0644, 1);
	while (1)
	{
		i = 0;
		sem_wait(check);
		while (i < philo->data->number_of_philo)
		{
			if (get_current_time() - philo->last_meal > philo->data->time_die)
			{
				philo->data->kill = 1;
				printf("%ld %d %s\n", get_current_time()
					- philo->data->time, philo->id, "is dead");
				while (i < data->number_of_philo)
					kill(philo[i++].id_p, SIGKILL);
				exit(1);
			}
			if (philo[k].eat == philo->data->nt_eat )
			{
				j++;
				k++;
			}
			if (j == philo->data->number_of_philo)
			{
				philo->data->kill = 1;
				printf("allo");
				printf("%ld %d %s\n", get_current_time()
					- philo->data->time, philo->id, "is dead");
				while (k < data->number_of_philo)
					kill(philo[k++].id_p, SIGKILL);
				exit(1);
			}
			i++;
		}
		sem_post(check);
		// if (philo->eat == philo->data->nt_eat 
		// 	|| get_current_time() - philo->last_meal > philo->data->time_die)
		// {
		// 	// int i;
		// 	philo->die = 1;
		// 	// display_message(&philo[i], "is dead");
		// 	printf("%ld %d %s\n", get_current_time()
		// - philo->data->time, philo->id, "is dead");
		// 		// i = 0;
		// 		// while (i < data->number_of_philo)
		// 		while (i < data->number_of_philo)
		// kill(philo[i++].id_p, SIGKILL);
		// 		// 	kill(philo[i].id_p, SIGKILL);
		// 		exit(1);
		// }
	}
	
	return (NULL);
}

void	thread_scanner(t_philo *philo, t_data *data)
{
	pthread_t	khedama;

	create_processes(philo);
	pthread_create(&khedama, NULL, hdi_meaya, (void *)philo);
	pthread_join(khedama, NULL);
	return ;
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
