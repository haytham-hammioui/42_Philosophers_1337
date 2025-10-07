/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhammiou <hhammiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 13:26:50 by hhammiou          #+#    #+#             */
/*   Updated: 2025/10/07 10:49:38 by hhammiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	get_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

size_t	read_lastmeal_t(t_philo *philo)
{
	size_t	t;

	pthread_mutex_lock(&philo->lastmeal_m);
	t = philo->lastmeal_t;
	pthread_mutex_unlock(&philo->lastmeal_m);
	return (t);
}

void	ft_check_death(t_philo *philos)
{
	int	i;

	while (1337)
	{
		i = 0;
		while (philos->data->philo_num > i)
		{
			if (read_flag(philos))
				return ;
			if ((get_time() - read_lastmeal_t(&philos[i])) 
				> (size_t)philos->data->t_die)
			{
				ft_print(&philos[i], "died");
				return ;
			}
			i++;
		}
	}
}

void	ft_print(t_philo *philo, char *str)
{
	size_t	t;

	pthread_mutex_lock(&philo->data->print_mutex);
	if (!check_sim(philo))
	{
		t = get_time() - philo->data->start_t;
		printf("%zu %d %s\n", t, philo->philo_id, str);
		if (str[0] == 'd' && str[1] == 'i' && str[2] == 'e'
			&& str[3] == 'd' && str[4] == '\0')
			change_sim(philo);
	}
	pthread_mutex_unlock(&philo->data->print_mutex);
}

void	ft_clear(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->data->philo_num)
	{
		pthread_mutex_destroy(&philo[i].lfork);
		pthread_mutex_destroy(&philo[i].lastmeal_m);
		i++;
	}
	pthread_mutex_destroy(&philo->data->death_mutex);
	pthread_mutex_destroy(&philo->data->sim_mutex);
	pthread_mutex_destroy(&philo->data->print_mutex);
	free(philo->data);
	free(philo);
}
