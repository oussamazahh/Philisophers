/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:24:36 by ozahidi           #+#    #+#             */
/*   Updated: 2024/05/18 22:42:11 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int   create_table(t_philo **philo, t_data **data, char **av, int ac)
{
    int i;

    i = 1;
    (void)ac;
    if (create_data(data, av, ac))
        return (1);
    if (ac == 6)
        (*data)->number_of_times_each_philosopher_must_eat = ft_atoi (av[5]);
    while (i <= ft_atoi(av[1]))
    {
        if (ft_lstadd_back(philo, ft_lstnew(i , *data)))
            return (1);
        i++;
    }
    return (0);
}
