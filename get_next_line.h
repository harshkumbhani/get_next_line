/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 12:53:46 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/05/11 20:07:57 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stddef.h>
# include <stdlib.h>
# include <string.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

# define ALLOC_FAIL NULL

char	*get_next_line(int fd);
char	*ft_get_line(char *result, char *stash);
void	ft_read(int fd, char **buffer, char *stash);
void	ft_update_stash(char *stash);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *s);

#endif