/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harsh <harsh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 02:44:12 by harsh             #+#    #+#             */
/*   Updated: 2023/05/31 16:57:18 by harsh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// static char	*read_line(int fd, char *stash, int stash_i, char *new_line);

char	*get_next_line(int fd)
{
	static char	stash[BUFFER_SIZE + 1];
	return read_line(fd, stash, 0, NULL);
}

char	*read_line(int fd, char *stash, int stash_i, char *new_line)
{
	int	bytes_read;

	bytes_read = 0;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (stash[stash_i] != '\0' || (bytes_read = read(fd, stash, BUFFER_SIZE)) > 0)
	{
		if(bytes_read < 0) // This checks if the read was successful.
		{
			if(new_line)
				free(new_line);
			return NULL;
		}
		stash[bytes_read] = '\0';
		new_line = ft_strjoin(new_line, stash);
		if (new_line == NULL)
			return (NULL);
		if (ft_strchr(stash, '\n'))
			return new_line;
		return read_line(fd, stash, 0, new_line);
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_line;
	int		i;
	int		k;

	if ((new_line = malloc(ft_strlen(s1) + ft_strlen(s2) + 1)) == NULL)
	{
		if(s1)
			free(s1);
		return (NULL);
	}
	i = -1;
	while (s1 && s1[++i])
		new_line[i] = s1[i];
	if(s1)
		free(s1);
	k = 0;
	while (s2 && s2[k])
	{
		new_line[i++] = s2[k++];
	}
	new_line[i] = '\0';
	return (new_line);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s && *s != (char)c)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

int	ft_strlen(char *str)
{
	int	i = 0;
	while (str && str[i] != '\n' && str[i])
		i++;
	return (i + (str && str[i] == '\n' ? 1 : 0));
}
