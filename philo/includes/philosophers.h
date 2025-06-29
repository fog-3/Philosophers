/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fosuna-g <fosuna-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 12:52:56 by fernando          #+#    #+#             */
/*   Updated: 2025/06/28 12:17:02 by fosuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

/* Structuts */
typedef struct s_data
{
	int				num_philosophers;
	int				num_philo_eaten;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				max_meals;
	long			start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	stop_mutex;
	int				stop_simulation;
}	t_data;

typedef struct s_philosopher
{
	int				id;
	pthread_t		thread;
	int				left_fork;
	int				right_fork;
	long			last_meal_time;
	int				meal_count;
	int				have_eaten;
	struct s_data	*data;
}	t_philosopher;

/** Time functions **/
long int	get_time(void);
void		wait(long time_to_sleep, t_philosopher *philo);
void		wait2(long time_to_sleep);
long int	get_diff_time(long int init_time);
long		intget_time(void);

/** Utils **/
int			ft_atoi(const char *str);
void		print_status(t_philosopher *philo, const char *status);
int			ft_strlen(const char *str);

/** Error functions **/
void		err_msg_args(void);
void		ft_free(t_data *data, t_philosopher **phil, char *msg);
int			eval_params(t_data *data);
int			cmp_atoi(char *str);

/*** Philosophers functions ***/
void		*philosopher_routine(void *arg);
int			start_philos(t_philosopher *philos, int n);
void		think_aux(t_philosopher *philo);
int			eval_status(t_philosopher *philo);
int			catch_forks(t_philosopher *philo);

#endif
