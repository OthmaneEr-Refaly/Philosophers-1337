/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_thread_handle.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oer-refa <oer-refa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 09:52:42 by oer-refa          #+#    #+#             */
/*   Updated: 2024/09/04 09:38:02 by oer-refa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


static void	handle_mutex_error(int status, t_opcode opcode)
{
	//TODO YOU NEED TO ADD THE ERROR_EXIT FUNCTION IN HERE
	//TODO AND DONT FOGRIT TO DESTROY THE MUTEXES.
	if ( status == 0)
		return;
	else if (status == EAGAIN && (opcode == LOCK || opcode == UNLOCK))
		printf("The mutex could not be acquired because the maximum number of recursive locks for mutex has been exceeded.");
	else if (status == ENOTRECOVERABLE && (opcode == LOCK || opcode == UNLOCK))
		printf("The state protected by the mutex is not recoverable.");
	else if (status == EOWNERDEAD && (opcode == LOCK || opcode == UNLOCK))
		printf("The state protected by the mutex is not recoverable.");
	else if (status == EINVAL && (opcode == LOCK || opcode == UNLOCK || opcode == DESTROY))
		printf("The state protected by the mutex is not recoverable.");
	else if (status == EAGAIN && (opcode == DESTROY))
		printf("The system lacked the necessary resources (other than memory) to initialize another mutex.");
	else if (status == ENOMEM)
		printf("Insufficient memory exists to initialize the mutex.");
	else if (status == EPERM)
		printf("The caller does not have the privilege to perform the operation.");
}


void	better_mutex_handle(t_mtx *mutex, t_opcode opcode)
{
	//TODO DONT FORGITE TO HANDLE THE MUTEX ERROR;
	
	if (LOCK == opcode)
		handle_mutex_error(pthread_mutex_lock(mutex), opcode);
	else if (UNLOCK == opcode)
		handle_mutex_error(pthread_mutex_unlock(mutex), opcode);
	else if (DESTROY == opcode)
		handle_mutex_error(pthread_mutex_destroy(mutex), opcode);
	else if (INIT == opcode)
		handle_mutex_error(pthread_mutex_init(mutex,NULL), opcode);
	else
		printf("mutex error");
}

static int	handle_thread_error(int status, t_opcode opcode)
{
	if (status == 0)
		return (0);
	if (status == EAGAIN)
		printf("Insufficient resources to create another thread.\n");
	else if (status == EINVAL)
	{
		if (opcode == JOIN)
			printf("Thread is not a joinable thread.\n");
		else if (opcode == CREATE)
			printf("Invalid settings in attr.\n");
		// else if (opcode == DETACH)
		// 	printf("Thread is not a valid thread object.\n");
	}
	else if (status == EPERM)
		printf("No permission to set the scheduling policy and parameters specified in attr.\n");
	else if (status == ESRCH)
		printf("No thread with the ID thread could be found.\n");
	else
		printf("Unknown error occurred.\n");
	return (1);
}

int	handle_thread_operation(pthread_t *thread, void *(*start_routine)(void *), void *arg, t_opcode opcode)
{
	int	status;

	if (opcode == JOIN)
		status = pthread_join(*thread, NULL);
	else if (opcode == CREATE)
		status = pthread_create(thread, NULL, start_routine, arg);
	// else if (opcode == DETACH)
	// 	status = pthread_detach(*thread);
	else
	{
		printf("Unknown thread operation\n");
		return (1);
	}
	return (handle_thread_error(status, opcode));
	// TODO IF YOU USED DETACH DONT FORGITE TO ADD IT HERE;
}