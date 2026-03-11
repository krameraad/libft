/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ekramer <ekramer@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/12/10 01:01:00 by ekramer       #+#    #+#                 */
/*   Updated: 2026/03/11 20:27:34 by ekramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned char	intlen(int n)
{
	unsigned char	count;

	if (n == 0)
		return (1);
	count = n < 0;
	n *= 1 + -2 * count;
	while (n)
	{
		n /= 10;
		++count;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char			*str;
	unsigned char	size;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = intlen(n);
	str = malloc(size + 1);
	if (str == NULL)
		return (NULL);
	str[size] = '\0';
	str[0] = '-' * (n < 0);
	n *= 1 + -2 * (n < 0);
	while (size && str[size - 1] != '-')
	{
		--size;
		str[size] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
