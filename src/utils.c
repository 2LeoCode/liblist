/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 21:07:32 by lsuardi           #+#    #+#             */
/*   Updated: 2021/03/17 20:00:33 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

static size_t	_ft_strlen(const char * s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

static void *	_ft_memcpy(void * dst, const void * src, size_t n)
{
	char *	it;

	it = (char*)dst;
	while (n--)
		*(it++) = *((char*)src++);
	return (dst);
}

void			_swap_ptr(void ** a, void ** b)
{
	void * c;

	c = *a;
	*a = *b;
	*b = c;
}

void *			_destroy(void ** data)
{
	if (*data)
	{
		free(*data);
		*data = NULL;
	}
	return (NULL);
}

void *			_dup_string(const void * src)
{
	size_t	len;
	void *	dup;

	len = _ft_strlen((const char*)src);
	if (!(dup = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	return (_ft_memcpy(dup, src, len + 1));
}
