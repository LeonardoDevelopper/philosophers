/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 15:28:04 by lleodev           #+#    #+#             */
/*   Updated: 2024/12/30 16:23:03 by lleodev          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "philo.h"

t_philo_info *init_philo_info(int argc, char **args, int index)
{
    t_philo_info *info;

    info = (t_philo_info *)malloc(sizeof(t_philo_info));
    if (!info)
        return (NULL);
    info->index = index;
    info->num_philo = ft_atoi(args[1]);
    info->time_die = ft_atoi(args[2]);
    info->time_eat = ft_atoi(args[3]);
    info->time_sleep = ft_atoi(args[4]);
    info->quant_eaten = 0;
    info->last_time_eat = 0;
    if (argc > 5)
        info->n_times_philo_eat = ft_atoi(args[5]);
    else
        info->n_times_philo_eat = 0;
    return (info);
}

t_philo  **init_philosophers(int num_philos, int argc, char **argv)
{
    int             i;
    t_philo         **philos;

    i = 0;
    philos = (t_philo **)malloc(sizeof(t_philo *) * (num_philos + 1));
    philos = memset(philos, sizeof(t_philo *), num_philos);
    while (i < num_philos)
    {
        philos[i] = (t_philo *)malloc(sizeof(t_philo));
        philos[i]->info = init_philo_info(argc, argv, i);
        philos[i]->left_fork = NULL;
        philos[i]->right_fork = NULL;
        i++;
    }
    return (philos);
}

pthread_mutex_t *init_fork(int num_philo)
{
    int i;
    pthread_mutex_t *fork;

    i = 0;
    fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * num_philo);
    if (!fork)
        return (NULL);
    while (i < num_philo)
    {
        pthread_mutex_init(&fork[i], NULL);
        i++;
    }
    return (fork);
}