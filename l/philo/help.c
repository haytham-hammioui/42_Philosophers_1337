/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhammiou <hhammiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 22:20:17 by hhammiou          #+#    #+#             */
/*   Updated: 2025/10/07 10:47:28 by hhammiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_sleep(t_philo *philo)
{
	size_t	end;

	ft_print(philo, "is sleeping");
	end = get_time() + philo->data->t_sleap;
	while (get_time() < end)
	{
		if (check_sim(philo))
			break ;
		usleep(200);
	}
}

void	ft_think(t_philo *philo)
{
	ft_print(philo, "is thinking");
}

void	ft_hz_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->lfork);
	ft_print(philo, "has taken a fork");
	pthread_mutex_lock(philo->rfork);
	ft_print(philo, "has taken a fork");
}

void	ft_7t_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->rfork);
	pthread_mutex_unlock(&philo->lfork);
}

void	ft_eat(t_philo *philo)
{
	size_t	end;

	ft_print(philo, "is eating");
	pthread_mutex_lock(&philo->lastmeal_m);
	philo->lastmeal_t = get_time();
	pthread_mutex_unlock(&philo->lastmeal_m);
	philo->nmeal++;
	end = get_time() + philo->data->t_eat;
	while (get_time() < end)
	{
		if (check_sim(philo))
			break ;
		usleep(200);
	}
}
