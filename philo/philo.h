/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:15:30 by ozahidi           #+#    #+#             */
/*   Updated: 2024/05/23 21:25:51 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define EAT 1
# define SLEEP 2
# define THINK 3
# define DEAD 4
# define TAKE 5

typedef struct s_fork
{
	int				id;
	pthread_mutex_t	fork;
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
	size_t			time;
	t_fork			*forks;
	pthread_mutex_t	check;
}					t_data;

typedef struct s_philo
{
	int				id;
	int				die;
	int				sleep;
	int				eat;
	int				take;
	long			last_meal;
	t_fork			*l_fork;
	t_fork			*r_fork;
	pthread_t		philo;
	struct s_philo	*next;
	t_data			*data;
}					t_philo;

/* CHECK ARGUMENTS */
int					check_arg(char **av, int ac);

/* TABLE CREATE */
int					create_table(t_philo **philo, t_data **data, char **av,
						int ac);

/* CREATE DATA */
int					create_data(t_data **data, char **av, int ac);

/* CREATE PHILO */
int					create_treads(t_philo *philo);

/* PRINT FUNCTION */
int					display_message(t_philo *philo, int value);

/* TIME */
long				get_current_time(void);
int					ft_sleep(int time);

/* TOOLS */
int					ft_atoi(char *str);
int					*ft_memset(int *b, int c, size_t len);

#endif