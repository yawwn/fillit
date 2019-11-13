/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcathery <mcathery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 13:42:33 by mcathery          #+#    #+#             */
/*   Updated: 2019/11/12 16:15:02 by hgalazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			ft_error(void)
{
	ft_putstr("error\n");
	exit(EXIT_FAILURE);
}

int				ft_char_check(char *line)
{
	while (*line)
	{
		if ((*line != '.') && (*line != '#'))
			return (0);
		line++;
	}
	return (1);
}

int				ft_octo_count(char *line)
{
	int i;

	i = 0;
	if (!line)
		return (0);
	while (*line)
	{
		if (*line == '#')
			i++;
		line++;
	}
	return (i);
}

int				first_check(const int fd, char *line)
{
	int		line_count;
	int		octo_count;

	line_count = 0;
	octo_count = 0;
	while (line_count < 4)
	{
		if (get_next_line(fd, &line))
		{
			octo_count += ft_octo_count(line);
			if (!ft_char_check(line) || octo_count > 4 || ft_strlen(line) != 4)
				ft_error();
			free(line);
		}
		line_count++;
	}
	if (octo_count < 4)
		ft_error();
	return (1);
}

int				first_look(const int fd)
{
	char	*line;

	line = NULL;
	while (1)
	{
		first_check(fd, line);
		if (!get_next_line(fd, &line))
			break ;
		free(line);
		if (ft_strlen(line) != 0)
			ft_error();
	}
	return (1);
}
