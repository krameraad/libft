/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ekramer <ekramer@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/12/10 01:37:14 by ekramer       #+#    #+#                 */
/*   Updated: 2026/01/24 02:10:19 by ekramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// @return Number of words in `s`, using `c` as a delimiter.
static size_t	wordcount(char const *s, char c)
{
	size_t	count;
	size_t	len;

	count = 0;
	while (*s == c)
		s++;
	while (*s != '\0')
	{
		count++;
		len = (size_t)ft_strchr(s, c);
		s += len - (size_t)s * !!len + ft_strlen(s) * !len;
		while (*s == c)
			s++;
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
	while (*s == c)
		s++;
	len = (size_t)ft_strchr(s, c);
	len -= (size_t)s * !!len + ft_strlen(s) * !len;
	i = 0;
	while (len != 0)
	{
		strs[i] = ft_substr(s, 0, len);
		if (strs[i] == NULL)
			return (freeall(strs), NULL);
		s += len;
		while (*s == c)
			s++;
		len = (size_t)ft_strchr(s, c);
		len -= (size_t)s * !!len + ft_strlen(s) * !len;
		i++;
	}
	strs[i] = NULL;
	return (strs);
}
