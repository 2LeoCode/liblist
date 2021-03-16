/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 19:02:45 by lsuardi           #+#    #+#             */
/*   Updated: 2021/03/15 19:12:17 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

int	lst_push_front(t_list ** lst_ptr, const void * data)
{
	t_list * new_lst;

	if (!(new_lst = lst_new(data)))
		return (LST_FAILURE);
	new_lst->next = *lst_ptr;
	*lst_ptr = new_lst;
	return (LST_SUCCESS);
}

int	lst_push_back(t_list ** lst_ptr, const void * data)
{
	t_list * new_lst;

	if (!(new_lst = lst_new(data)))
		return (LST_FAILURE);
	if (*lst_ptr)
		lst_last(*lst_ptr)->next = new_lst;
	else
		*lst_ptr = new_lst;
	return (LST_SUCCESS);
}

int	lst_push_at(t_list ** lst_ptr, const void * data, size_t index)
{
	t_list *	prev;
	t_list *	head;
	t_list *	new_lst;

	prev = *lst_ptr;
	while (index-- > 1)
	{
		if (!prev)
			return (lst_push_back(lst_ptr, data));
		prev = prev->next;
	}
	if (!!(head = prev->next))
		head = head->next;
	if (!(new_lst = malloc(sizeof(t_list))))
		return (LST_FAILURE);
	prev->next = new_lst;
	new_lst->next = head;
	return (LST_SUCCESS);
}
