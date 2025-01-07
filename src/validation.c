/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 15:37:35 by lleodev           #+#    #+#             */
/*   Updated: 2024/12/28 15:42:43 by lleodev          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "philo.h"

int is_num(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);   
}

int only_num(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (!is_num(str[i]))
            return (0);
        i++;
    }
    return (1);
}