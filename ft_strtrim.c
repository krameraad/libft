/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekramer <ekramer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 14:35:49 by ekramer           #+#    #+#             */
/*   Updated: 2025/10/28 20:16:27 by ekramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char const	*find_trimstart(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (set[j])
	{
		if (s1[i] == set[j])
		{
			j = 0;
			i++;
		}
		else
			j++;
	}
	return (s1 + i);
}

static size_t	find_trimend(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	if (*s1 == '\0')
		return (1);
	i = ft_strlen(s1) - 1;
	j = 0;
	while (i >= 0 && set[j])
	{
		if (s1[i] == set[j])
		{
			j = 0;
			if (i)
				i--;
		}
		else
			j++;
	}
	return (i + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	size;

	s1 = find_trimstart(s1, set);
	size = find_trimend(s1, set);
	str = malloc(size + 1);
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s1, size + 1);
	return (str);
}
