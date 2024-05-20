/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:08:44 by ozahidi           #+#    #+#             */
/*   Updated: 2024/05/16 19:17:17 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int check_arg(char **av, int ac)
{
    int i;
    int j;

    i = 1;
    while (i < ac && av[i])
    {
        j = 0;
        while (av[i][j])
        {
            if (!ft_isdigit(av[i][j]))
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}
