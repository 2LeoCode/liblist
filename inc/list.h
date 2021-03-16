/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 14:42:58 by lsuardi           #+#    #+#             */
/*   Updated: 2021/03/16 15:36:02 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include <stdlib.h>

# define LST_FAILURE -1
# define LST_SUCCESS 0
# define default_dup_f lst_new
# define default_free_f destroy
# define SHARE_DATA NULL
# define DUP_DFLT &default_dup_f
# define DUP_2 &two_dimensional_dup_f
# define DUP_2_SHARE &two_dimensional_share_dup_f
# define DUP_3 &three_dimensional_dup_f
# define DUP_3_SHARE &three_dimensional_share_dup_f
# define NO_FREE NULL
# define FREE_DFLT &default_free_f
# define FREE_2 &two_dimensional_free_f
# define FREE_2_DATA &two_dimensional_data_free_f
# define FREE_3 &three_dimensional_free_f
# define FREE_3_DATA &three_dimensional_data_free_f

typedef struct			s_list
{
	void *				data;
	struct s_list *		next;
}						t_list;

typedef int				(*cmp_f)(const void *, const void *);
typedef int				(*check_f)(const void *);
typedef void			(*apply_f)(void *);
typedef int				(*rand_f)(int);
typedef void *			(*free_f)(void **);
typedef t_list *		(*dup_f)(const void *);

/*
** lst_new.c
*/
t_list *				lst_new(const void *);

/*
** lst_push.c
*/
int						lst_push_front(t_list **, const void *);
int						lst_push_back(t_list **, const void *);
int						lst_push_at(t_list **, const void *, size_t);

/*
** lst_create.c
*/
t_list *				lst_create(size_t, void **, free_f);

/*
** lst_clear.c
*/
void *					lst_clear(t_list **, free_f);
void *					lst_clear_a(t_list **, free_f);

/*
** lst_last.c
*/
t_list *				lst_last(const t_list *);

/*
** lst_size.c
*/
size_t					lst_size(const t_list *);

/*
** lst_rm.c
*/
int						lst_rm_last(t_list **, free_f);
int						lst_rm_first(t_list **, free_f);
int						lst_rm_if(t_list **, check_f, free_f);
int						lst_rm_if_eq(t_list **, const void *, cmp_f, free_f);
int						lst_rm_at(t_list **, size_t, free_f);

/*
** lst_apply.c
*/
size_t					lst_apply_all(t_list *, apply_f);
size_t					lst_apply_if(t_list *, check_f, apply_f);
size_t					lst_apply_if_eq(t_list *, const void *, cmp_f,
apply_f);

/*
** lst_at.c
*/
t_list *				lst_at(const t_list *, size_t);

/*
** lst_sort.c
*/
void					lst_sort(t_list *, cmp_f);
void					lst_invert_sort(t_list *, cmp_f);

/*
** lst_merge.c
*/
void					lst_merge(t_list *, t_list *);
void					lst_merge_sorted(t_list *, t_list *, cmp_f);
void					lst_merge_invert_sorted(t_list *, t_list *, cmp_f);

/*
** lst_shuffle.c
*/
void					lst_shuffle(t_list *, rand_f);

/*
** lst_dup.c
*/
t_list *				lst_dup(const t_list *, dup_f, free_f);
t_list *				lst_dup_from(const t_list *, size_t, dup_f, free_f);
t_list *				lst_ndup(const t_list *, size_t, dup_f, free_f);
t_list *				lst_ndup_from(const t_list *, size_t, size_t, dup_f,
free_f);

/*
** lst_rev.c
*/
void					lst_rev(t_list * lst);

/*
** MACRO DEFINED FUNCTIONS BELOW
** [default functions for lst_dup]
** [and lst_clear]
**
**
** dup_f.c
*/
t_list *				two_dimensional_dup_f(const void *);
t_list *				two_dimensional_share_dup_f(const void *);
t_list *				three_dimensional_dup_f(const void *);
t_list *				three_dimensional_share_dup_f(const void *);

/*
** free_f.c
*/
void *					two_dimensional_free_f(void **);
void *					two_dimensional_data_free_f(void **);
void *					three_dimensional_free_f(void **);
void *					three_dimensional_data_free_f(void **);

/*
** utils.c
** [utilities for the library]
** [you can ignore this part]
*/
void					swap_ptr(void **, void **);
void *					destroy(void **);

#endif
