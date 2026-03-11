/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putbase_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ekramer <ekramer@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/11 18:31:12 by ekramer       #+#    #+#                 */
/*   Updated: 2026/03/11 19:13:11 by ekramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putbase_fd(\
unsigned long long n, char const *base, unsigned int len, int fd)
{
	int	count;

	count = 0;
	if (n < len)
		return (ft_putchar_fd(base[n], fd));
	count += ft_putbase_fd(n / len, base, len, fd);
	count += ft_putbase_fd(n % len, base, len, fd);
	return (count);
}
