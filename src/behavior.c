/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   behavior.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 09:24:33 by lleodev           #+#    #+#             */
/*   Updated: 2024/12/31 17:07:23 by lleodev          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "philo.h"

void *run_thread_simulation(void *data)
{
    t_philo *philo;
    t_pthread_info *info;
    long initial_timestamp;

    info = (t_pthread_info *)data;
    philo = info->philo;
    initial_timestamp = get_timestamp();
    while (1)
    {
        long current_timestamp = get_timestamp();
        if (philo_die(info->circle_table, philo, (current_timestamp - initial_timestamp)))
            break ;
        else
        {
            if (philo_get_fork(philo, info->circle_table, ((current_timestamp - initial_timestamp))))
                philo_eating(philo, info->circle_table, ((current_timestamp - initial_timestamp)), 200);
            philo_sleeping(philo, (current_timestamp - initial_timestamp), &info->circle_table->log_mutex);
            philo_thinking(philo, (current_timestamp - initial_timestamp), &info->circle_table->log_mutex);
        }
    }
    return (NULL);
}



void philo_thinking(t_philo *philo, long timestamp, pthread_mutex_t *log_mutex)
{
    printf("\033[38;5;213m%ld %d is thinking\n\033[0m", timestamp, (philo->info->index + 1), log_mutex);
}

void philo_eating(t_philo *philo, t_circle_table *circle_table, long timestamp, int time_die)
{
    printf("\033[1;33m%ld %d is eating\033[0m\n", timestamp, (philo->info->index + 1), &circle_table->log_mutex);
    usleep(philo->info->time_eat * 1000);
    philo->info->last_time_eat = timestamp;
    pthread_mutex_unlock(philo->left_fork);
    pthread_mutex_unlock(philo->right_fork);
}

void philo_sleeping(t_philo *philo, long timestamp, pthread_mutex_t *log_mutex)
{
    printf("\033[1;34m%ld %d is sleeping\033[0m\n", timestamp, (philo->info->index + 1), log_mutex);
    usleep(philo->info->time_sleep * 1000);
}

int philo_die(t_circle_table *circle_table, t_philo *philo, long timestamp)
{
    if (pthread_mutex_lock(&circle_table->philo_die_mutex) == 0)
    {
        if (circle_table->philo_die)
        {
            printf("\033[1;31m%ld %d is dead\033[0m\n", timestamp,
                (philo->info->index + 1), &circle_table->log_mutex);
            pthread_mutex_unlock(&circle_table->philo_die_mutex);
            return 1;
        }
        if ((timestamp - philo->info->last_time_eat) >= philo->info->time_die)
        {
            printf("\033[1;31m%ld %d is dead\033[0m\n", timestamp,
                (philo->info->index + 1), &circle_table->log_mutex);
            circle_table->philo_die = 1;
            pthread_mutex_unlock(&circle_table->philo_die_mutex);
            return 1;
        }
        pthread_mutex_unlock(&circle_table->philo_die_mutex);
    }
    return 0;
}

int    philo_get_fork(t_philo *philo, t_circle_table *circle_table, long timestamp)
{
    philo->left_fork = &circle_table->fork[philo->info->index];
    philo->right_fork = &circle_table->fork[(philo->info->index + 1) % philo->info->num_philo];

    if (philo->info->index % 2 == 0)
    {
        if (pthread_mutex_lock(philo->left_fork) == 0)
        {
            printf("\033[1;32m%ld %d has taken a fork\033[0m\n",
                timestamp, (philo->info->index + 1), &circle_table->log_mutex);
            if (pthread_mutex_lock(philo->right_fork) == 0)
                return (printf("\033[1;32m%ld %d has taken a fork\033[0m\n",
                    timestamp, (philo->info->index + 1), &circle_table->log_mutex), 1);
            pthread_mutex_unlock(philo->left_fork);
        }
    }
    else
    {
        if (pthread_mutex_lock(philo->right_fork) == 0)
        {
            printf("\033[1;32m%ld %d has taken a fork\033[0m\n",
                timestamp, (philo->info->index + 1), &circle_table->log_mutex);
            if (pthread_mutex_lock(philo->left_fork) == 0)
                return (printf("\033[1;32m%ld %d has taken a fork\033[0m\n",
                    timestamp, (philo->info->index + 1), &circle_table->log_mutex), 1);
            pthread_mutex_unlock(philo->right_fork);
        }
    }
    return (0);
}
