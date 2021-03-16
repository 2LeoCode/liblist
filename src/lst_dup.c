/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_dup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 19:33:42 by lsuardi           #+#    #+#             */
/*   Updated: 2021/03/15 21:45:28 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

t_list *	lst_dup(const t_list * src, dup_f dup_function,
free_f free_function)
{
	t_list *	new_lst;
	t_list *	it;

	if (!src || !(new_lst = malloc(sizeof(t_list))))
		return (NULL);
	it = new_lst;
	if (!dup_function)
		it->data = src->data;
	else if (!(it->data = (*dup_function)(src->data)))
		return (lst_clear(&new_lst, free_function));
	src = src->next;
	while (src)
	{
		if (!(it->next = malloc(sizeof(t_list))))
			return (lst_clear(&new_lst, free_function));
		it = it->next;
		if (!dup_function)
			it->data = src->data;
		else if (!(it->data = (*dup_function)(src->data)))
			return (lst_clear(&new_lst, free_function));
		src = src->next;
	}
	return (new_lst);
}

t_list *	lst_dup_from(const t_list * src, size_t start, dup_f dup_function,
free_f free_function)
{
	while (start-- && src)
		src = src->next;
	return (lst_dup(src, dup_function, free_function));
}

t_list *	lst_ndup(const t_list * src, size_t n, dup_f dup_function,
free_f free_function)
{
	t_list *	new_lst;
	t_list *	it;

	if (!src || !n || !(new_lst = malloc(sizeof(t_list))))
		return (NULL);
	it = new_lst;
	if (!dup_function)
		it->data = src->data;
	else if (!(it->data = (*dup_function)(src->data)))
		return (lst_clear(&new_lst, free_function));
	src = src->next;
	while (n-- && src)
	{
		if (!(it->next = (*dup_function)(src->data)))
			return (lst_clear(&new_lst, free_function));
		it = it->next;
		if (!dup_function)
			it->data = src->data;
		else if (!(it->data = (*dup_function)(src->data)))
			return (lst_clear(&new_lst, free_function));
		src = src->next;
	}
	return (new_lst);
}

t_list *	lst_ndup_from(const t_list * src, size_t start, size_t n,
dup_f dup_function, free_f free_function)
{
	while (start-- && src)
		src = src->next;
	return (lst_ndup(src, n, dup_function, free_function));
}
