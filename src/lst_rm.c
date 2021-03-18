/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_rm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 21:08:21 by lsuardi           #+#    #+#             */
/*   Updated: 2021/03/17 21:42:25 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

int	lst_rm_last(t_list ** lst_ptr, free_f free_function)
{
	t_list *	last;
	t_list *	new_last;

	if (!(last = lst_last(*lst_ptr)))
		return (0);
	new_last = *lst_ptr;
	while (new_last->next != last)
		new_last = new_last->next;
	(*free_function)((void**)&last->data);
	free(last);
	new_last->next = NULL;
	return (1);
}

int	lst_rm_first(t_list ** lst_ptr, free_f free_function)
{
	t_list *	first;

	if (!(first = *lst_ptr))
		return (0);
	*lst_ptr = (*lst_ptr)->next;
	(*free_function)((void**)&first->data);
	free(first);
	first = NULL;
	return (1);
}

int	lst_rm_if(t_list ** lst_ptr, check_f check_function, free_f free_function)
{
	t_list *	prev;
	t_list *	it;
	t_list *	head;
	int			rm_count;

	rm_count = 0;
	while ((*check_function)((void*)(*lst_ptr)->data))
		rm_count += lst_rm_first(lst_ptr, free_function);
	it = *lst_ptr;
	while (it->next)
	{
		prev = it;
		it = prev->next;
		head = it->next;
		if ((*check_function)((void*)it->data))
		{
			(*free_function)((void**)&it->data);
			free(it);
			rm_count++;
			prev->next = head;
			it = prev;
		}
	}
	return (rm_count);
}

int	lst_rm_if_eq(t_list ** lst_ptr, const void * dataref, cmp_f cmp_function,
free_f free_function)
{
	t_list *	prev;
	t_list *	it;
	t_list *	head;
	int			rm_count;

	rm_count = 0;
	while (*lst_ptr && !(*cmp_function)((*lst_ptr)->data, dataref))
		rm_count += lst_rm_first(lst_ptr, free_function);
	it = *lst_ptr;
	while (it->next)
	{
		prev = it;
		it = prev->next;
		head = it->next;
		if (!(*cmp_function)(it->data, dataref))
		{
			(*free_function)((void**)&it->data);
			free(it);
			rm_count++;
			prev->next = head;
			it = prev;
		}
	}
	return (rm_count);
}

int	lst_rm_at(t_list ** lst_ptr, size_t i, free_f free_function)
{
	t_list *	prev;
	t_list *	it;
	t_list *	head;

	prev = *lst_ptr;
	while (--i && prev)
		prev = prev->next;
	if (!prev)
		return (0);
	it = prev->next;
	head = it->next;
	(*free_function)((void**)&it->data);
	free(it);
	it = NULL;
	prev->next = head;
	return (1);
}
