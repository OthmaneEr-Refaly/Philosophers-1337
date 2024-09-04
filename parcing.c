/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oer-refa <oer-refa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 15:04:50 by oer-refa          #+#    #+#             */
/*   Updated: 2024/08/31 12:12:32 by oer-refa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// 5 800 200 200 [5]
void	parcing(t_data *data, char **argv)
{
	data->number_of_philosophers = ft_atol(argv[1]);
	data->time_to_die= ft_atol(argv[2]) * 1e3; //multiplication to convert it from MS to MicS to use it in the USLEEP / 1e3 is the same as *1000
	data->time_to_eat = ft_atol(argv[3]) * 1e3;
	data->time_to_sleep = ft_atol(argv[4]) * 1e3;
	
	if (data->time_to_die < data->time_to_eat + data->time_to_sleep)
	{
		printf("3tihom wa9t");
		exit(1);
	}
	if (data->time_to_die < 6e4 || data->time_to_eat < 6e4 || data->time_to_sleep < 6e4)
	{
		//TODO make the error functions here;
		printf("the timeset should not be lower then 60ms\n");
	}
	if (argv[5])
		data->number_of_times_each_philosopher_must_eat = ft_atol(argv[5]);
	else
		data->number_of_times_each_philosopher_must_eat = -1;
}
static	long	ft_atol(const char *av)
{
	long	res = 0;
	
	av = valid_input(av);
	if (ft_strlen(av) > 10)
		exit(1);
	while(*av >= '0' && *av <= '9')
		res = res * 10 + (*av++ - '0');
	if (res > INT_MAX)
	{
		printf("Error\nThe limit is INT MAX");
		exit(1);
	}
	return(res);
}

/**
 * ! in valid input we need to check :
 * ? if the number is negative ?
 * ? check 0 ?
 * ? empty ?
 * ? if the number is true number "   +898&&%" ✅  "  +%$@898" 👎 ?
 * ? if its above the int max ?
 * * the function should return a pointer to the number 
 */
static const char *valid_input(const char *av)
{
	const char *number;
	if (*av == '0')
	{
		printf("0 falisifa ?");
		exit(1);
	}
	while(*av == ' ' || *av == '\t' || *av == '\n'
		|| *av == '\r' || *av == '\v' || *av == '\f' || *av == '+')
		av++;
	if (*av == '-')
	{
		printf("NO negiative numbers are allowed");
		exit(1);
	}
	else if (!(*av >= '0' && *av <= '9'))
	{
		printf("Not a Number");
		exit(1);
	}
	else if (*av == '\0')
	{
		printf("empty string");
		exit(1);
	}
	number = av;
	return(number);
}