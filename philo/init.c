/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhammiou <hhammiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 21:21:04 by hhammiou          #+#    #+#             */
/*   Updated: 2025/10/06 10:40:16 by hhammiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_data	*data_init(int ac, char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (ft_msg_error(2), NULL);
	data->philo_num = (int)ft_atol(av[1]);
	data->t_die = (int)ft_atol(av[2]);
	data->t_eat = (int)ft_atol(av[3]);
	data->t_sleap = (int)ft_atol(av[4]);
	if (ac == 6)
		data->m_eat_num = (int)ft_atol(av[5]);
	else
		data->m_eat_num = -1;
	data->sim_end = 0;
	data->someone_died = 0;
	data->start_t = get_time();
	if (pthread_mutex_init(&data->print_mutex, NULL) != 0
		|| pthread_mutex_init(&data->sim_mutex, NULL) != 0
		|| pthread_mutex_init(&data->death_mutex, NULL) != 0)
	{
		free(data);
		return (ft_msg_error(3), NULL);
	}
	return (data);
}

t_philo	*philo_init(t_data *data)
{
	t_philo	*philos;
	int		i;

	philos = malloc(sizeof(t_philo) * data->philo_num);
	if (!philos)
	{
		free(data);
		return (ft_msg_error(4), NULL);
	}
	i = 0;
	while (i < data->philo_num)
	{
		philos[i].philo_id = i + 1;
		philos[i].nmeal = 0;
		philos[i].data = data;
		philos[i].lastmeal_t = data->start_t;
		pthread_mutex_init(&philos[i].lfork, NULL);
		pthread_mutex_init(&philos[i].lastmeal_m, NULL);
		if (i > 0)
			philos[i - 1].rfork = &philos[i].lfork;
		i++;
	}
	philos[data->philo_num - 1].rfork = &philos[0].lfork;
	return (philos);
}

void	tr_create(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->data->philo_num)
	{
		pthread_create(&philo[i].thread, NULL, philo_routine, &philo[i]);
		i++;
	}
	ft_check_death(philo);
	if (philo->data->philo_num > 1)
	{
		i = 0;
		while (i < philo->data->philo_num)
		{
			pthread_join(philo[i].thread, NULL);
			i++;
		}
	}
	i = 0;
	while (i < philo->data->philo_num)
	{
		pthread_detach(philo[i].thread);
		i++;
	}
}
