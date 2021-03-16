/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_merge.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 18:53:00 by lsuardi           #+#    #+#             */
/*   Updated: 2021/03/15 19:23:02 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

void	lst_merge(t_list * a, t_list * b)
{
	lst_last(a)->next = b;
}

void	lst_merge_sorted(t_list * a, t_list * b, cmp_f cmp_function)
{
	lst_merge(a, b);
	lst_sort(a, cmp_function);
}

void	lst_merge_invert_sorted(t_list * a, t_list * b, cmp_f cmp_function)
{
	lst_merge(a, b);
	lst_invert_sort(a, cmp_function);
}
