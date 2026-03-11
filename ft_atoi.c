/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ekramer <ekramer@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/17 13:12:54 by ekramer       #+#    #+#                 */
/*   Updated: 2026/03/11 19:35:04 by ekramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	total;
	int	i;

	total = 0;
	i = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == 32)
		++i;
	sign = 1 + -2 * (str[i] == '-');
	i += str[i] == '-' || str[i] == '+';
	while (str[i] >= '0' && str[i] <= '9')
		total = total * 10 + str[i++] - '0';
	return (total * sign);
}
