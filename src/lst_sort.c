/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 19:39:10 by lsuardi           #+#    #+#             */
/*   Updated: 2021/03/15 19:43:02 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

void	lst_sort(t_list * lst, cmp_f cmp_function)
{
	t_list *	head;

	while (lst)
	{
		head = lst->next;
		while (head)
		{
			if ((*cmp_function)(lst->data, head->data) > 0)
				swap_ptr(&lst->data, head->data);
			head = head->next;
		}
		lst = lst->next;
	}
}

void	lst_invert_sort(t_list * lst, cmp_f cmp_function)
{
	t_list *	head;

	while (lst)
	{
		head = lst->next;
		while (head)
		{
			if ((*cmp_function)(lst->data, head->data) < 0)
				swap_ptr(&lst->data, head->data);
			head = head->next;
		}
		lst = lst->next;
	}
}
