/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhammiou <hhammiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 15:56:20 by hhammiou          #+#    #+#             */
/*   Updated: 2025/10/06 10:39:44 by hhammiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_msg_error(int i)
{
	if (i == 1)
		write(2, "Error: invalid arguments\n", 26);
	else if (i == 2)
		write(2, "Error: malloc failed (data)\n", 28);
	else if (i == 3)
		write(2, "Error: failed to initialize mutex\n", 34);
	else if (i == 4)
		write(2, "Error: malloc failed (philosophers)\n", 36);
}

int	ft_is_digit(char *str)
{
	int	i;

	i = 0;
	if (!str || !*str)
		return (0);
	if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

long	ft_atol(const char *str)
{
	int		i;
	int		s;
	long	r;

	i = 0;
	s = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = -1;
		i++;
	}
	r = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + (str[i] - '0');
		if (r * s > INT_MAX || r * s < INT_MIN)
			return ((long)INT_MAX + 1);
		i++;
	}
	return (r * s);
}

int	parsing(int ac, char **av)
{
	int		i;
	long	num;

	if (ac != 5 && ac != 6)
		return (ft_msg_error(1), 1);
	i = 1;
	while (i < ac)
	{
		if (!ft_is_digit(av[i]))
			return (ft_msg_error(1), 1);
		num = ft_atol(av[i]);
		if (num <= 0 || num > INT_MAX)
			return (ft_msg_error(1), 1);
		i++;
	}
	return (0);
}
