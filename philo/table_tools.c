/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 19:22:37 by ozahidi           #+#    #+#             */
/*   Updated: 2024/05/18 21:05:20 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_lstadd_back(t_philo **philo, t_philo *new)
{
	t_philo	*cel;

	if (!philo || !new)
		return (1);
	if (*philo == NULL)
		*philo = new;
	else
	{
		cel = *philo;
		while (cel->next != NULL)
			cel = cel->next;
		cel->next = new;
	}
	return (0);
}

t_philo	*ft_lstnew(int nb, t_data *data_info)
{
	t_philo	*cel;

	cel = (t_philo *)malloc(sizeof(t_philo));
	if (!cel)
		return (NULL);
	cel->next = NULL;
    cel->id = nb;
	cel->eat = 0;
	cel->sleep = 0;
    cel->l_fork = 0;
    cel->r_fork = 0;
	cel->die = ALIVE;
	cel->data = data_info;
	return (cel);
}

void	ft_lstadd_front(t_philo **philo, t_philo *new)
{
	if (!philo || !new)
		return ;
	new->next = *philo;
	*philo = new;
}
