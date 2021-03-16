/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_last.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 21:06:14 by lsuardi           #+#    #+#             */
/*   Updated: 2021/03/14 21:08:10 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

t_list *	lst_last(const t_list * lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return ((t_list*)lst);
}
