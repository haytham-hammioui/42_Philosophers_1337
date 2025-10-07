/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhammiou <hhammiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 19:07:54 by hhammiou          #+#    #+#             */
/*   Updated: 2025/10/07 12:06:29 by hhammiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	*data;
	t_philo	*philo;

	if (parsing(ac, av))
		return (1);
	data = data_init(ac, av);
	if (!data)
		return (1);
	philo = philo_init(data);
	if (!philo)
		return (1);
	tr_create(philo);
	ft_clear(philo);
	return (0);
}
