/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 16:48:28 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/05/11 20:43:48 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	stash[BUFFER_SIZE + 1];
	char		*result = NULL;
	char		*buffer = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ft_read(fd, &buffer, stash);
	result = ft_get_line(result, stash);
	if (result == NULL)
	{
		free(buffer);
		return (NULL);
	}
	ft_update_stash(stash);
	return (result);
}

void	ft_read(int fd, char **buffer, char *stash)
{
	int		read_bytes;

	read_bytes = 1;
	while (read_bytes != 0 && ft_strchr(stash, '\n') == NULL)
	{
		*buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
		read_bytes = read(fd, *buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(*buffer);
			return ;
		}
		(*buffer)[read_bytes] = '\0';
		stash = ft_strjoin(stash, *buffer);
	}
}

char	*ft_get_line(char *result, char *stash)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	result = (char *)malloc(sizeof(char) * (i + 1));
	if (result == NULL)
		return (NULL);
	while (j < i)
	{
		result[j] = stash[j];
		j++;
	}
	result[j] = '\0';
	return (result);
}

void	ft_update_stash(char *stash)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	if (stash[i] == '\n')
		i++;
	while (stash[i] != '\0')
	{
		stash[j] = stash[i];
		i++;
		j++;
	}
	stash[j] = '\0';
}

//#include <stdio.h>

//int main(void)
//{
//	int fd = open("text.txt", O_RDONLY);
//	char *s;
//	char *s1;
//	s = get_next_line(fd);
//	printf("First call%s\n",s);
//	s1 = get_next_line(fd);
//	printf("Second call%s\n",s1);
//	free(s);
//	free(s1);
//	close(fd);
//	return (0);
//}
