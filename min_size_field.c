/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_size_field.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgalazza <hgalazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 16:49:03 by hgalazza          #+#    #+#             */
/*   Updated: 2019/11/12 16:15:02 by hgalazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		count_pieces(t_fillit *stack)
{
	int			i;
	t_fillit	*tmp;

	tmp = stack;
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int		min_size(t_fillit *stack)
{
	int block;
	int size;

	size = 2;
	block = (count_pieces(stack) * 4);
	while (block > (size * size))
		size += 1;
	return (size);
}
