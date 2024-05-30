/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:15:30 by ozahidi           #+#    #+#             */
/*   Updated: 2024/05/30 12:59:33 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
#include <semaphore.h>
#include <signal.h>

# define EAT 1
# define SLEEP 2
# define THINK 3
# define DEAD 4
# define TAKE 5

typedef struct s_fork
{
	int				id;
	sem_t			*fork;
}					t_fork;

typedef struct s_data
{
	int				nt_eat;
	int				number_of_philo;
	int				number_of_fork;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				kill;
	int				id_kill;
	long			time;
	sem_t			*enter;//sup
	sem_t			*forks;
	sem_t			*start;
	sem_t			*fasting;
	sem_t			*print_lock;
}					t_data;

typedef struct s_philo
{
	int				id;
	int				id_p;
	int				eat;
	long			last_meal;
	t_fork			*l_fork;
	t_fork			*r_fork;
	pthread_t		philo;
	t_data			*data;
}					t_philo;

/* CHECK ARGUMENTS */
int					check_arg(char **av, int ac);

/* TABLE CREATE */
t_philo*					create_table(t_data *data, char **av,
						int ac);

/* CREATE DATA */
t_data*					create_data(char **av, int ac);

/* CREATE PHILO */
int					create_threads(t_philo *philo);
int					_death_note(void *param);

/* DESTROY MUTEX */
void				destroy_mutex(t_philo *philo);

/* PRINT FUNCTION */
int					display_message(t_philo *philo, char *value);

/* TIME */
long				get_current_time(void);
int					ft_sleep(t_philo *philo, int time);

/* TOOLS */
int					ft_atoi(char *str);
int					*ft_memset(int *b, int c, size_t len);

#endif