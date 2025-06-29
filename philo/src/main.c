/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fosuna-g <fosuna-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 20:29:33 by fernando          #+#    #+#             */
/*   Updated: 2025/06/29 08:57:52 by fosuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	init_struct(char **argv, t_data *data)
{
	int	n;
	int	i;

	i = 0;
	n = cmp_atoi(argv[1]);
	data->num_philosophers = n;
	data->num_philo_eaten = 0;
	data->time_to_die = cmp_atoi(argv[2]);
	data->time_to_eat = cmp_atoi(argv[3]);
	data->time_to_sleep = cmp_atoi(argv[4]);
	data->forks = (pthread_mutex_t *)malloc(n * sizeof(pthread_mutex_t));
	while (i < n)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			return (-1);
		i++;
	}
	if (pthread_mutex_init(&data->print, NULL) != 0)
		return (-1);
	if (pthread_mutex_init(&data->stop_mutex, NULL) != 0)
		return (-1);
	data->stop_simulation = 0;
	n = eval_params(data);
	return (n);
}

void	init_philos(t_data *global_data)
{
	t_philosopher	*philos;
	int				n;
	int				i;

	n = global_data->num_philosophers;
	philos = (t_philosopher *)malloc(n * sizeof(t_philosopher));
	global_data->start_time = get_time();
	i = 0;
	while (i < n)
	{
		philos[i].id = i + 1;
		philos[i].left_fork = i;
		philos[i].right_fork = (i + 1) % n;
		philos[i].last_meal_time = global_data->start_time;
		philos[i].meal_count = 0;
		philos[i].have_eaten = 0;
		philos[i].data = global_data;
		i++;
	}
	start_philos(philos, n);
}

int	main(int argc, char *argv[])
{
	t_data			global_data;

	if (argc == 5 || argc == 6)
	{
		if (init_struct(argv, &global_data) < 0)
		{
			ft_free(&global_data, NULL, "bad initialization");
			return (-1);
		}
		global_data.max_meals = -1;
		if (argc == 6)
			global_data.max_meals = ft_atoi(argv[5]);
		init_philos(&global_data);
	}
	else
		err_msg_args();
	return (0);
}
