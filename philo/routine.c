/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhammiou <hhammiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 22:12:25 by hhammiou          #+#    #+#             */
/*   Updated: 2025/06/22 21:15:42 by hhammiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void *av)
{
	t_philo	*philo;

	philo = (t_philo *)av;
	if (philo->philo_id % 2 == 0)
		ft_sleep(philo);
	while (!check_sim(philo))
	{
		ft_think(philo);
		ft_hz_forks(philo);
		ft_eat(philo);
		ft_7t_forks(philo);
		ft_sleep(philo);
		if (philo->data->m_eat_num != -1 
			&& philo->nmeal >= philo->data->m_eat_num)
		{
			change_flag(philo);
			break ;
		}
	}
	return (NULL);
}
