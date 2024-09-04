/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oer-refa <oer-refa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:43:22 by oer-refa          #+#    #+#             */
/*   Updated: 2024/09/01 09:45:37 by oer-refa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * ! this is how the input should be 5 800 200 200 [5] 
 * * 5 ===> is the number of how many philosophers.
 * * 800 ===> is the time to die.
 * * 200 ===> is the time to eat.
 * * 200 ===> is the time to sleep.
 * *[5] ===> is how many time the philo would eat.
 */
//TODO now what i need to do is to parse all of this.

int	main(int argc, char **argv)
{
	
	if (argc == 6 || argc == 5)
	{
		t_data data;
		t_philo philo;
		parcing(&data,argv);
		// //TODO 2) then i need to init the data to work with.
		data_init(&data, &philo);

		// //TODO 3) solver the philo problem.
		// solving_philos_problem(&data);
		
		// //TODO 4) clean everything no leaks allowed.
		// clean(&data);
		// printf("all good");
		
	}
	else
	{
		printf("arguments problem");
		//TODO make the exit function.
	}
}