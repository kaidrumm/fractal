/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrumm <kdrumm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 21:44:20 by kdrumm            #+#    #+#             */
/*   Updated: 2016/11/09 16:39:32 by kdrumm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** Takes in the file descriptor as a string, looks for this entry in the list.
** Sets "buf" and "i" from corresponding values in stat.
** If FD is not already in the table, add a new node to the list.
*/

static t_file	*load_info(int fd, t_list **stat)
{
	t_list	*node;
	t_file	*f;

	node = NULL;
	if (stat)
		node = *stat;
	while (node)
	{
		f = (t_file *)node->content;
		if (f->fd - fd == 0)
			return (f);
		node = node->next;
	}
	f = (t_file *)malloc(sizeof(t_file));
	MALLOC_GUARD4(f);
	f->fd = fd;
	f->buf = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	MALLOC_GUARD4(f->buf);
	ft_bzero(f->buf, BUFF_SIZE + 1);
	f->i = 0;
	ft_lstadd(stat, ft_lstnew(f, sizeof(t_file)));
	free(f);
	return ((t_file *)(*stat)->content);
}

/*
** Removes a file from the list
*/

static void		close_fd(t_list **stat, int fd)
{
	t_list	*current;
	t_list	*prev;

	prev = NULL;
	current = *stat;
	while (current != NULL && (((t_file *)current->content)->fd - fd != 0))
	{
		prev = current;
		current = current->next;
	}
	if (((t_file *)current->content)->fd - fd == 0)
	{
		free(((t_file *)current->content)->buf);
		if (prev)
			prev->next = current->next;
		else
			*stat = current->next;
		free(current);
	}
}

/*
** Saves content from line, reallocates line, copies in old content plus more
*/

static void		gnl_helper2(t_file *f, char **line)
{
	int		j;
	char	*s;

	s = NULL;
	if (*line)
		s = *line;
	j = f->i;
	while (f->buf[j] != '\n' && f->buf[j] && j < BUFF_SIZE)
		j++;
	*line = (char *)malloc(sizeof(char) * (ft_strlen(s) + (j - f->i) + 1));
	MALLOC_GUARD3(*line);
	j = 0;
	if (s && *s)
	{
		*line = ft_strcpy(*line, s);
		free(s);
		j = ft_strlen(*line);
		s = NULL;
	}
	while (f->buf[f->i] != '\n' && f->buf[f->i] && f->i < BUFF_SIZE)
		(*line)[j++] = (f->buf)[(f->i)++];
	(*line)[j] = '\0';
}

/*
** Checks if buffer needs to be reloaded, reads into buffer,
** returns one or zero based on status of buffer and helper2
*/

static int		gnl_helper(t_file *f, char **line)
{
	int		ret;

	if (f->i == 0 || f->i >= BUFF_SIZE || !(f->buf)[f->i])
	{
		ft_bzero(f->buf, BUFF_SIZE + 1);
		f->i = 0;
		ret = read(f->fd, f->buf, BUFF_SIZE);
		if (ret == -1)
			return (-1);
		else if (ret == 0 && !(f->buf)[f->i])
		{
			if (!(*line))
				return (0);
			else
				return (1);
		}
	}
	gnl_helper2(f, line);
	if ((f->buf)[f->i] == '\n')
	{
		(f->i)++;
		return (1);
	}
	return (2);
}

/*
** Loads memory of file, then calls helper function, closes file if needed
*/

int				get_next_line(const int fd, char **line)
{
	static t_list	*stat = NULL;
	t_file			*f;
	int				ret;

	f = load_info(fd, &stat);
	if (!line)
		return (-1);
	*line = NULL;
	ret = 2;
	while (1)
	{
		ret = gnl_helper(f, line);
		if (ret == 0 || ret == -1)
			close_fd(&stat, f->fd);
		if (ret != 2)
			return (ret);
	}
	return (-1);
}
