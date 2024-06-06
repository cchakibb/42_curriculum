/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <chbachir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:54:14 by chbachir          #+#    #+#             */
/*   Updated: 2024/06/06 14:54:15 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <stdlib.h>
# include <stddef.h>
# include <fcntl.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*fill_stash_buffer(int fd, char *stash, char *buffer);
char	*extract_line_stash(char *line, char *stash);
char	*extract_new_stash(char *stash);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *str);
char	*ft_strjoin(const char *s, const char *s1);
char	*ft_strchr(const char *str, const char ch);
#endif
