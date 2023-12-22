/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:41:00 by chbachir          #+#    #+#             */
/*   Updated: 2023/07/26 10:14:03 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

char	*ft_strchr(char *str, int c);
char	*ft_strjoin(char *s, char *buffer);
int		ft_strlen(char *str);
char	*ft_next(char *s);
char	*ft_line(char *s);
char	*ft_read(int fd, char *s);
char	*get_next_line(int fd);

#endif
