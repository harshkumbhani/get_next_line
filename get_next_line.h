/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harsh <harsh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 12:53:46 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/05/19 15:30:24 by harsh            ###   ########.fr       */
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

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define ALLOC_FAIL NULL

char	*get_next_line(int fd);
char	*ft_read_file(int fd, char *stash);
char	*ft_get_line(char *stash);
char	*ft_update_stash(char *stash);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *s);

#endif