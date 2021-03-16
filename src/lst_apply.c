/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_apply.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 18:40:52 by lsuardi           #+#    #+#             */
/*   Updated: 2021/03/16 15:35:45 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

size_t	lst_apply_all(t_list * lst, apply_f apply_function)
{
	size_t	apply_count;

	apply_count = 0;
	while (lst)
	{
		(*apply_function)(lst->data);
		apply_count++;
		lst = lst->next;
	}
	return (apply_count);
}

size_t	lst_apply_if(t_list * lst, check_f check_function, apply_f apply_function)
{
	size_t	apply_count;

	apply_count = 0;
	while (lst)
	{
		if ((*check_function)(lst->data))
		{
			(*apply_function)(lst->data);
			apply_count++;
		}
		lst = lst->next;
	}
	return (apply_count);
}

size_t	lst_apply_if_eq(t_list * lst, const void * dataref, cmp_f cmp_function,
apply_f apply_function)
{
	size_t	apply_count;

	apply_count = 0;
	while (lst)
	{
		if (!(*cmp_function)(lst->data, dataref))
		{
			(*apply_function)(lst->data);
			apply_count++;
		}
		lst = lst->next;
	}
	return (apply_count);
}
