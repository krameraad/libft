/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putunbr_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ekramer <ekramer@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/24 22:14:04 by ekramer       #+#    #+#                 */
/*   Updated: 2026/03/11 19:13:28 by ekramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putunbr_fd(unsigned int n, int fd)
{
	int	count;

	count = 0;
	if (n < 10)
		return (ft_putchar_fd(n + '0', fd));
	count += ft_putunbr_fd(n / 10, fd);
	count += ft_putunbr_fd(n % 10, fd);
	return (count);
}
