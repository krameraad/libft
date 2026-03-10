/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putptr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ekramer <ekramer@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/24 22:20:25 by ekramer       #+#    #+#                 */
/*   Updated: 2026/01/24 03:25:07 by ekramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putptr_fd(unsigned long long n, int fd)
{
	if (n == 0)
		return (write(fd, "(nil)", 5));
	return (write(fd, "0x", 2) + ft_puthex_fd(n, false, fd));
}
