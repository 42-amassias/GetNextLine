/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 04:47:38 by amassias          #+#    #+#             */
/*   Updated: 2023/11/09 22:54:13 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>

# define FD_LIMIT 1024

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

char	*get_next_line(
			int fd);

void	*ft_memcpy(
			void *dst,
			const void *src,
			size_t n);

char	*ft_strchr(
			const char *str,
			char c);

void	ft_strcat(
			char **dst_ptr,
			const char *src);

size_t	ft_strlen(
			const char *str);

#endif