/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filosofo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:33:56 by fernando          #+#    #+#             */
/*   Updated: 2025/02/23 17:44:57 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void    think(t_philosopher *philo)
{
    //Comprobamos toda la vain: stop_simulation, max_meals, last_meal_time, meal_count;
}

void    eat(t_philosopher *philo)
{
    pthread_mutex_lock(&philo->data->forks[philo->left_fork]);
    print_status(philo, "has taken a fork");
    pthread_mutex_lock(&philo->data->forks[philo->right_fork]);
    print_status(philo, "has taken a fork");
    print_status(philo, "is eating");
    wait(philo->data->time_to_eat);
    pthread_mutex_unlock(&philo->data->forks[philo->left_fork]);
    pthread_mutex_unlock(&philo->data->forks[philo->right_fork]);
}

void    sleep_philo(t_philosopher *philo)
{
    print_status(philo, "is sleeping");
    wait(philo->data->time_to_sleep);
}

void	*philosopher_routine(void *arg)
{
	t_philosopher   *philo;
    
    philo = (t_philosopher  *) arg;
    while (!philo->data->stop_simulation)
    {
        eat(philo);
        sleep_philo(philo);
        think(philo);
    }
    return NULL;
}

void    start_philos(t_philosopher *philos, int n)
{
	int i;
    pthread_t th_philo;
    
    i = 0;
    while(i < n)
    {
        th_philo = philos[i].thread;
        if (pthread_create(&th_philo, NULL, philosopher_routine, &philos[i]) != 0)
        {
            write(2, "Error creando el hilo", 21);
            return (0);
        }
        i++;
    }
    i = 0;
    while (i < n)
    {
        th_philo = philos[i].thread;
        pthread_join(th_philo, NULL);
    }
    return (1);
}
