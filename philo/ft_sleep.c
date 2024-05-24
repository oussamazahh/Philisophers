/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:39:49 by ozahidi           #+#    #+#             */
/*   Updated: 2024/05/24 17:49:22 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_current_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int	ft_sleep(t_philo *philo, int time)
{
	long	start;
	int		kill;

	start = get_current_time();
	kill = philo->data->kill;
	while (get_current_time() - start < time)
	{
		if (kill == 1)
			return (1);
		usleep(100);
	}
	return (0);
}
