/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 21:47:53 by fernando          #+#    #+#             */
/*   Updated: 2025/05/10 11:39:58 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

// struct timeval {
//   time_t        tv_sec;   // Seconds
//   suseconds_t   tv_usec;  // microseconds
// };

/* It's a sleep function with a better control of the millisecond that pass */
void	wait(long time_to_sleep)
{
	long	wake_up_time;

	wake_up_time = get_time() + time_to_sleep;
	while (get_time() < wake_up_time)
		usleep(100);
}

/* It gives the miliseconds pased since 1970 */
long int	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL))
		return (0);
	return ((long int)(time.tv_sec * 1000) + (time.tv_usec / 1000));
}

/* It returns the miliseconds between the time passed by argument and
 the actual time */
long int	get_diff_time(long int init_time)
{
	long int	curr_time;
	
	curr_time = get_time();
	if (curr_time == 0)
		return (0);
	return (curr_time - init_time);
}
