/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oer-refa <oer-refa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 11:36:23 by oer-refa          #+#    #+#             */
/*   Updated: 2024/09/07 08:59:17 by oer-refa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	data_init(t_data *data, t_philo *philo)
{
	long i = 0;
	data->philos = malloc (sizeof(t_philo) * (data->number_of_philosophers));
	if (data->philos == NULL)
		return(-1);
	//TODO FREE
	data->forks = malloc (sizeof(t_fork) * (data->number_of_philosophers)); 
	if (data->forks == NULL)
		malloc_error(data);
	//TODO FREE
	while(i < data->number_of_philosophers)
	{
		if (better_mutex_handle(&(data->forks[i].fork), INIT) == -1)
			return (-1);
		data->forks[i].fork_id = i;
		i++;
	}
	philos_init(data,philo);
	return (0);
}

static void	philos_init(t_data *data, t_philo *philo)
{
	int i;

	i = 0;
	while(i < data->number_of_philosophers)
	{
		philo = data->philos + i;
		philo->philo_id = i + 1;
		philo->nbr_of_meals = 0;
		philo->full = false;
		philo->data = data;
		forks_assign(philo,data->forks,i);
		// printf("philo id is ==> %d\nthe number of meals is ==> %ld\nis he full ==>%d\n",philo->philo_id,philo->nbr_of_meals,philo->full);
		i++;
	}
}

static void	forks_assign(t_philo *philo,t_fork *fork, int fork_index)
{
	/**
	 * * In this function i have used the EVEN and ODD thing to prevent the deadlock
	 * * So the ODD numbered philosophers will reach there left fork first
	 * * and the EVEN numbered philosophers will reach there right fork first.
	 */
	
	/**
	 * ? First fork is the left one.
	 * ? Seacond gork is the right one.
	*/

	if (philo->philo_id % 2 == 0) //ODD OR EVEN NUMBER 
	{
		philo->left_fork = &fork[fork_index];
		philo->right_fork = &fork[(fork_index + 1) % philo->data->number_of_philosophers];
	}
	else
	{
		philo->right_fork = &fork[fork_index];
		philo->left_fork = &fork[(fork_index + 1) % philo->data->number_of_philosophers];
	}
}