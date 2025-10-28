/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekramer <ekramer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 13:25:11 by ekramer           #+#    #+#             */
/*   Updated: 2025/10/28 17:01:44 by ekramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*newstr;
	size_t		s1_size;
	size_t		s2_size;

	if (!s1 || !s2)
		return (NULL);
	s1_size = ft_strlen(s1);
	s2_size = ft_strlen(s2);
	newstr = malloc(s1_size + s2_size + 1);
	if (!newstr)
		return (NULL);
	ft_strlcpy(newstr, s1, s1_size + 1);
	ft_strlcpy(newstr + s1_size, s2, s2_size + 1);
	return (newstr);
}
