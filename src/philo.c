/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 15:02:02 by lleodev           #+#    #+#             */
/*   Updated: 2024/12/31 11:18:04 by lleodev          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "philo.h"

int main(int argc, char *argv[])
{
    t_circle_table *circle_table;

    if (argc == 5 || argc == 6)
    {
        if (validate_args(argc, argv))
        {
            circle_table = (t_circle_table *)malloc(sizeof(t_circle_table));
            circle_table->num_philo = ft_atoi(argv[1]);
            circle_table->philo_die = 0;
            pthread_mutex_init(&circle_table->philo_die_mutex, NULL);
            pthread_mutex_init(&circle_table->log_mutex, NULL);
            circle_table->info = init_philo_info(argc, argv, 0);
            circle_table->philosophers = init_philosophers(circle_table->num_philo, argc, argv);
            circle_table->fork = init_fork(circle_table->num_philo);
            create_pthreads(circle_table, run_thread_simulation);
            wait_pthreads(circle_table);
        }
        else
            printf("Non numeric param\n");
    }
    return (0);
}
