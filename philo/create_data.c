/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 19:34:46 by ozahidi           #+#    #+#             */
/*   Updated: 2024/05/20 12:08:15 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int create_data(t_data **data, char **av, int ac)
{
    (void)ac;
    (*data) = malloc(sizeof(t_data));
    if (!data)
        return (1);
    (*data)->number_of_philo = ft_atoi(av[1]);
    (*data)->number_of_fork = ft_atoi(av[1]);
    (*data)->time_die = ft_atoi(av[2]);
    (*data)->time_eat = ft_atoi(av[3]);
    (*data)->time_sleep = ft_atoi(av[4]);
    (*data)->time = get_current_time();
    (*data)->forks = malloc(sizeof(int) * ((*data)->number_of_fork));
    if (!((*data)->forks))
        return (1);
    (*data)->forks = ft_memset((*data)->forks, 0, (*data)->number_of_fork);
    return (0);
}