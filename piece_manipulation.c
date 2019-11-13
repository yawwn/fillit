/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_manipulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcathery <mcathery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 12:44:14 by mcathery          #+#    #+#             */
/*   Updated: 2019/11/12 16:15:02 by hgalazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	insert_piece(char **field, int *tet, char c)
{
	int x;
	int y;
	int i;

	x = 0;
	y = 0;
	i = 0;
	while (i < 8)
	{
		x = tet[i];
		y = tet[i + 1];
		field[y][x] = c;
		i += 2;
	}
}

void	clear_piece(char **field, int *tet)
{
	int x;
	int y;
	int i;

	x = 0;
	y = 0;
	i = 0;
	while (i < 8)
	{
		x = tet[i];
		y = tet[i + 1];
		field[y][x] = '.';
		i += 2;
	}
}
