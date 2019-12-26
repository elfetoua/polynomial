/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   module.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elfetoua <elfetoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 00:52:05 by elfetoua          #+#    #+#             */
/*   Updated: 2019/12/26 14:37:32 by elfetoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"

static	void	menu(void)
{
	printf("\n\t-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=--=");
	printf("\n\t\t  ****** Operations  ******\n");
	printf("\t-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=--=\n");
	printf("\t 1. Ajout des polynomes\n");
	printf("\t 2. soustraction de polynomes\n");
	printf("\t 3. multiplication de polynomes\n");
	printf("\t 4. oppose d'un polynome\n");
	printf("\t 5. puissance n'eme d'un polynome\n");
	printf("\t 6. division de 2 polynomes\n");
	printf("\t 7. derivee d'un polynome\n");
	printf("\t 8. primitive d'un polynome\n");
	printf("\t 9. Calcule de P(n) , n un entier\n");
	printf("\t 10. Quitter \n");
	printf("\t-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=--=\n");
	printf("\t __\n");
}
static	void	traitement_choix(short choix)
{
	t_list	**S;
	t_list	*p1;
	t_list	*p2;
	t_list	*tmp;
	int		n, i;

	printf("Entrer le nombre des polynomes que vous allez entrer\n");
	scanf("%d", &n);
	S = (t_list**)malloc(sizeof(n + 1));
	i = 0;
	while(i < n)
	{
		S[i] = (t_list*)malloc(sizeof(t_list));
		S[i] = NULL;
		printf("Entrer le plynome %d\n", i + 1);
		lire_input(&S[i]);
		i++;
	}
	i = 0;
	printf("Voici vos entrees\n");
	while(i < n)
	{
		printf("  |%d)\t", i + 1);
		afficher_poly(&S[i]);
		i++;
	}
	if ((choix >= 1 && choix <= 4) || choix == 6)
	{
		if (choix == 1)
		{
			puts("	Entrer le numero du 1er polynome\n");
			scanf("%d", &n);
			p1 = S[n];
			puts("	Entrer le numero du 2eme polynome\n");
			scanf("%d", &n);
			p2 = S[n];
			printf("\nla somme est :\n");
			tmp = add_poly(p1, p2);
			afficher_poly(&tmp);
			free_list(&tmp);
			free_list(&p1);
			free_list(&p2);
		}
		if (choix == 2)
			{
				puts("	Entrer le 1er polynome\n");
				p1 = NULL;
				lire_input(&p1);
				printf("Voila le polynome que vous avez entrer:\n");
				afficher_poly(&p1);
				puts("	Entrer le 2eme polynome\n");
				p2 = NULL;
				lire_input(&p2);
				printf("Voila le polynome que vous avez entrer:\n");
				afficher_poly(&p2);
				tmp = sub_poly(p1, p2);
				printf("\nla difference est :\n");
				afficher_poly(&tmp);
				free_list(&tmp);
				free_list(&p1);
				free_list(&p2);
			}
		if (choix == 3)
		{
			puts("	Entrer le 1er polynome\n");
			p1 = NULL;
			lire_input(&p1);
			printf("Voila le polynome que vous avez entrer:\n");
			afficher_poly(&p1);
			puts("	Entrer le 2eme polynome\n");
			p2 = NULL;
			lire_input(&p2);
			printf("Voila le polynome que vous avez entrer:\n");
			afficher_poly(&p2);
			printf("\nle produit des 2 polynomes est :\n");
			tmp = mul_poly(p1, p2);
			afficher_poly(&tmp);
			free_list(&tmp);
			free_list(&p1);
			free_list(&p2);
		}
		if (choix == 4)
			{
				puts("	Entrer le polynome\n");
				p1 = NULL;
				lire_input(&p1);
				printf("Voila le polynome que vous avez entrer:\n");
				afficher_poly(&p1);
				oppos_poly(p1);
			}
		if (choix == 6)
		{
			puts("	Entrer le 1er polynome\n");
			p1 = NULL;
			lire_input(&p1);
			printf("Voila le polynome que vous avez entrer:\n");
			afficher_poly(&p1);
			puts("	Entrer le 2eme polynome\n");
			p2 = NULL;
			lire_input(&p2);
			printf("Voila le polynome que vous avez entrer:\n");
			afficher_poly(&p2);
			division(p1, p2);
			}
	}
	if (choix == 5)
		{	
			puts("	Entrer le polynome\n");
			p1 = NULL;
			lire_input(&p1);
			printf("Voila le polynome que vous avez entrer:\n");
			afficher_poly(&p1);
			int n;
			printf("entrer la puissance n\n");
			scanf("%d", &n);
			printf("\nResultat  :\n");
			tmp = puiss_n(p1, n);
			afficher_poly(&tmp);
			free_list(&tmp);
		}
	if (choix == 7)
	{
		puts("	Entrer le polynome\n");
		p1 = NULL;
		lire_input(&p1);
		printf("Voila le polynome que vous avez entrer:\n");
		afficher_poly(&p1);
		derivative(p1);
	}
	if (choix == 8)
		{
			puts("	Entrer le polynome\n");
			p1 = NULL;
			lire_input(&p1);
			printf("Voila le polynome que vous avez entrer:\n");
			afficher_poly(&p1);
			printf("La primitive  :\n");
			//primitive(p1);
		}
	if (choix == 9)
	{
		puts("	Entrer le polynome\n");
		p1 = NULL;
		lire_input(&p1);
		printf("Voila le polynome que vous avez entrer:\n");
		afficher_poly(&p1);
		calcule(p1);
	}
}

int				main()
{
	short choix;

	menu();
	choix = 0;
	while (choix > 10 || choix < 1)
	{
		scanf("%hd", &choix);
		if ((choix > 10 || choix < 1) && choix != 10)
			printf(" desole votre choix est invalide, ressayer de nouveaux:\n");
	}
	if (choix == 10)
		return (0);
	traitement_choix(choix);
	printf("\n\tFin des operations. reaffichage du menu\n:");
	main();
	return (0);
}
