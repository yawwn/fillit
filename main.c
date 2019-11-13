/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgalazza <hgalazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 16:48:13 by hgalazza          #+#    #+#             */
/*   Updated: 2019/11/12 16:15:02 by hgalazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_field(char **field, int size)
{
	int i;

	i = -1;
	while (field[++i])
	{
		ft_putstr(field[i]);
		ft_putchar('\n');
	}
	free_field(field, size);
}

int		help_solve(char **field, int *tet, t_fillit *stack, int size)
{
	if (check_collision(field, tet, size))
	{
		insert_piece(field, tet, stack->c);
		if (solve_tet(field, stack->next, size))
		{
			free(tet);
			return (1);
		}
		clear_piece(field, tet);
	}
	return (0);
}

int		solve_tet(char **field, t_fillit *stack, int size)
{
	int *tet;
	int x;
	int y;

	y = -1;
	tet = (int *)malloc(sizeof(int) * 8);
	if (!stack)
	{
		free(tet);
		return (1);
	}
	while (++y < size)
	{
		x = -1;
		while (++x < size)
		{
			dup_coord(tet, stack->name);
			shift_tet(tet, x, y);
			if (help_solve(field, tet, stack, size))
				return (1);
		}
	}
	free(tet);
	return (0);
}

int		ft_solver(int fd)
{
	t_fillit	*tmp;
	t_fillit	*stack;
	int			size;
	char		**field;

	tmp = store_piece(fd, NULL);
	size = min_size(tmp);
	stack = name_to_coord(tmp);
	node_free(tmp);
	field = field_gen(size);
	while (!solve_tet(field, stack, size))
	{
		free_field(field, size);
		size += 1;
		field = field_gen(size);
	}
	print_field(field, size);
	node_free_co(stack);
	return (1);
}

int		main(int argc, char **argv)
{
	int fd;

	fd = 0;
	if (argc != 2)
	{
		ft_putstr(USAGE);
		exit(1);
	}
	else
	{
		if ((fd = open(argv[1], O_RDONLY)) < 0)
			ft_error();
		else if (first_look(fd))
		{
			fd = open(argv[1], O_RDONLY);
			ft_solver(fd);
		}
		close(fd);
	}
	return (0);
}
