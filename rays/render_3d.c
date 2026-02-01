/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouaa <sbouaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 00:00:00 by sbouaa            #+#    #+#             */
/*   Updated: 2026/01/19 21:58:10 by sbouaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	calculate_texture_x(t_game *data, int ray_id, double wall_x)
{
	int	tex_x;
	int	tex_id;
	int	tex_width;

	tex_id = data->rays[ray_id].tex_id;
	tex_width = data->wall[tex_id].width;
	tex_x = (int)(wall_x * (double)tex_width);
	if (tex_x < 0)
		tex_x = 0;
	if (tex_x >= tex_width)
		tex_x = tex_width - 1;
	if (tex_id == 1 || tex_id == 2)
		tex_x = tex_width - tex_x - 1;
	return (tex_x);
}

void	draw_ceiling_floor(t_game *data, int x, t_wall_dim *dim)
{
	int	y;

	y = 0;
	while (y < dim->top)
	{
		put_pixel(data, x, y, data->tex->ceiling_color);
		y++;
	}
	y = dim->bottom;
	while (y < WIN_HEIGHT)
	{
		put_pixel(data, x, y, data->tex->floor_color);
		y++;
	}
}

void	init_texture_draw(t_game *data, int x, t_tex_draw *tex,
	double wall_height)
{
	double	wall_x;

	tex->tex_id = data->rays[x].tex_id;
	tex->tex_height = data->wall[tex->tex_id].height;
	wall_x = calculate_wall_x(data, x);
	tex->tex_x = calculate_texture_x(data, x, wall_x);
	tex->step = (double)tex->tex_height / wall_height;
}

void	draw_wall_column(t_game *data, int x, t_wall_dim *dim)
{
	int			y;
	int			tex_y;
	int			color;
	t_tex_draw	tex;

	init_texture_draw(data, x, &tex, dim->height);
	tex.tex_pos = (dim->top - WIN_HEIGHT / 2.0 + dim->height / 2.0) * tex.step;
	y = dim->top;
	while (y < dim->bottom)
	{
		tex_y = (int)tex.tex_pos;
		if (tex_y < 0)
			tex_y = 0;
		if (tex_y >= tex.tex_height)
			tex_y = tex.tex_height - 1;
		tex.tex_pos += tex.step;
		color = get_texture_pixel(data, tex.tex_id, tex.tex_x, tex_y);
		put_pixel(data, x, y, color);
		y++;
	}
}

void	render_3d_view(t_game *data)
{
	int			x;
	t_wall_dim	dim;

	x = 0;
	while (x < WIN_WIDTH)
	{
		calculate_wall_dim(data, x, &dim);
		draw_ceiling_floor(data, x, &dim);
		draw_wall_column(data, x, &dim);
		x++;
	}
}
