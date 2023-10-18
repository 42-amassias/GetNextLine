/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 06:46:18 by amassias          #+#    #+#             */
/*   Updated: 2023/10/18 06:42:17 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdlib.h>
#include <unistd.h>

typedef struct s_buffer {
	unsigned long	size;
	struct s_buffer	*next;
	char			data[BUFFER_SIZE];
}	t_buffer;

void	*free_buffer(t_buffer **buffer_ptr)
{
	t_buffer	*itr;
	t_buffer	*buffer;

	itr = *buffer_ptr;
	while (itr)
	{
		buffer = itr;
		itr = buffer->next;
		free(buffer);
	}
	*buffer_ptr = NULL;
	return (NULL);
}

unsigned long	compute_final_size(t_buffer *buffer)
{
	unsigned long	size;

	size = 0;
	while (buffer)
	{
		size += buffer->size;
		buffer = buffer->next;
	}
	return (size);
}

char	*compile(t_buffer *buffer)
{
	t_buffer		*itr;
	char			*line;
	unsigned long	size;

	itr = buffer;
	size = compute_final_size(buffer);
	if (size == 0)
		return ((char *) free_buffer(&buffer));
	line = (char *) malloc(size + 1);
	if (!line)
		return ((char *) free_buffer(&buffer));
	line[size] = '\0';
	itr = buffer;
	size = 0;
	while (itr)
	{
		ft_memcpy(line + size, itr->data, itr->size);
		size += itr->size;
		itr = itr->next;
	}
	(void) free_buffer(&buffer);
	return (line);
}

t_buffer	*create_buffer(void)
{
	t_buffer	*buffer;

	buffer = (t_buffer *) malloc(sizeof(t_buffer));
	if (!buffer)
		return (NULL);
	(buffer)->size = 0;
	(buffer)->next = NULL;
	return (buffer);
}

char	*get_next_line(int fd)
{
	t_buffer	*org;
	t_buffer	**ptr;
	long		n;

	ptr = &org;
	while (1)
	{
		*ptr = create_buffer();
		if (!*ptr)
			return (free_buffer(&org));
		while (1)
		{
			n = read(fd, (*ptr)->data + (*ptr)->size, 1);
			if (n < 0)
				return (free_buffer(&org));
			(*ptr)->size += n;
			if (n == 0 || (*ptr)->data[(*ptr)->size - n] == '\n')
				return (compile(org));
			if ((*ptr)->size == BUFFER_SIZE)
				break ;
		}
		ptr = &(*ptr)->next;
	}
}
