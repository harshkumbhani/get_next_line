/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 17:37:11 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/05/15 16:55:10 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *str, int c)
{
	int	i;

	i = -1;
	if (str == NULL)
		return (NULL);
	while (str[++i] != '\0')
	{
		if (str[i] == c)
			return (&str[i]);
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*result;

	i = -1;
	j = 0;
	if (s2 == NULL)
		return (NULL);
	if (s1 == NULL)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		if (s1 == ALLOC_FAIL)
			return (free(s1), ALLOC_FAIL);
		s1[0] = '\0';
	}
	result = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (result == ALLOC_FAIL)
		return (free(s1), ALLOC_FAIL);
	while (s1[++i] != '\0')
		result[i] = s1[i];
	while (s2[j] != '\0')
		result[i++] = s2[j++];
	result[i] = '\0';
	return (free(s1), result);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}
