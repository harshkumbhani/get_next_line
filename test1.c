/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:36:51 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/05/05 15:32:17 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 2
#endif

int	main(void)
{
	char	buffer[BUFFER_SIZE];
	int		fd;
	char	*result;
	size_t	i;

	i = 0;
	result = (char *)calloc(BUFFER_SIZE, sizeof(char));
	fd = open("text.txt", O_RDONLY);
	read(fd, buffer, BUFFER_SIZE);
	printf("\nfd : %d", fd);
	while (buffer[i] != '\0')
	{
		result[i] = buffer[i];
		if (buffer[i] == '\n')
			break;
		i++;
	}
	printf("\nThe read string from text.txt files is:\n%s\n", result);
	read(fd,buffer, BUFFER_SIZE);
	printf("\nThe 2nd read string from text.txt files is:\n%s\n", buffer);
	read(fd,buffer, BUFFER_SIZE);
	printf("\nThe 3rd read string from text.txt files is:\n%s\n", buffer);
	close(fd);
	free(result);
	return (0);
}
