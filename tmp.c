/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 14:00:30 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/05/01 16:44:09 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

void	update_static_buffer(char *static_buffer, int new_line_pos, char *result)
{
	int	i;

	i = 0;
	while (static_buffer[new_line_pos + i] != 0)
	{
		if (i <= new_line_pos)
			result[i] = static_buffer[i];
		static_buffer[i] = static_buffer[new_line_pos + i];
		i++;
	}
	static_buffer[new_line_pos + i] = '\0';
}

char *new_line(int i, size_t size, char* read_buffer, char *static_buffer)
{
	char *result;
	int new_line_pos;

	new_line_pos = i;
	result = malloc(size);
	while (i >= 0)
	{
		result[size - i] = read_buffer[i];
		i--;
	}
	update_static_buffer(static_buffer, new_line_pos, result);
}

char	*r_read(int fd, size_t size, char *static_buffer)
{
	int		len;
	char	read_buffer[BUFFER_SIZE];// this is uniq per funkiton call
	int		i;
	char	*result;

	len = read(fd, read_buffer, BUFFER_SIZE);
	if (len == -1)
		return ;// error
	while(read_buffer != '\0')
	{
		if (read_buffer[i] != '\n')
		{
			return (new_line(i, size + i, read_buffer, static_buffer));
		}
		i++;
	}
	result = r_read(fd, size, static_buffer);
	while (len >= 0)
	{
		result[size - len] = read_buffer[len];
		len--;
	}
	return (result);
}


char *just_use_buffer(size_t size, char *static_buffer)
{
	char	*result;

	{
		result = malloc (size);
		update_static_buffer(static_buffer, size, result);
		return (result);
	}
}

char	*get_next_line(fd)
{
	static char	static_buffer[BUFFER_SIZE] = "";
	char		*result;
	size_t		size;
	size = 0;
	while (static_buffer[size] != '\0')
	{
		if (static_buffer[size] == '\n')
			return (just_use_buffer(size, static_buffer));
		size++;
	}
	result = r_read(fd, size, static_buffer);
	return (result);	
}
