/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:15:30 by ozahidi           #+#    #+#             */
/*   Updated: 2024/05/20 12:10:47 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>

typedef struct s_data
{
	int				number_of_times_each_philosopher_must_eat;
	int				number_of_philo;
	int				number_of_fork;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				*forks;
	size_t			time;
	pthread_mutex_t mutex;
}					t_data;

typedef struct s_philo
{
	int				id;
	int				die;
	int				sleep;
	int				eat;
	int				l_fork;
	int				r_fork;
	pthread_t 		philo;
	struct s_philo	*next;
	t_data			*data;
}					t_philo;


#define DIE -1;
#define ALIVE 0;

/* CHECK ARGUMENTS */
int 	check_arg(char **av, int ac);

/* TABLE CREATE */
int   create_table(t_philo **philo, t_data **data, char **av, int ac);
int	create_data(t_data **data, char **av, int ac);
int taking_forks(t_philo **philo);

/* TOOLS FOR LINKED LIST */
int		ft_lstadd_back(t_philo **philo, t_philo *new);
void	ft_lstadd_front(t_philo **philo, t_philo *new);
t_philo	*ft_lstnew(int nb, t_data *data_info);

/* TIME */
size_t get_current_time(void);
int 	ft_sleep(int time);

/* TOOLS */
int		ft_atoi(char *str);
int	*ft_memset(int *b, int c, size_t len);
#endif