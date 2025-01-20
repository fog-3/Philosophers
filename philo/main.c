/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 20:29:33 by fernando          #+#    #+#             */
/*   Updated: 2025/01/02 20:34:42 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int main(int argc, char *argv[])
{
	uint64_t	init_time;

	if (argc == 5 || argc == 6)
	{
		
		
		/* init_time = get_time();
		sleep(2);
		printf("Milliseconds of the program: %ld\n", get_diff_time(init_time)); */
	}
	else
		err_msg_args();
	return (0);
}
