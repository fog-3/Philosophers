
#include "../includes/philosophers.h"


// Function used to print the status of every philosopher
void	print_status(t_philosopher *philo, const char *status)
{
	pthread_mutex_lock(&philo->data->print);
	printf("%ld %i %s\n", get_diff_time(philo->data->start_time), philo->id, status);
	pthread_mutex_unlock(&philo->data->print);
}

int	eval_status(t_philosopher *philo)
{
	int res;

	res = 0;
	pthread_mutex_lock(&philo->data->stop_mutex);
	if (get_diff_time(philo->last_meal_time) > philo->data->time_to_die ||
		philo->data->stop_simulation || (philo->data->max_meals > 0 &&
		philo->meal_count >= philo->data->max_meals))
	{
		if (get_diff_time(philo->last_meal_time) > philo->data->time_to_die)
		{
			print_status(philo, "died");
			philo->data->stop_simulation = 1;
		}
		res = 1;
	}
	pthread_mutex_unlock(&philo->data->stop_mutex);
	return (res);
}
