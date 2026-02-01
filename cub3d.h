/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kraoui <kraoui@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 15:46:38 by sbouaa            #+#    #+#             */
/*   Updated: 2026/01/20 02:51:05 by kraoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include "mlx/mlx.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>

# define ERR_ARGS "Error\nToo many arguments."
# define ERR_NO_FILE "Error\nThe Map file is missing."
# define ERR_EXT "Error\nfile extention is wrong, it should end with .cub"
# define ERR_FILE "Error\nCannot open file"
# define ERR_TEX_FILE "Error\nCannot open texture file"
# define ERR_MEM "Error\nMemory allocation failed"
# define ERR_DUP_ID "Error\nDuplicate identifier"
# define ERR_MISS_ID "Error\nMissing identifier"
# define ERR_SPACE_TEX "Error\nspace in name of texture, \
or there's no texture at all"
# define ERR_COLOR "Error\nInvalid color format"
# define ERR_MAP_INVALID "Error\nMap not found or invalid"
# define ERR_MAP_CONTENT "Error\nNon-map content after map"
# define ERR_MAP_CHAR "Error\nInvalid character in map"
# define ERR_MAP_WALLS "Error\nMap not surrounded by walls"
# define ERR_MAP_PLAYER "Error\nInvalid number of players"
# define ERR_MAP_HOLE "Error\nMap has holes"
# define ERR_MAP_LAST "Error\nMap must be last element"
# define ERR_ID_FORMAT "Error\nInvalid identifier format"

# define WIN_WIDTH 1280
# define WIN_HEIGHT 720

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

typedef struct s_texture
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bpp;
	int		line_len;
	int		endian;
}	t_texture;

typedef struct s_keys
{
	int		w;
	int		a;
	int		s;
	int		d;
	int		left;
	int		right;
}			t_keys;

typedef struct s_dda
{
	double		pos_x;
	double		pos_y;
	int			map_x;
	int			map_y;
	double		dir_x;
	double		dir_y;
	double		delta_x;
	double		delta_y;
	double		side_x;
	double		side_y;
	int			step_x;
	int			step_y;
	int			side;
	double		angle;
}				t_dda;

typedef struct s_wall_dim
{
	int			top;
	int			bottom;
	double		height;
}				t_wall_dim;

typedef struct s_tex_draw
{
	int			tex_id;
	int			tex_x;
	int			tex_height;
	double		step;
	double		tex_pos;
}				t_tex_draw;

typedef struct s_hit
{
	double		perp;
}				t_hit;

typedef struct s_wall
{
	int			top;
	int			bottom;
	int			color;
}				t_wall;

typedef struct s_player
{
	int				x;
	int				y;
	double			turn_d;
	double			walk_d;
	double			strafe_d;
	int				speed;
	double			rotate_s;
	double			angle;
}				t_player;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*mlx_img;
	char		*img_addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_mlx;

typedef struct s_ray
{
	double		perp_dist;
	int			hit_vertical;
	double		hit_x;
	double		hit_y;
	int			tex_id;
}				t_ray;

typedef struct s_tex
{
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	int			floor[3];
	int			ceiling[3];
	int			floor_color;
	int			ceiling_color;
}				t_tex;

typedef struct s_map
{
	char		**grid;
	int			width;
	int			height;
	char		player_dir;
	int			player_x;
	int			player_y;
	int			player_count;
}				t_map;

typedef struct s_game
{
	char		**file;
	t_tex		*tex;
	t_map		*map;
	t_mlx		*info;
	t_player	*player;
	t_keys		keys;
	t_ray		rays[WIN_WIDTH];
	t_texture	wall[4];
}				t_game;

// toolbox
int				is_valid_map_char(char c);
int				is_map_line(char *line);
int				count_array(char **arr);
void			free_game(t_game *game);
int				ft_error_msg(char *message, t_game *game);

// check_map
void			check_map_chars(t_game *game);
void			check_map_borders(t_game *game);
void			check_map(t_game *game);

// parse_map
int				find_map_start(t_game *game);
void			get_map_dimensions(t_game *game, int start, int *height,
					int *width);
void			check_map_position(t_game *game, int map_end);
int				create_map_grid(t_game *game, int map_start);
void			parse_map(t_game *game);

// parse_colors
int				rgb_to_int(int r, int g, int b);
int				set_final_color(char **tokens, int *color_array, t_game *game,
					int *found);
void			fill_color_array(char **tokens, char **rgb, int *color_array,
					t_game *game);
int				parse_color(t_game *game, char **tokens, int *found);

// parse_textures
int				check_texture_path(char *path);
int				set_no_texture(char *path, t_game *game, int *found);
int				set_so_texture(char *path, t_game *game, int *found);
int				set_we_texture(char *path, t_game *game, int *found);
int				set_ea_texture(char *path, t_game *game, int *found);

// parse_identifiers
int				parse_texture(t_game *game, char **tokens, int *found);
int				handle_line(t_game *game, char *line, int *found);
int				parse_identifiers(t_game *game);

// parser
t_game			*parse_cub_file(int ac, char **av);

///////////
void			drawing(t_game *data);
void			ft_terminate(t_game *data);
void			init_map(t_game *data);
void			ft_re(t_game *data);
double			normalize_angle(double a);
void			dda_setup(t_dda *d, t_game *data, double ang);
void			dda_trace(t_dda *d, t_game *data);
void			store_ray(t_game *data, int id, t_hit *h, t_dda *d);
void			render_3d_view(t_game *data);
void			put_pixel(t_game *info, int x, int y, int color);
int				check_collision(t_game *data, double x, double y);
double			calculate_wall_x(t_game *data, int ray_id);
int				get_texture_pixel(t_game *data, int tex_id, int x, int y);
void			calculate_wall_dim(t_game *data, int ray_id, t_wall_dim *dim);
int				close_window(t_game *data);
int				key_press(int key, t_game *data);
int				key_release(int key, t_game *data);
int				game_loop(t_game *data);
void			load_textures(t_game *data);
void			destroy_textures(t_game *tex, int id);

#endif
