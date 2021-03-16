/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 19:01:16 by lsuardi           #+#    #+#             */
/*   Updated: 2021/03/16 15:36:42 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

t_list *	lst_new(const void * data)
{
	t_list *	new_lst;

	if (!(new_lst = malloc(sizeof(t_list))))
		return (NULL);
	new_lst->data = (void*)data;
	new_lst->next = NULL;
	return (new_lst);
}
