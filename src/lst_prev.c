/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_prev.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 22:01:54 by lsuardi           #+#    #+#             */
/*   Updated: 2021/03/18 22:08:02 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

t_list *	lst_prev(const t_list * beg, const t_list * cur)
{
	if (!cur)
		return (NULL);
	while (beg && beg->next != cur)
		beg = beg->next;
	return ((t_list*)beg);
}
