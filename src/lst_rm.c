/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_rm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 21:08:21 by lsuardi           #+#    #+#             */
/*   Updated: 2021/03/16 16:14:45 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

int	lst_rm_last(t_list ** lst_ptr, free_f free_function)
{
	t_list *	last;

	if (!(last = lst_last(*lst_ptr)))
		return (0);
	(*free_function)((void**)&last);
	return (1);
}

int	lst_rm_first(t_list ** lst_ptr, free_f free_function)
{
	t_list *	first;

	if (!(first = *lst_ptr))
		return (0);
	*lst_ptr = (*lst_ptr)->next;
	(*free_function)((void**)&first);
	return (1);
}

int	lst_rm_if(t_list ** lst_ptr, check_f check_function, free_f free_function)
{
	t_list *	prev;
	t_list *	head;
	int			rm_count;

	rm_count = 0;
	while ((*check_function)((void*)*lst_ptr))
		rm_count += lst_rm_first(lst_ptr, free_function);
	while (*lst_ptr)
	{
		prev = *lst_ptr;
		*lst_ptr = prev->next;
		head = (*lst_ptr)->next;
		if ((*check_function)((void*)*lst_ptr))
		{
			(*free_function)((void**)lst_ptr);
			rm_count++;
			prev->next = head;
			*lst_ptr = prev;
		}
	}
	return (rm_count);
}

int	lst_rm_if_eq(t_list ** lst_ptr, const void * dataref, cmp_f cmp_function,
free_f free_function)
{
	t_list *	prev;
	t_list *	head;
	int			rm_count;

	rm_count = 0;
	while (*lst_ptr && !(*cmp_function)((*lst_ptr)->data, dataref))
		rm_count += lst_rm_first(lst_ptr, free_function);
	while (*lst_ptr)
	{
		prev = *lst_ptr;
		*lst_ptr = prev->next;
		head = (*lst_ptr)->next;
		if (!(*cmp_function)((*lst_ptr)->data, dataref))
		{
			(*free_function)((void**)lst_ptr);
			rm_count++;
			prev->next = head;
			*lst_ptr = prev;
		}
	}
	return (rm_count);
}

int	lst_rm_at(t_list ** lst_ptr, size_t i, free_f free_function)
{
	t_list *	prev;
	t_list *	head;

	prev = *lst_ptr;
	while (--i && prev)
		prev = prev->next;
	if (!prev)
		return (0);
	*lst_ptr = prev->next;
	head = (*lst_ptr)->next;
	(*free_function)((void**)lst_ptr);
	prev->next = head;
	return (1);
}
