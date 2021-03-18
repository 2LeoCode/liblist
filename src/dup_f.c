/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_f.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 21:18:20 by lsuardi           #+#    #+#             */
/*   Updated: 2021/03/17 20:01:56 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

t_list *	two_dimensional_share_dup_f(const void * data)
{
	t_list *	src;
	t_list *	new_member;
	t_list *	new_data;

	if (!(src = (t_list*)data)
	|| !(new_member = malloc(sizeof(t_list))))
		return (NULL);
	if (!(new_data = malloc(sizeof(t_list))))
		return (lst_clear(&new_member, NO_FREE));
	new_member->data = (void*)new_data;
	new_data->data = src->data;
	while (!!(src = src->next))
	{
		if (!(new_data->next = malloc(sizeof(t_list))))
			return (lst_clear(&new_member, FREE_DFLT));
		new_data = new_data->next;
		new_data->data = src->data;
	}
	new_data->next = NULL;
	return (new_member);
}

t_list *	three_dimensional_share_dup_f(const void * data)
{
	t_list *	src;
	t_list *	new_member;
	t_list *	new_data;

	if (!(src = (t_list*)data)
	|| !(new_member = malloc(sizeof(t_list))))
		return (NULL);
	if (!(new_data = malloc(sizeof(t_list))))
		return (lst_clear(&new_member, NO_FREE));
	new_member->data = (void*)new_data;
	if (!(new_data->data = two_dimensional_share_dup_f(src->data)))
		return (lst_clear(&new_member, FREE_2));
	while (!!(src = src->next))
	{
		if (!(new_data->next = malloc(sizeof(t_list))))
			return (lst_clear(&new_member, FREE_DFLT));
		new_data = new_data->next;
		if (!(new_data->data = two_dimensional_share_dup_f(src->data)))
			return (lst_clear(&new_member, FREE_2));
	}
	new_data->next = NULL;
	return (new_member);
}
