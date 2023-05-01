/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 16:48:28 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/05/01 18:40:21 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>// temp

char	*get_next_line(int fd)
{
	static char	string[BUFFER_SIZE];
	int			i;
	char	*result;

	i = read(fd, string, BUFFER_SIZE);
	if (i < 0)
		return (NULL);
	printf("i = %i\nstring = %s\n",i , string);
	while (string[i] != '\0')
	{
		printf("check char %c\n",string[i]);

		if (string[i] == '\n')
			return (string);
		i++;
	}
	return (string);
}

int main(void)
{
	int fd = open("text.txt", O_RDONLY);
	char *s;
	char *s1;
	s = get_next_line(fd);
	printf("address: %p \n%s\n",s, s);
	s1 = get_next_line(fd);
	printf("address: %p \n%s\n",s1, s1);
	//free(s);
	//free(s1);
	return (0);
}