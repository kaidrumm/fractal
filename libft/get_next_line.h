/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrumm <kdrumm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 21:45:32 by kdrumm            #+#    #+#             */
/*   Updated: 2016/11/09 16:39:31 by kdrumm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# include <fcntl.h>

# define BUFF_SIZE 42
# define MALLOC_GUARD2(x) if(!x) return (-1);
# define MALLOC_GUARD3(x) if(!x) return ;
# define MALLOC_GUARD4(x) if(!x) return NULL;

int				get_next_line(const int fd, char **line);

typedef struct	s_file
{
	int			fd;
	char		*buf;
	int			i;
}				t_file;

#endif
