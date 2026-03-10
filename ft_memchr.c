/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ekramer <ekramer@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/09 14:10:32 by ekramer       #+#    #+#                 */
/*   Updated: 2026/01/24 02:57:37 by ekramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*p;
	size_t		i;

	p = s;
	i = 0;
	while (i < n)
	{
		if (p[i] == (char)c)
			return ((char *)p + i);
		i++;
	}
	return (NULL);
}
