/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 16:52:57 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/04/29 20:06:39 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#define	BUFFER_SIZE 100

char	*gnl(int fd)
{
	static char static_buffer[BUFFER_SIZE];
	char buffer[BUFFER_SIZE];
	int len = read(fd,buffer,BUFFER_SIZE);
	buffer[len] = 0;
	printf("buffer len = %d \nthis is buffer buffer = %s\n",len ,buffer);
	return(NULL);
}

int	main(void)
{
	int		fd;
	char	buf[BUFFER_SIZE];
	int		nb_read;
	int		count;
	
	fd = open("cat.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	
	//printf("fd = %d\n", fd);
	//read(fd, "This is a new line\n", 13);
	nb_read = -1;
	count	= 0;
	while (nb_read != 0)
	{
		nb_read = read(fd, buf, BUFFER_SIZE);
		if (nb_read == -1)
		{
			printf("Read error!\n");
			return (1);
		}
		buf[nb_read] = '\0';
		printf("\e[36m%d : [\e[0m%s\e[36m]\e[0m\n", count, buf);
		count++;
	}
	close(fd);
	return (0);
}