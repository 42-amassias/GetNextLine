/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 06:28:08 by amassias          #+#    #+#             */
/*   Updated: 2023/11/09 22:48:58 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

#include <stdlib.h>

void	*ft_memcpy(
			void *dst,
			const void *src,
			size_t n)
{
	size_t	i;

	i = 0;
	while (i++ < n)
		*(char *)dst++ = *(char *)src++;
	return ((void *)((char *)dst - i));
}

char	*ft_strchr(
				const char *str,
				char c)
{
	while (*str != '\0' && *str != c)
		++str;
	if (*str != '\0' || c == '\0')
		return ((char *)str);
	return (NULL);
}

void	ft_strcat(
			char **dst_ptr,
			const char *src)
{
	size_t	dst_size;
	size_t	src_size;
	char	*res;

	dst_size = ft_strlen(*dst_ptr);
	src_size = ft_strlen(src);
	res = (char *) malloc(dst_size + src_size + 1);
	if (res != NULL)
	{
		ft_memcpy(res, *dst_ptr, dst_size);
		ft_memcpy(res + dst_size, src, src_size);
		res[dst_size + src_size] = '\0';
	}
	free(*dst_ptr);
	*dst_ptr = res;
}

size_t	ft_strlen(
			const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		++i;
	return (i);
}
