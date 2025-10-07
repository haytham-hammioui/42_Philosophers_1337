/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhammiou <hhammiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 13:25:25 by hhammiou          #+#    #+#             */
/*   Updated: 2025/06/22 21:35:47 by hhammiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	read_flag(t_philo *philo)
{
	int	flag;

	pthread_mutex_lock(&philo->data->death_mutex);
	flag = philo->data->someone_died;
	pthread_mutex_unlock(&philo->data->death_mutex);
	return (flag);
}

void	change_flag(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->death_mutex);
	philo->data->someone_died = 1;
	pthread_mutex_unlock(&philo->data->death_mutex);
}

int	check_sim(t_philo *av)
{
	int	sim_status;

	pthread_mutex_lock(&av->data->death_mutex);
	sim_status = av->data->sim_end;
	pthread_mutex_unlock(&av->data->death_mutex);
	return (sim_status);
}

void	change_sim(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->sim_mutex);
	philo->data->sim_end = 1;
	pthread_mutex_unlock(&philo->data->sim_mutex);
}
