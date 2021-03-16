/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 19:07:42 by lsuardi           #+#    #+#             */
/*   Updated: 2021/03/14 19:18:51 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

t_list *	lst_create(size_t size, void ** dataset, free_f free_function)
{
	t_list *	new_lst;

	new_lst = NULL;
	while (size--)
	{
		if (lst_push_front(&new_lst, *dataset) == LST_FAILURE)
			return (lst_clear(&new_lst, free_function));
		dataset++;
	}
	return (new_lst);
}
