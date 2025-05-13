/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stobin <stobin@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 17:19:45 by stobin            #+#    #+#             */
/*   Updated: 2024/06/15 22:53:43 by stobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif

typedef enum t_bool
{
	TRUE,
	FALSE
}					t_bool;

typedef struct t_glist
{
	char			*txt;
	struct t_glist	*nxt;
}					t_glist;

char				*get_next_line(int fd);
char				*trim_tail(t_glist *tail, ssize_t i);
void				drop_chunks(t_glist *chunk);
void				load_buf(int fd, t_glist **chunk);
void				build_line(t_glist *chunk, char **line);
void				count_line(t_glist *chunk, char **line);
void				grab_chunk(t_glist **chunk, char *buf, int bread);
t_bool				line_broke(t_glist *chunk);
t_glist				*ft_lstlastg(t_glist *chunk);
t_glist				*clean_tail(t_glist **chunk);
void				free_drop(t_glist *tail, t_glist **chunk);
void				free_tail(t_glist *tail);

#endif
