/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 17:00:49 by lleodev           #+#    #+#             */
/*   Updated: 2024/12/30 17:47:06 by lleodev          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "philo.h"

void    create_pthreads(t_circle_table *circle_table, void *(*fun)(void *))
{
    int i;
    t_pthread_info   *info;

    i = 0;
    while(circle_table->philosophers[i])
    {
        info = (t_pthread_info *)malloc(sizeof(t_pthread_info));
        info->philo = circle_table->philosophers[i];
        info->circle_table = circle_table;
        pthread_create(&circle_table->philosophers[i]->thread, NULL, fun, info);
        i++;
    }
    
}

void wait_pthreads(t_circle_table *circle_table)
{
    int i;

    i = 0;
    while (i < circle_table->num_philo)
    {
        pthread_join(circle_table->philosophers[i]->thread, NULL);
        i++;
    }
}