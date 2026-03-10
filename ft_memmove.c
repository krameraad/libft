/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ekramer <ekramer@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/07 11:52:49 by ekramer       #+#    #+#                 */
/*   Updated: 2026/01/24 02:52:19 by ekramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*p_dest;
	const char	*p_src;

	if (dest <= src)
		return (ft_memcpy(dest, src, n));
	p_dest = dest;
	p_src = src;
	while (n-- > 0)
		p_dest[n] = p_src[n];
	return (dest);
}
