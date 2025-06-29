/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fosuna-g <fosuna-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 11:58:27 by fosuna-g          #+#    #+#             */
/*   Updated: 2025/06/29 09:04:33 by fosuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	num_fork(t_philosopher *philo, int num)
{
	int	res;

	res = 0;
	if (philo->id % 2 && num == 1)
		res = philo->left_fork;
	else if (philo->id % 2 && num == 2)
		res = philo->right_fork;
	else if (philo->id % 2 == 0 && num == 1)
		res = philo->right_fork;
	else if (philo->id % 2 == 0 && num == 2)
		res = philo->left_fork;
	return (res);
}

int	avoid_deadlock(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->data->stop_mutex);
	if (philo->data->num_philosophers == 1)
	{
		wait2(philo->data->time_to_die);
		print_status(philo, "died");
		philo->data->stop_simulation = 1;
		pthread_mutex_unlock(&philo->data->stop_mutex);
		return (0);
	}
	pthread_mutex_unlock(&philo->data->stop_mutex);
	return (1);
}

int	catch_forks(t_philosopher *philo)
{
	int	first_fork;
	int	second_fork;

	first_fork = num_fork(philo, 1);
	second_fork = num_fork(philo, 2);
	pthread_mutex_lock(&philo->data->forks[first_fork]);
	print_status(philo, "has taken a fork");
	if (eval_status(philo) || !avoid_deadlock(philo))
	{
		pthread_mutex_unlock(&philo->data->forks[first_fork]);
		return (0);
	}
	pthread_mutex_lock(&philo->data->forks[second_fork]);
	print_status(philo, "has taken a fork");
	if (eval_status(philo))
	{
		pthread_mutex_unlock(&philo->data->forks[first_fork]);
		pthread_mutex_unlock(&philo->data->forks[second_fork]);
		return (0);
	}
	return (1);
}
