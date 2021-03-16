/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 20:56:28 by lsuardi           #+#    #+#             */
/*   Updated: 2021/03/15 21:45:41 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

void *	lst_clear(t_list ** lst_ptr, free_f free_function)
{
	t_list *	head;

	while (*lst_ptr)
	{
		head = (*lst_ptr)->next;
		if (free_function)
			(*free_function)((void**)&(*lst_ptr)->data);
		free(*lst_ptr);
		*lst_ptr = head;
	}
	return (NULL);
}

void *	lst_clear_a(t_list ** lst_ptr, free_f free_function)
{
	static t_list ** attached;

	if (lst_ptr)
		attached = lst_ptr;
	else if (attached)
		lst_clear(attached, free_function);
	return (NULL);
}
