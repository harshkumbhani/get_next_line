/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harsh <harsh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 16:48:28 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/05/19 14:38:05 by harsh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash = ALLOC_FAIL;
	char		*res;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (ALLOC_FAIL);
	stash = ft_read_file(fd, stash);
	if (stash == ALLOC_FAIL)
		return (free(stash), ALLOC_FAIL);
	res = ft_get_line(stash);
	if (res[0] == '\0' && !ft_strchr(stash, '\n'))
	{
		stash = ft_update_stash(stash);
		return (free(res), ALLOC_FAIL);
	}
	stash = ft_update_stash(stash);
	return (res);
}

char	*ft_read_file(int fd, char *stash)
{
	char	*buffer;
	int		ret;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (ALLOC_FAIL);
	ret = 1;
	while (ret > 0 && !ft_strchr(stash, '\n') && !ft_strchr(stash, '\0'))
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret < 0)
			return (free(buffer), free(stash), ALLOC_FAIL);
		buffer[ret] = '\0';
		stash = ft_strjoin(stash, buffer);
	}
	return (free(buffer), stash);
}

char	*ft_get_line(char *stash)
{
	int		i;
	char	*res;

	i = 0;
	if (!stash)
		return (ALLOC_FAIL);
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	if (stash[i] == '\n')
		i++;
	res = (char *)malloc(sizeof(char) * (i + 1));
	if (!res)
		return (ALLOC_FAIL);
	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
	{
		res[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		res[i++] = '\n';
	res[i] = '\0';
	return (res);
}

char	*ft_update_stash(char *stash)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	if (!stash)
		return (ALLOC_FAIL);
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	if (stash[i] == '\0')
		return (free(stash), ALLOC_FAIL);
	res = malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
	if (res == ALLOC_FAIL)
		return (free(stash), ALLOC_FAIL);
	i++;
	while (stash[i] != '\0')
		res[j++] = stash[i++];
	res[j] = '\0';
	return (free(stash), res);
}

//#include <stdio.h>

//int main(void)
//{
//	int fd = open("text.txt", O_RDONLY);
//	//char	*s;
//	//char	*s1;
//	//char	*s3;
//	int i = 0;
//	//s = get_next_line(fd);
//	//printf("First call %s\n",s);
//	//s1 = get_next_line(fd);
//	//printf("Second call %s\n",s1);
//	//s3 = get_next_line(fd);
//	//printf("Third call %s\n",s3);	
//	while (i <= 15)
//	{
//		printf("Call %d %s\n",i, get_next_line(fd));
//		i++;
//	}
//	//free(s);
//	//free(s1);
//	close(fd);
//	system("leaks a.out");
//	return (0);
//}