/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fosuna-g <fosuna-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:04:00 by fernando          #+#    #+#             */
/*   Updated: 2025/05/11 09:45:44 by fosuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

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
