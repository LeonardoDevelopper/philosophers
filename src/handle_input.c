/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 15:02:08 by lleodev           #+#    #+#             */
/*   Updated: 2024/12/28 15:39:22 by lleodev          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "philo.h"

int validate_args(int num, char **args)
{
	int	i;

	i = 1;
	while (i < num)
	{
		if (!only_num(args[i]))
			return (0);
		i++;
	}
	return (1);
}
