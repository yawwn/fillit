/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgalazza <hgalazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 16:19:25 by hgalazza          #+#    #+#             */
/*   Updated: 2019/11/12 16:15:02 by hgalazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_fillit	*add_piece(void *piece_name, char piece_ch)
{
	t_fillit *piece;

	piece = (t_fillit *)malloc(sizeof(t_fillit));
	piece->name = piece_name;
	piece->c = piece_ch;
	piece->next = NULL;
	return (piece);
}

t_fillit	*append(void *piece_name, t_fillit *head, char piece_ch)
{
	t_fillit *cursor;
	t_fillit *piece;

	cursor = head;
	while (cursor->next != NULL)
		cursor = cursor->next;
	piece = add_piece(piece_name, piece_ch);
	cursor->next = piece;
	return (head);
}

t_fillit	*store_piece(const int fd, char *line)
{
	int			*tet;
	char		*name;
	t_fillit	*piece;
	t_fillit	*first;
	char		c;

	c = 'A';
	first = NULL;
	while (1)
	{
		tet = coord(make_piece(fd, line));
		if (!(name = get_name(tet)))
			ft_error();
		if (first == NULL)
			first = add_piece(name, c++);
		else
			piece = append(name, first, c++);
		free(tet);
		if (!(get_next_line(fd, &line)))
			break ;
		free(line);
	}
	return (first);
}
