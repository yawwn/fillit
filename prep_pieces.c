/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_pieces.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgalazza <hgalazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:33:53 by hgalazza          #+#    #+#             */
/*   Updated: 2019/11/12 16:15:02 by hgalazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	*make_piece(const int fd, char *line)
{
	int	x;
	int	y;
	int *tab;
	int i;

	y = -1;
	tab = (int *)malloc(sizeof(int) * 8);
	i = 0;
	while (++y <= 3)
	{
		x = 0;
		get_next_line(fd, &line);
		while (line[x])
		{
			if (line[x] == '#')
			{
				tab[i] = x;
				tab[i + 1] = y;
				i += 2;
			}
			x++;
		}
		free(line);
	}
	return (tab);
}

int	min_x(int *tab)
{
	int x;
	int i;
	int size;

	size = 4;
	i = 0;
	x = tab[i];
	while (size--)
	{
		if (tab[i] >= 0 && tab[i] <= 3)
		{
			if (tab[i] < x)
				x = tab[i];
		}
		i += 2;
	}
	return (x);
}

int	min_y(int *tab)
{
	int y;
	int i;
	int size;

	size = 4;
	i = 1;
	y = tab[i];
	while (size--)
	{
		if (tab[i] >= 0 && tab[i] <= 3)
		{
			if (tab[i] < y)
				y = tab[i];
		}
		i += 2;
	}
	return (y);
}

int	*coord(int *tab)
{
	int mx;
	int my;
	int i;
	int size;

	size = 4;
	mx = min_x(tab);
	my = min_y(tab);
	i = 0;
	while (size--)
	{
		tab[i] -= mx;
		tab[i + 1] -= my;
		i += 2;
	}
	return (tab);
}
