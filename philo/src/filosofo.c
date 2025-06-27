/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filosofo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fosuna-g <fosuna-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:33:56 by fernando          #+#    #+#             */
/*   Updated: 2025/06/27 12:42:33 by fosuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void    think(t_philosopher *philo)
{
	if (eval_status(philo))
		return ;
	print_status(philo, "is thinking");
}

void	eat(t_philosopher *philo)
{
	if (!catch_forks(philo))
		return ;
	pthread_mutex_lock(&philo->data->stop_mutex);
	philo->last_meal_time = get_time();
	philo->meal_count++;
	pthread_mutex_unlock(&philo->data->stop_mutex);
	print_status(philo, "is eating");
	wait(philo->data->time_to_eat, philo);
	pthread_mutex_unlock(&philo->data->forks[philo->left_fork]);
	pthread_mutex_unlock(&philo->data->forks[philo->right_fork]);
}

void    sleep_philo(t_philosopher *philo)
{
	if (eval_status(philo))
		return ;
	print_status(philo, "is sleeping");
	wait(philo->data->time_to_sleep, philo);
}

void	*philosopher_routine(void *arg)
{
	t_philosopher   *philo;
	
	philo = (t_philosopher  *) arg;
	while (!eval_status(philo))
	{
		eat(philo);
		sleep_philo(philo);
		think(philo);
	}
	return NULL;
}

int    start_philos(t_philosopher *philos, int n)
{
	int i;
	
	i = 0;
	while(i < n)
	{
		if (pthread_create(&philos[i].thread, NULL, philosopher_routine, &philos[i]) != 0)
		{
			write(2, "Error creando el hilo", 21);
			return (0);
		}
		i++;
	}
	i = 0;
	while (i < n)
	{
		pthread_join(philos[i].thread, NULL);
		i++;
	}
	ft_free(philos->data, &philos, NULL);
	return (1);
}
