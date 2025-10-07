/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhammiou <hhammiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 19:08:06 by hhammiou          #+#    #+#             */
/*   Updated: 2025/10/06 10:37:57 by hhammiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_data{
	int				philo_num;
	int				t_die;
	int				t_eat;
	int				t_sleap;
	int				m_eat_num;
	size_t			start_t;
	int				sim_end;
	int				someone_died;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	sim_mutex;
	pthread_mutex_t	death_mutex;
}					t_data;

typedef struct s_philo{
	int				philo_id;
	int				nmeal;
	size_t			lastmeal_t;
	pthread_mutex_t	lastmeal_m;
	pthread_mutex_t	lfork;
	pthread_mutex_t	*rfork;
	pthread_t		thread;
	t_data			*data;
}					t_philo;

/*-----------*//*PARSING*//*------------*/
int		parsing(int ac, char **av);
long	ft_atol(const char *str);

/*-----------*//*INITALIZATION*//*------------*/
t_data	*data_init(int ac, char **av);
t_philo	*philo_init(t_data *data);
void	tr_create(t_philo *philo);
size_t	get_time(void);

/*-----------*//*ERRORS*//*------------*/
void	ft_msg_error(int i);

/*-----------*//*ROUTINE*//*------------*/
void	*philo_routine(void *av);
void	ft_check_death(t_philo *philos);
void	ft_sleep(t_philo *philo);
int		check_sim(t_philo *av);
void	ft_think(t_philo *philo);
void	ft_7t_forks(t_philo *philo);
void	ft_hz_forks(t_philo *philo);
void	ft_eat(t_philo *philo);
void	change_flag(t_philo *philo);
int		read_flag(t_philo *philo);
void	ft_print(t_philo *philo, char *str);
void	change_sim(t_philo *philo);

/*-----------*//*CLEAR*//*------------*/
void	ft_clear(t_philo *philo);

#endif