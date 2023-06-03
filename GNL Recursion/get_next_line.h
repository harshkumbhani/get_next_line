/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harsh <harsh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 02:44:21 by harsh             #+#    #+#             */
/*   Updated: 2023/05/31 10:52:48 by harsh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stddef.h>
# include <stdlib.h>
# include <string.h>

char			*get_next_line(int fd);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_strchr(const char *s, int c);
int				ft_strlen(char *str);
char			*read_line(int fd, char *stash, int stash_i, char *new_line);

#endif
