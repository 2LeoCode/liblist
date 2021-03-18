/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_shuffle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 19:23:13 by lsuardi           #+#    #+#             */
/*   Updated: 2021/03/17 21:45:06 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

void	lst_shuffle(t_list * lst, rand_f rand_function)
{
	t_list *	it;
	size_t		size;
	size_t		n;

	it = lst;
	size = lst_size(lst);
	while (it)
	{
		n = (*rand_function)((int)size);
		_swap_ptr(&lst_at(lst, n)->data, &it->data);
		it = it->next;
	}
}
