/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oer-refa <oer-refa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:58:40 by oer-refa          #+#    #+#             */
/*   Updated: 2024/09/07 15:45:09 by oer-refa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <stdbool.h>
# include <limits.h>
# include <sys/time.h> // this library to use the function gettimeofday();
# include <errno.h>



// 5 800 200 200 [5]


/**
 * ? enum to set a cutom data type with fixed set of names and values
 */
typedef enum 	e_opcode
{
				INIT,
				LOCK,
				UNLOCK,
	// DETACH;
				DESTROY,
				CREATE,
				JOIN,
}				t_opcode;


typedef struct s_data t_data;


/**
 * ?Struct for the mutex of the forks
 */
typedef pthread_mutex_t t_mtx;


/**
 * ?Fork Struct
 */
typedef	struct 	s_fork
{
	t_mtx		fork;
	int			fork_id;
}				t_fork;


/**
 * ?Philo Struct.
 */
typedef struct 	s_philo
{
	int			philo_id;
	long		nbr_of_meals;
	bool		full;
	long		last_meal_time;
	t_fork		*right_fork;
	t_fork 		*left_fork;
	pthread_t	thread_id; /*cuz every philo is a thread*/
	t_data		*data;
}				t_philo;


/**
 * ?Data struct
 */
struct 	s_data
{
	long		number_of_philosophers;
	long		time_to_die;
	long		time_to_eat;
	long		time_to_sleep;
	long		number_of_times_each_philosopher_must_eat;
	t_fork		*forks;
	t_philo		*philos;
};



/**
 * !!!!!!!!Prototypess!!!!!!!!
 */


/**
 * *Helper functions
 */
static	long	ft_atol(const char *av);
size_t			ft_strlen(const char *str);


/**
 * *Input functions*
 */
void				parcing(t_data *data, char **argv);
static const char 	*valid_input(const char *av);


/**
 * *Data init functions
 */
int		data_init(t_data *data, t_philo *philo);
void	here(t_data *data, t_philo philo);
static void	forks_assign(t_philo *philo,t_fork *fork, int fork_index);
static void	philos_init(t_data *data, t_philo *philo);

/**
 * *Threads and Mutex functions
 */
int			better_mutex_handle(t_mtx *mutex, t_opcode opcode);
int			better_threads_handle(pthread_t *threads, t_opcode opcode);
int			handle_thread_operation(pthread_t *thread, void *(*start_routine)(void *), void *arg, t_opcode opcode);
static int	handle_thread_error(int status, t_opcode opcode);
static int	handle_mutex_error(int status, t_opcode opcode);

/**
 * *Error handling functions
 */
void	malloc_error(t_data *data);
int error_here(t_data *data);

/**
 * *Algorithms functions
 */
void	solving_philos_problem(t_data *data);

#endif