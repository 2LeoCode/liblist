/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_rev.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 20:37:36 by lsuardi           #+#    #+#             */
/*   Updated: 2021/03/15 21:07:20 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

void	lst_rev(t_list * lst)
{
	size_t		size;
	size_t		index;
	t_list *	it;

	size = lst_size(lst);
	it = lst;
	while (!!(index = --size / 2))
	{
		swap_ptr(&it->data, &lst_at(lst, size)->data);
		it = it->next;
	}
}