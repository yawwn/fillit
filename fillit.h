/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcathery <mcathery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 13:43:12 by mcathery          #+#    #+#             */
/*   Updated: 2019/11/12 16:15:02 by hgalazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "./libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

# define USAGE "usage: ./fillit filename\n"
# define I_PIECE (int [8]) {0,0,0,1,0,2,0,3}
# define IH_PIECE (int [8]) {0,0,1,0,2,0,3,0}
# define O_PIECE (int [8]) {0,0,1,0,0,1,1,1}
# define L_PIECE (int [8]) {0,0,0,1,0,2,1,2}
# define LR_PIECE (int [8]) {0,0,1,0,2,0,0,1}
# define LD_PIECE (int [8]) {0,0,1,0,1,1,1,2}
# define LL_PIECE (int [8]) {2,0,0,1,1,1,2,1}
# define J_PIECE (int [8]) {1,0,1,1,0,2,1,2}
# define JR_PIECE (int [8]) {0,0,0,1,1,1,2,1}
# define JD_PIECE (int [8]) {0,0,1,0,0,1,0,2}
# define JL_PIECE  (int [8]) {0,0,1,0,2,0,2,1}
# define T_PIECE (int [8]) {1,0,0,1,1,1,2,1}
# define TR_PIECE (int [8]) {0,0,0,1,1,1,0,2}
# define TD_PIECE (int [8]) {0,0,1,0,2,0,1,1}
# define TL_PIECE (int [8]) {1,0,0,1,1,1,1,2}
# define S_PIECE (int [8]) {1,0,2,0,0,1,1,1}
# define SR_PIECE (int [8]) {0,0,0,1,1,1,1,2}
# define Z_PIECE (int [8]) {0,0,1,0,1,1,2,1}
# define ZR_PIECE (int [8]) {1,0,0,1,1,1,0,2}

typedef struct		s_fillit
{
	void			*name;
	char			c;
	struct s_fillit	*next;
}					t_fillit;

void				ft_error(void);
int					ft_solver(int fd);
int					first_look(const int fd);
int					*make_piece(const int fd, char *line);
int					*coord(int *tab);
char				*get_name(int *tet);
t_fillit			*add_piece(void *piece_name, char piece_ch);
t_fillit			*append(void *piece_name, t_fillit *head, char piece_ch);
t_fillit			*store_piece(const int fd, char *line);
t_fillit			*name_to_coord(t_fillit *stack);
int					tabcmp(int *tab1, int *tab2, int n);
int					min_size(t_fillit *stack);
void				node_free(t_fillit *stack);
void				node_free_co(t_fillit *stack);
void				free_field(char **field, int size);
char				**field_gen(int size);
int					*shift_tet(int *tab, int x, int y);
int					dup_coord(int *dst, int *srcs);
int					solve_tet(char **field, t_fillit *stack, int size);
int					check_collision(char **field, int *tet, int size);
void				insert_piece(char **field, int *tet, char c);
void				clear_piece(char **field, int *tet);

#endif
