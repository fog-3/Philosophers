/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mutex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fosuna-g <fosuna-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 11:58:38 by fosuna-g          #+#    #+#             */
/*   Updated: 2025/06/29 08:55:10 by fosuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

// Function used to print the status of every philosopher
void	print_status(t_philosopher *philo, const char *status)
{
	pthread_mutex_lock(&philo->data->print);
	printf("%ld %i %s\n", get_diff_time(philo->data->start_time),
		philo->id, status);
	pthread_mutex_unlock(&philo->data->print);
}

int	eval_status(t_philosopher *philo)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&philo->data->stop_mutex);
	if (philo->data->max_meals > 0
		&& philo->meal_count >= philo->data->max_meals)
	{
		if (!philo->have_eaten)
		{
			philo->have_eaten = 1;
			philo->data->num_philo_eaten++;
		}
		if (philo->data->num_philo_eaten == philo->data->num_philosophers)
			philo->data->stop_simulation = 1;
	}
	if (get_diff_time(philo->last_meal_time) > philo->data->time_to_die)
	{
		if (!philo->data->stop_simulation)
			print_status(philo, "died");
		philo->data->stop_simulation = 1;
	}
	i = philo->data->stop_simulation;
	pthread_mutex_unlock(&philo->data->stop_mutex);
	return (i);
}
