/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_rev.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 20:37:36 by lsuardi           #+#    #+#             */
/*   Updated: 2021/03/17 21:17:01 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

void	lst_rev(t_list * lst)
{
	t_list *	it;
	size_t		pos;
	size_t		size;

	pos = 0;
	size = lst_size(lst);
	it = lst;
	while (pos < (size / 2))
	{
		pos++;
		_swap_ptr(&it->data, &lst_at(lst, size - pos)->data);
		it = it->next;
	}
}
