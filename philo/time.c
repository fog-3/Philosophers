/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 21:47:53 by fernando          #+#    #+#             */
/*   Updated: 2025/01/09 20:42:34 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// struct timeval {
//   time_t        tv_sec;   // Seconds
//   suseconds_t   tv_usec;  // microseconds
// };

void	wait(long time_to_sleep)
{
	long	wake_up_time;

	wake_up_time = get_time() + time_to_sleep;
	while (get_time() < wake_up_time)
		usleep(100);
}

uint64_t	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL))
		return (0);
	return ((time.tv_sec * (uint64_t)1000) + (time.tv_usec / 1000));
}

uint64_t	get_diff_time(uint64_t init_time)
{
	uint64_t	curr_time;
	
	curr_time = get_time();
	if (curr_time == 0)
		return (0);
	return (curr_time - init_time);
}
