/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekramer <ekramer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 13:25:11 by ekramer           #+#    #+#             */
/*   Updated: 2025/11/24 21:25:49 by ekramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char		*str;
	size_t		s1_len;

	s1_len = ft_strlen(s1);
	str = malloc(s1_len + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, __SIZE_MAX__);
	ft_strlcpy(str + s1_len, s2, __SIZE_MAX__);
	return (str);
}
