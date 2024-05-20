/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:15:07 by ozahidi           #+#    #+#             */
/*   Updated: 2024/05/20 12:02:36 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// number_of_philosophers | time_to_die time_to_eat | time_to_sleep
// [number_of_times_each_philosopher_must_eat

// timestamp_in_ms X has taken a fork
// ◦ timestamp_in_ms X is eating
// ◦ timestamp_in_ms X is sleeping
// ◦ timestamp_in_ms X is thinking
// ◦ timestamp_in_ms X died
void print(t_philo *philo)
{
    while (philo)
    {
        printf("id %d\n", philo->id);
        philo = philo->next;
    }
    
}

int main (int ac, char **av)
{
    t_philo *philo;
    t_data *data;

    if (ac != 5 && ac != 6)
    {
        printf ("to run <<./philo>> flow next step:\n");
        printf ("./phile [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep]\n");
        printf ("You can add [number_of_times_each_philosopher_must_eat]\n");
        return (1);
    }
    else
    {
        philo = NULL;
        if (check_arg(av, ac) == 1)
            return (printf("Error : incorrect argument\n"),1);
        if (create_table(&philo, &data, av, ac))
            return (1);
        if (taking_forks(&philo))
            return (1);
    }
    
}