/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekramer <ekramer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 22:15:40 by ekramer           #+#    #+#             */
/*   Updated: 2025/11/24 22:18:34 by ekramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puthex_fd(unsigned long long n, char lettercase, int fd)
{
	int		count;

	count = 0;
	if (n < 16)
	{
		if (n < 10)
			return (ft_putchar_fd(n + '0', fd));
		if (lettercase == UPPERCASE)
			return (ft_putchar_fd(n - 10 + 'A', fd));
		return (ft_putchar_fd(n - 10 + 'a', fd));
	}
	count += ft_puthex_fd(n / 16, lettercase, fd);
	count += ft_puthex_fd(n % 16, lettercase, fd);
	return (count);
}
