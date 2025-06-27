/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fosuna-g <fosuna-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 20:36:15 by fernando          #+#    #+#             */
/*   Updated: 2025/06/25 13:24:41 by fosuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

/* Function that print some error mensages when the arguments are wrong */
void err_msg_args()
{
	write(2, "\n*================ \e[1;31mERROR\e[0m: Incorrect Arguments", 56);
	write(2, " =================*\n\n You must to pass to the program:\n", 55);
	write(2, "\t\e[36m- Number of philosophers\e[0m: is the number of\n", 53);
	write(2, "\t  philosophers and the number of forks.\n", 41);
	write(2, "\t\e[36m- Time to die (in miliseconds)\e[0m: if a philoso", 54);
	write(2, "pher\n\t  does not start eating in this time he will die.\n", 56);
	write(2, "\t\e[36m- Time to eat (in miliseconds)\e[0m: the ", 46);
	write(2, "time that has a\n\t  philosopher to eat. \n", 40);
	write(2, "\t\e[36m- Time to sleep (in miliseconds)\e[0m:", 43);
	write(2, " the time of a\n", 15);
	write(2, "\t  philosopher to sleep.\n", 25);
	write(2, " Optionally you can pass to the program:\n", 41);
	write(2, "\t\e[36m- Number of times each philosopher must eat\e[0m:", 54);
	write(2, " if all\n", 8);
	write(2, "\t  eat at least this number of times to stop the\n", 49);
	write(2, "\t  simulation. If is not specified, the simulation\n", 51);
	write(2, "\t  will stop with the death of a philosopher.\n", 46);
	write(2, "\n Example of use:\n", 18);
	write(2, "\t\e[36m./philo 5 800 200 200 5\e[0m\n\n", 35);
}

void	ft_free(t_data *data, t_philosopher **phil, char *msg)
{
	int i;

	i = 0;
	if (msg != NULL)
		printf("\e[1;31mError\e[0m: %s\n", msg);
	if (phil != NULL && *phil != NULL)
	{
		free(*phil);
        *phil = NULL;
	}
	if (data != NULL)
	{
		if (data->forks != NULL)
		{
			while (i < data->num_philosophers)
				pthread_mutex_destroy(&data->forks[i++]);
			free(data->forks);
			data->forks = NULL;
		}
		pthread_mutex_destroy(&data->print);
		pthread_mutex_destroy(&data->stop_mutex);
	}		
}

int	eval_params(t_data *data)
{
	int	res;

	res = 0;
	if (data->time_to_sleep < 0 || data->time_to_die < 0 ||
		data->time_to_eat < 0 || data->num_philosophers <= 0)
	{
		res = -1;
	}
	return (res);
}

int	cmp_atoi(char *str)
{
	int res;
	int	i;

	res = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			res = -1;
		i++;
	}
	if (!res)
		res = ft_atoi(str);
	return (res);
}
