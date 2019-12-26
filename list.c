/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elfetoua <elfetoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 18:02:46 by elfetoua          #+#    #+#             */
/*   Updated: 2019/12/26 14:41:13 by elfetoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"

t_list     *new_node(float n_coeff, int n_exp)
{
	t_list *new;

	new = (t_list*)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->coeff = n_coeff;
	new->exp = n_exp;
	new->next = NULL;
	return (new);
}

void		insert_node(t_list **head, float coeff, int xp)
{
	t_list		*node;
	t_list		*current;

	current = *head;
	node = new_node(coeff, xp);
	if (*head == NULL)
		*head = node;
	else
	{
		while (current->next != NULL)
			current = current->next;
		current->next = node;
	}
}

void		free_list(t_list** list)
{
	t_list*	tmp;
	t_list*	tmp2;

	tmp2 = *list;
	while (tmp2)
	{
		tmp = tmp2;
		tmp2 = tmp2->next;
		free(tmp);
	}
}
void		afficher_poly(t_list **head1)
{
	t_list *head;
	head = *head1;
	//puts("\n");
	if (head->coeff == 0 && head->exp == 0)
		puts(" 0 ");
	while(head)
	{
		if (head->exp != 0 && head->coeff != 0)
		{
			if (head->exp != 1)
			{
				if (head->coeff > 0 && head->coeff != 1)
					printf("%dx'%d", (int)head->coeff, head->exp);
				else if (head->coeff == 1)
					printf(" x'%d", head->exp);
				else if (head->coeff == -1)
					printf(" -x'%d", head->exp);

				else
					printf(" %dx'%d", (int)head->coeff, head->exp);
			}
			else
			{
				if (head->coeff > 0 && head->coeff != 1)
					printf("%dx", (int)head->coeff);
				else if (head->coeff < 0 && head->coeff != -1)
					printf(" %dx", (int)head->coeff);
				else if (head->coeff == 1)
					printf(" x");
				else if (head->coeff == -1)
					printf("- x");
			}
		}	
		else if (head->exp == 0)
		{
			if (head->coeff > 0)
				printf("%d", (int)head->coeff);
			else if (head->coeff < 0)
				printf(" %d", (int)head->coeff);
		}
		if (head->next != NULL && head->next->coeff > 0)
			printf(" + ");
		head = head->next;
	}
	printf("\n");
}

void		lire_input(t_list **head)
{
	int		i;
	float	coeff;
	int		expo;

	i = 1;
	expo = -1;
	puts("L'insertion se fait du la plus grande puissance vers la petite\n");
	while (expo != 0)
	{
		printf("\tEntrer le coefficient N' %d\n", i);
		scanf("%f", &coeff);
		printf("\tEntrer l'exponant N' %d\n", i);
		scanf("%d", &expo);
		insert_node(head, coeff, expo);
		i++;
	}
}

int	ft_power(int nbr, int p)
{
	if (p == 0)
		return (1);
	return (nbr * ft_power(nbr, p - 1));
}

t_node     *new_node2(int n_coeff[2], int n_exp)
{
	t_node *new;

	new = (t_node*)malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->coeff[0] = n_coeff[0];
	new->coeff[1] = n_coeff[1];
	new->exp = n_exp;
	new->next = NULL;
	return (new);
}

void		insert_node2(t_node **head, int coeff[2], int xp)
{
	t_node		*node;
	t_node		*current;

	current = *head;
	node = new_node2(coeff, xp);
	if (*head == NULL)
		*head = node;
	else
	{
		while (current->next != NULL)
			current = current->next;
		current->next = node;
	}
}

void		print_poly(t_node **head1)
{
	t_node *head;
	head = *head1;
	puts("\n");
	if (head->coeff[0] == 0 && head->exp == 0)
		puts(" 0 ");
	while(head)
	{
		if (head->exp != 0 && head->coeff[0] != 0)
		{
			if (head->exp != 1)
			{
				if (head->coeff[0] > 0 && head->coeff[0] != 1)
				{
					if (head->coeff[0] % head->coeff[1])
						printf("%dx'%d", head->coeff[0] / head->coeff[1], head->exp);
					else
						printf("%d / %dx'%d", head->coeff[0] , head->coeff[1], head->exp);
				}
				else if (head->coeff[0] == 1 && head->coeff[1] == 1)
					printf(" x'%d", head->exp);
				else if (head->coeff[0] == -1 && head->coeff[1] == 1)
					printf(" -x'%d", head->exp);

				else
					printf(" %dx'%d", head->coeff[0], head->exp);
			}
			else
			{
				if (head->coeff[0] > 0 && head->coeff[0] != 1)
				{
					if (head->coeff[0] % head->coeff[1])
						printf("%dx", head->coeff[0] / head->coeff[1]);
				}
				else if (head->coeff[0] < 0 && head->coeff[0] != -1)
					printf(" %dx", head->coeff[0] / head->coeff[1]);
				else if (head->coeff[0] == 1 && head->coeff[1] == 1)
					printf(" x");
				else if (head->coeff[0] == 1 && head->coeff[1] != 1)
					printf(" %dx", head->coeff[0] / head->coeff[1]);
				else if (head->coeff[0] == -1 && head->coeff[1] == 1)
					printf("- x");
			}
		}	
		else if (head->exp == 0)
		{
			if (head->coeff[0] > 0 && head->coeff[1] == 1)
				printf("%d", head->coeff[0]);
			else if (head->coeff[0] > 0 && head->coeff[1] != 1)
				printf("%d", head->coeff[0] / head->coeff[1]);
			else if (head->coeff[0] < 0)
				printf(" %d", head->coeff[0]);
		}
		if (head->next != NULL && head->next->coeff > 0)
			printf(" + ");
		head = head->next;
	}
	printf("\n");
}