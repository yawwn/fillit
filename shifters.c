/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shifters.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgalazza <hgalazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 14:37:14 by hgalazza          #+#    #+#             */
/*   Updated: 2019/11/12 16:15:02 by hgalazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		*x_shift(int *tab, int x)
{
	int	i;
	int size;

	size = 4;
	i = 0;
	while (size--)
	{
		tab[i] = tab[i] + x;
		i += 2;
	}
	return (tab);
}

int		*y_shift(int *tab, int y)
{
	int i;
	int size;

	size = 4;
	i = 1;
	while (size--)
	{
		tab[i] = tab[i] + y;
		i += 2;
	}
	return (tab);
}

int		*shift_tet(int *tab, int x, int y)
{
	tab = x_shift(tab, x);
	tab = y_shift(tab, y);
	return (tab);
}
