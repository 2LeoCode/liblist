/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_at.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 18:51:08 by lsuardi           #+#    #+#             */
/*   Updated: 2021/03/15 19:29:42 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

t_list *	lst_at(const t_list * lst, size_t index)
{
	while (index--)
	{
		if (!lst)
			return (NULL);
		lst = lst->next;
	}
	return ((t_list*)lst);
}
