/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphilipp <vphilipp@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:34:49 by vphilipp          #+#    #+#             */
/*   Updated: 2023/12/12 17:34:51 by vphilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libft/ft_printf.h"
# include "../libft/libft.h"
# include "MLX42.h"
# include <stdio.h>
# include <string.h>

typedef struct s_game
{
	void		*mlx;
	void		*win;
	mlx_image_t	*sprites[8];
	char		*addr;
	char		**matrix;
	char		**ref_matrix;
	int			lines;
	int			rows;
	int			img_pxl;
	int			collectables;
	int			total_collectables;
	int			moves;
	int			current_x;
	int			current_y;
	int			end_x;
	int			end_y;
}				t_game;

// INIT
void			terminate_all(t_game *game);
void			init_game(t_game *game, char **argv);
void			init_display(t_game *game);
// SPRITES
void			init_textures(t_game *game);
void			init_player(t_game *game);
// DISPLAY
int				display_wall(t_game *game, void *mlx);
int				display_player(t_game *game, void *mlx);
int				display_collectible(t_game *game, void *mlx);
int				display_ground(t_game *game, void *mlx);
int				display_exit(t_game *game, void *mlx);
// MOVES
int				move_up(t_game *game);
int				move_down(t_game *game);
int				move_left(t_game *game);
int				move_right(t_game *game);
// KEY PRESSES
void			key_press(struct mlx_key_data keycode, void *param);
void			w_press(t_game *game);
void			a_press(t_game *game);
void			s_press(t_game *game);
void			d_press(t_game *game);
// COMPLETION
void			check_collectable(t_game *game);
// PARSING
int				calc_lines(char *path);
int				calc_rows(char *path);
int				calc_x(t_game *game);
int				calc_y(t_game *game);
t_game			build_matrix(char *path, t_game game);
void			set_start(t_game *game);
void			set_end(t_game *game);
void			set_collectables(t_game *game);
void			print_map(t_game game);
// VERIF
void			flood_fill(t_game *game, int x, int y);
int				check_bounds(int x, int y, t_game *game);
int				check_exit(t_game *game);
int				check_shape(t_game *game);
int				check_walls(t_game *game);
int				check_collectables(t_game *game);
void			verify(t_game *game);
// CLEARING
void			clear(t_game *game);
void			clear_player(t_game *game);
void			clear_tab(char **splitted);
#endif
