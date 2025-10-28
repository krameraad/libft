/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekramer <ekramer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 12:48:03 by ekramer           #+#    #+#             */
/*   Updated: 2025/10/27 14:26:39 by ekramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// @return Index of the first character in `s` that isn't `c`.
static size_t	skip_char(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] == c)
		i++;
	return (i);
}

// @return Index of the first character in `s` which is the same as `c`.
static size_t	find_next(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

// @return Number of words in `s`, using `c` as a delimiter.
static size_t	wordcount(char const *s, char c)
{
	size_t	count;

	count = 0;
	s += skip_char(s, c);
	while (*s != '\0')
	{
		count++;
		s += find_next(s, c);
		s += skip_char(s, c);
	}
	return (count);
}

/* Free all strings in array `strs`.
Assumes the array ends with a `NULL` pointer. */
static void	freeall(char **strs)
{
	size_t	i;

	i = 0;
	while (strs[i] != NULL)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	size_t	len;
	size_t	i;

	strs = malloc((wordcount(s, c) + 1) * sizeof(char *));
	if (strs == NULL)
		return (NULL);
	s += skip_char(s, c);
	len = find_next(s, c);
	i = 0;
	while (len != 0)
	{
		strs[i] = ft_substr(s, 0, len);
		if (strs[i] == NULL)
		{
			freeall(strs);
			return (NULL);
		}
		s += len;
		s += skip_char(s, c);
		len = find_next(s, c);
		i++;
	}
	strs[i] = NULL;
	return (strs);
}
