/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_collision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcathery <mcathery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 19:52:24 by mcathery          #+#    #+#             */
/*   Updated: 2019/11/12 16:15:02 by hgalazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		max_x(int *tet)
{
	int i;
	int x;
	int size;

	i = 0;
	x = tet[i];
	size = 3;
	while (size--)
	{
		i += 2;
		if (x < tet[i])
			x = tet[i];
	}
	return (x);
}

int		max_y(int *tet)
{
	int i;
	int y;
	int size;

	i = 1;
	y = tet[i];
	size = 3;
	while (size--)
	{
		i += 2;
		if (y < tet[i])
			y = tet[i];
	}
	return (y);
}

int		octo_collision(char **field, int *tet)
{
	int	i;
	int size;

	i = 0;
	size = 4;
	while (size--)
	{
		if (field[tet[i + 1]][tet[i]] != '.')
			return (1);
		i += 2;
	}
	return (0);
}

int		box_collision(int *tet, int size)
{
	int x;
	int y;

	x = max_x(tet);
	y = max_y(tet);
	if (x >= size || y >= size)
		return (1);
	return (0);
}

int		check_collision(char **field, int *tet, int size)
{
	return (!(box_collision(tet, size)) && !(octo_collision(field, tet)));
}
