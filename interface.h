/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elfetoua <elfetoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 00:55:29 by elfetoua          #+#    #+#             */
/*   Updated: 2019/12/26 14:47:33 by elfetoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HEADER__H
# define __HEADER__H
# include <stdio.h>
# include <stdlib.h>

typedef struct		s_list
{
	int	coeff;
	int	exp;
	struct s_list	*next;
}					t_list;

typedef struct		s_node
{
	int	coeff[2];
	int	exp;
	struct s_node	*next;
}					t_node;

t_list		*new_node(float, int);
void		insert_node(t_list **, float, int);
void		afficher_poly(t_list**);
void		lire_input(t_list **);
t_list		*add_poly(t_list*, t_list*);
t_list		*sub_poly(t_list*, t_list*);
t_list		*mul_poly(t_list*, t_list*);
void		free_list(t_list**);
void		poly_add(t_list**, int, int);
void		oppos_poly(t_list*);
t_list		*puiss_n(t_list*, int);
t_list*		division(t_list*, t_list*);
void		derivative(t_list	*poly);
void		primitive(t_list	*poly);
void		print_poly(t_node **head1);
int			ft_power(int nbr, int p);
void		calcule(t_list	*poly);
t_list*		division1(t_list*, t_list*);
void		pgcd_poly(t_list *p, t_list	*d);
t_node     *new_node2(int n_coeff[2], int n_exp);
void		insert_node2(t_node **head, int coeff[2], int xp);

#endif

/*
t_list	*add_poly(t_list	*head_p1, t_list	*head_p2)
{
	t_list	*p_sum;
	t_list	*hd;

	
	p_sum = NULL;
	while(head_p1)
	{
		poly_add(&p_sum, head_p1->coeff, head_p1->exp);
		head_p1 = head_p1->next;
	}
	while(head_p2)
	{
		poly_add(&p_sum, head_p2->coeff, head_p2->exp);
		head_p2 = head_p2->next;
	}
	return(p_sum);
}*/