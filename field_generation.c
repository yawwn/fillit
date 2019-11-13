/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_generation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcathery <mcathery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 20:23:48 by mcathery          #+#    #+#             */
/*   Updated: 2019/11/12 16:17:42 by hgalazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*line_gen(int col)
{
	char	*line;
	int		i;

	i = 0;
	line = (char *)malloc(sizeof(char) * col + 1);
	while (i < col)
	{
		line[i] = '.';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	**field_gen(int size)
{
	char	**field;
	int		i;
	char	*line;

	i = 0;
	field = (char **)malloc(sizeof(char *) * size + 1);
	while (i < size)
	{
		field[i] = (char *)malloc(sizeof(char) * size + 1);
		line = line_gen(size);
		ft_strcpy(field[i], line);
		free(line);
		i++;
	}
	field[i] = NULL;
	return (field);
}
