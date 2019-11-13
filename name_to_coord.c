/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_to_coord.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgalazza <hgalazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:11:12 by hgalazza          #+#    #+#             */
/*   Updated: 2019/11/12 16:15:02 by hgalazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			dup_coord(int *dst, int *srcs)
{
	int *pdst;
	int i;

	i = 0;
	pdst = dst;
	while (i < 8)
	{
		pdst[i] = srcs[i];
		i++;
	}
	return (1);
}

int			*convert_id(char *name)
{
	int *tet;

	tet = (int *)malloc(sizeof(int) * 8);
	(ft_strcmp(name, "I_PIECE") == 0) && (dup_coord(tet, I_PIECE));
	(ft_strcmp(name, "IH_PIECE") == 0) && (dup_coord(tet, IH_PIECE));
	(ft_strcmp(name, "O_PIECE") == 0) && (dup_coord(tet, O_PIECE));
	(ft_strcmp(name, "L_PIECE") == 0) && (dup_coord(tet, L_PIECE));
	(ft_strcmp(name, "LR_PIECE") == 0) && (dup_coord(tet, LR_PIECE));
	(ft_strcmp(name, "LD_PIECE") == 0) && (dup_coord(tet, LD_PIECE));
	(ft_strcmp(name, "LL_PIECE") == 0) && (dup_coord(tet, LL_PIECE));
	(ft_strcmp(name, "J_PIECE") == 0) && (dup_coord(tet, J_PIECE));
	(ft_strcmp(name, "JR_PIECE") == 0) && (dup_coord(tet, JR_PIECE));
	(ft_strcmp(name, "JD_PIECE") == 0) && (dup_coord(tet, JD_PIECE));
	(ft_strcmp(name, "JL_PIECE") == 0) && (dup_coord(tet, JL_PIECE));
	(ft_strcmp(name, "T_PIECE") == 0) && (dup_coord(tet, T_PIECE));
	(ft_strcmp(name, "TR_PIECE") == 0) && (dup_coord(tet, TR_PIECE));
	(ft_strcmp(name, "TD_PIECE") == 0) && (dup_coord(tet, TD_PIECE));
	(ft_strcmp(name, "TL_PIECE") == 0) && (dup_coord(tet, TL_PIECE));
	(ft_strcmp(name, "S_PIECE") == 0) && (dup_coord(tet, S_PIECE));
	(ft_strcmp(name, "SR_PIECE") == 0) && (dup_coord(tet, SR_PIECE));
	(ft_strcmp(name, "Z_PIECE") == 0) && (dup_coord(tet, Z_PIECE));
	(ft_strcmp(name, "ZR_PIECE") == 0) && (dup_coord(tet, ZR_PIECE));
	return (tet);
}

t_fillit	*name_to_coord(t_fillit *stack)
{
	t_fillit	*head;
	t_fillit	*piece;
	char		*name;
	char		c;

	c = 'A';
	head = NULL;
	while (stack)
	{
		name = stack->name;
		if (head == NULL)
			head = add_piece(convert_id(name), c++);
		else
			piece = append(convert_id(name), head, c++);
		stack = stack->next;
	}
	return (head);
}
