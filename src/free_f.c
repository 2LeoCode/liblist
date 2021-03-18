/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 21:58:43 by lsuardi           #+#    #+#             */
/*   Updated: 2021/03/17 20:01:42 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

void *	two_dimensional_free_f(void ** data)
{
	t_list *	lst;

	if (!(lst = (t_list*)*data))
		return (NULL);
	while (lst)
	{
		free(lst);
		lst = lst->next;
	}
	*data = NULL;
	return (NULL);
}

void *	two_dimensional_data_free_f(void ** data)
{
	t_list *	lst;

	if (!(lst = (t_list*)*data))
		return (NULL);
	while (lst)
	{
		_destroy(&lst->data);
		free(lst);
		lst = lst->next;
	}
	*data = NULL;
	return (NULL);
}

void *	three_dimensional_free_f(void ** data)
{
	t_list *	lst;

	if (!(lst = (t_list*)*data))
		return (NULL);
	while (lst)
	{
		two_dimensional_free_f(&lst->data);
		lst = lst->next;
	}
	*data = NULL;
	return (NULL);
}

void *	three_dimensional_data_free_f(void ** data)
{
	t_list *	lst;

	if (!(lst = (t_list*)*data))
		return (NULL);
	while (lst)
	{
		two_dimensional_data_free_f(&lst->data);
		lst = lst->next;
	}
	*data = NULL;
	return (NULL);
}
