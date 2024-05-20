/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:39:49 by ozahidi           #+#    #+#             */
/*   Updated: 2024/05/20 12:10:02 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t get_current_time(void)
{
    struct timeval tv;

    gettimeofday(&tv, NULL);
    return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int ft_sleep(int time)
{
    size_t start;

    start = get_current_time();
    while (get_current_time() - start < time)
        usleep(100);
    return (1);
}
