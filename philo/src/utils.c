/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:04:00 by fernando          #+#    #+#             */
/*   Updated: 2025/05/10 11:40:03 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

// Function used to print the status of every philosopher
void	print_status(t_philosopher *philo, const char *status)
{
	pthread_mutex_lock(&philo->data->print);
	printf("%ld %i %s\n", get_diff_time(philo->data->start_time), philo->id, status);
	pthread_mutex_unlock(&philo->data->print);
}

int	ft_atoi(const char *str)
{
	int	neg;
	int	res;
	int	i;
	
	i = 0;
	neg = 1;
	res = 0;
	if (str[i] == '\n' || str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '-')
		neg *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		res += (res * 10) + (str[i] - '0');
	res *= neg;
	return (res);
}
