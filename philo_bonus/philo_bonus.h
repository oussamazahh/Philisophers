/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:15:30 by ozahidi           #+#    #+#             */
/*   Updated: 2024/07/09 22:17:17 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_fork
{
	int			id;
	sem_t		*fork;
}				t_fork;

typedef struct s_data
{
	int			nt_eat;
	int			number_of_philo;
	int			number_of_fork;
	int			time_die;
	int			time_eat;
	int			time_sleep;
	long		time;
	sem_t		*forks;
	sem_t		*start;
	sem_t		*fasting;
	sem_t		*print_lock;
	sem_t		*lock;
	sem_t		*protect_meal;
	sem_t		*protect_eat;
}				t_data;

typedef struct s_philo
{
	int					id;
	int					id_p;
	int					eat;
	long				last_meal;
	t_fork				*l_fork;
	t_fork				*r_fork;
	pthread_t			philo;
	t_data				*data;
}				t_philo;

/* CHECK ARGUMENTS */
int				check_arg(char **av, int ac);

/* TABLE CREATE */
t_philo			*create_table(t_data *data);

/* CREATE DATA */
t_data			*create_data(char **av, int ac);

/* CREATE PROCESS PHILO */
void			create_processes(t_philo *philo);

/* PHILO ROUTINE */
int				philo_routine(t_philo *philo, t_data *data);

/* CREATE THREAD  SCANNER*/
void			create_thread(pthread_t *monitor,
					void *(*routine)(void *),
					t_philo *philo);

/* DEATH SCANNER */
void			*death_scanner(void *arg);

/* PRINT FUNCTION */
int				display_message(t_philo *philo, char *value);

/* TIME */
long			get_current_time(void);
int				ft_sleep(t_philo *philo, int time);

/* EXTRA TOOLS */
int				ft_atoi(char *str);
int				*ft_memset(int *b, int c, size_t len);
long			last_meal(t_philo *philo, int update);
#endif