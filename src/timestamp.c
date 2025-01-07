/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timestamp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 16:04:32 by lleodev           #+#    #+#             */
/*   Updated: 2024/12/30 16:43:58 by lleodev          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "philo.h"

long    get_timestamp(void)
{
    struct timeval  time;
    long            timestamp;

    gettimeofday(&time, NULL);
    timestamp = time.tv_sec * 1000 + time.tv_usec / 1000;
    return (timestamp);
}

long    get_timestamp_interval(long initial_time, long current_time)
{
    return (current_time - initial_time);
}
