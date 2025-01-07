/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 09:29:35 by lleodev           #+#    #+#             */
/*   Updated: 2024/12/30 16:21:56 by lleodev          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "philo.h"

void    free_circle_table(t_circle_table *circle_table)
{
    if (circle_table)
    {
        if (circle_table->philosophers)
            free_philosophers(circle_table->philosophers);
        if (circle_table->fork)
            free(circle_table->fork);
        free(circle_table);
    }
}
void free_philosophers(t_philo **philos)
{
    int i;

    i = 0;
    while (philos[i])
    {
        free(philos[i]->info);
        free(philos[i]);
    }
    free(philos);
}
