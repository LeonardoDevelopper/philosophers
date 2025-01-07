/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 15:02:13 by lleodev           #+#    #+#             */
/*   Updated: 2024/12/31 12:45:26 by lleodev          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>

typedef struct s_philo_info
{
    int             index;
    int             num_philo;
    int             time_die;
    int             time_eat;
    int             time_sleep;
    int             last_time_eat;
    int             quant_eaten;
    int             n_times_philo_eat;
}   t_philo_info;

typedef struct s_philo
{
    t_philo_info    *info;
    pthread_t       thread;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;
}   t_philo;

typedef struct s_circle_table
{
    int             num_philo;
    int             philo_die;
    t_philo_info    *info;
    t_philo         **philosophers;
    pthread_mutex_t *fork;
    pthread_mutex_t *log_mutex;
    pthread_mutex_t philo_die_mutex;
}   t_circle_table;

typedef struct s_philo_fork
{
    t_philo         *philo;
    pthread_mutex_t *fork;
}   t_philo_fork;

typedef struct s_pthread_info
{
    t_circle_table *circle_table;
    t_philo         *philo;
}   t_pthread_info;

t_philo_info    *init_philo_info(int argc, char **args, int index);
t_philo         **init_philosophers(int num_philos, int argc, char **argv);

pthread_mutex_t *init_fork(int num_philo);

void            create_pthreads(t_circle_table *circle_table, void *(* fun)(void *));
void            *run_thread_simulation(void *philo_info);
void            free_circle_table(t_circle_table *circle_table);
void            free_philosophers(t_philo **philos);
void            wait_pthreads(t_circle_table *circle_table);

void            philo_thinking(t_philo *philo, long initial_timestamp, pthread_mutex_t *log_mutex);
void            philo_eating(t_philo *philo, t_circle_table *circle_table, long initial_timestamp, int initial_time_die);
void            philo_sleeping(t_philo *philo, long initial_timestamp, pthread_mutex_t *log_mutex);
void            print_status_log(char *message, long timestamp, int index, pthread_mutex_t *log_mutex);

int             philo_get_fork(t_philo *philo, t_circle_table *circle_table, long timestamp);

long            get_timestamp(void);
long            get_timestamp_interval(long initial_time, long current_time);

int             philo_die(t_circle_table *circle_table, t_philo *philo, long initial_timestamp);
int             validate_args(int num, char **args);
int             only_num(char *str);
int             is_num(char c);
int             ft_atoi(char *str);
int             *sort_list(int* lst, int (*cmp)(int, int));

void printf_philo(t_philo *philo);

#endif
