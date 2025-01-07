/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 15:37:40 by lleodev           #+#    #+#             */
/*   Updated: 2024/12/31 11:22:57 by lleodev          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "philo.h"

int ft_atoi(char *str)
{
    int i;
    int num;
    int sign;

    i = 0;
    num = 0;
    sign = 1;
    while (str[i] == 32 || (str[i] > 9 && str[i] <= 13))
        i++;
    if (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            sign = -sign;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        num = num * 10 + str[i] - '0';
        i++;
    }
    return (num * sign);
}

void printf_philo(t_philo *philo)
{
    printf("num_philo: %d\n", philo->info->num_philo);
    printf("time_die: %d\n", philo->info->time_die);
    printf("time_eat: %d\n", philo->info->time_eat);
    printf("time_sleep: %d\n", philo->info->time_sleep);
    if (philo->info->num_philo == 6)
        printf("num_times_philo_eat: %d\n", philo->info->n_times_philo_eat);
}

void    print_status_log(char *message, long timestamp, int index, pthread_mutex_t *log_mutex)
{
    if (pthread_mutex_lock(log_mutex) == 0)
    {
        printf(message, timestamp,  index);
        pthread_mutex_unlock(log_mutex);
    }
}
