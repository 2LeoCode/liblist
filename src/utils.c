/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 21:07:32 by lsuardi           #+#    #+#             */
/*   Updated: 2021/03/15 22:02:15 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

void	swap_ptr(void ** a, void ** b)
{
	void * c;

	c = *a;
	*a = *b;
	*b = c;
}

void *	destroy(void ** data)
{
	if (*data)
	{
		free(*data);
		*data = NULL;
	}
	return (NULL);
}
