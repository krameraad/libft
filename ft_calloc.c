/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekramer <ekramer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 17:05:22 by ekramer           #+#    #+#             */
/*   Updated: 2025/10/29 19:20:17 by ekramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*s;
	size_t	totalsize;

	totalsize = nmemb * size;
	if (totalsize == 0)
		return (malloc(0));
	if (totalsize / size != nmemb)
		return (NULL);
	s = malloc(totalsize);
	if (s == NULL)
		return (NULL);
	ft_bzero(s, totalsize);
	return (s);
}
