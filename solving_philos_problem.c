/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solving_philos_problem.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oer-refa <oer-refa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 10:00:58 by oer-refa          #+#    #+#             */
/*   Updated: 2024/09/07 15:53:39 by oer-refa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//TODO IN THIS FUNCTION I NEED TO SYNC THE START OF ALL THE THREADS/PHILOS.
//TODO AND I NEED TO MAKE ENDLESS LOOP TO WAIT FOR THE THREADS TO FINISH.


void	eating(t_data *data)
{
	int i;

	printf("here2\n");
	i = 100;
	while(i < data->time_to_eat)
	{
		printf("eating time is ==> %d\n",i);
		i++;
	}
}
void	*dinnig_simulation(void *data)
{
	eating(data);
	printf("error here2");
}
void	solving_philos_problem(t_data *data)
{
	int i;

	if (data->number_of_times_each_philosopher_must_eat == 0) //if the number of time to eat is 0, it means that there is no need to eat 
		printf("error here");
	if (data->number_of_philosophers == 1) //TODO when there is only one philosopher, this should be handled.
		printf("error here");
	while(i < data->number_of_philosophers)
	{
		handle_thread_operation(&data->philos[i].philo_id, dinnig_simulation, &data->philos[i], CREATE);
		i++;
	}
}