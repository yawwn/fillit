/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_of_piece.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgalazza <hgalazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 16:08:10 by hgalazza          #+#    #+#             */
/*   Updated: 2019/11/12 16:15:02 by hgalazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		tabcmp(int *tab1, int *tab2, int n)
{
	int i;

	i = -1;
	while (++i < n)
	{
		if (tab1[i] != tab2[i])
			return (0);
	}
	return (1);
}

char	*get_name(int *tet)
{
	char	*name;

	name = NULL;
	(tabcmp(tet, I_PIECE, sizeof(tet))) && (name = "I_PIECE");
	(tabcmp(tet, IH_PIECE, sizeof(tet))) && (name = "IH_PIECE");
	(tabcmp(tet, O_PIECE, sizeof(tet))) && (name = "O_PIECE");
	(tabcmp(tet, L_PIECE, sizeof(tet))) && (name = "L_PIECE");
	(tabcmp(tet, LR_PIECE, sizeof(tet))) && (name = "LR_PIECE");
	(tabcmp(tet, LD_PIECE, sizeof(tet))) && (name = "LD_PIECE");
	(tabcmp(tet, LL_PIECE, sizeof(tet))) && (name = "LL_PIECE");
	(tabcmp(tet, J_PIECE, sizeof(tet))) && (name = "J_PIECE");
	(tabcmp(tet, JR_PIECE, sizeof(tet))) && (name = "JR_PIECE");
	(tabcmp(tet, JD_PIECE, sizeof(tet))) && (name = "JD_PIECE");
	(tabcmp(tet, JL_PIECE, sizeof(tet))) && (name = "JL_PIECE");
	(tabcmp(tet, T_PIECE, sizeof(tet))) && (name = "T_PIECE");
	(tabcmp(tet, TR_PIECE, sizeof(tet))) && (name = "TR_PIECE");
	(tabcmp(tet, TD_PIECE, sizeof(tet))) && (name = "TD_PIECE");
	(tabcmp(tet, TL_PIECE, sizeof(tet))) && (name = "TL_PIECE");
	(tabcmp(tet, S_PIECE, sizeof(tet))) && (name = "S_PIECE");
	(tabcmp(tet, SR_PIECE, sizeof(tet))) && (name = "SR_PIECE");
	(tabcmp(tet, Z_PIECE, sizeof(tet))) && (name = "Z_PIECE");
	(tabcmp(tet, ZR_PIECE, sizeof(tet))) && (name = "ZR_PIECE");
	return (name);
}
