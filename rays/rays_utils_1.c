/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_utils_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouaa <sbouaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 05:27:09 by sbouaa            #+#    #+#             */
/*   Updated: 2026/01/19 22:58:31 by sbouaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	dda_setup_steps(t_dda *d)
{
	if (d->dir_x < 0)
	{
		d->step_x = -1;
		d->side_x = (d->pos_x - d->map_x) * d->delta_x;
	}
	else
	{
		d->step_x = 1;
		d->side_x = (d->map_x + 1.0 - d->pos_x) * d->delta_x;
	}
	if (d->dir_y < 0)
	{
		d->step_y = -1;
		d->side_y = (d->pos_y - d->map_y) * d->delta_y;
	}
	else
	{
		d->step_y = 1;
		d->side_y = (d->map_y + 1.0 - d->pos_y) * d->delta_y;
	}
}

void	dda_setup(t_dda *d, t_game *data, double ang)
{
	double	tile;

	tile = 64;
	d->angle = ang;
	d->pos_x = (double)data->player->x / tile;
	d->pos_y = (double)data->player->y / tile;
	d->map_x = (int)d->pos_x;
	d->map_y = (int)d->pos_y;
	d->dir_x = cos(ang);
	d->dir_y = sin(ang);
	if (d->dir_x == 0.0)
		d->delta_x = 1e30;
	else
		d->delta_x = fabs(1.0 / d->dir_x);
	if (d->dir_y == 0.0)
		d->delta_y = 1e30;
	else
		d->delta_y = fabs(1.0 / d->dir_y);
	dda_setup_steps(d);
}

void	dda_trace(t_dda *d, t_game *data)
{
	d->side = 0;
	while (d->map_x >= 0 && d->map_x < data->map->width && d->map_y >= 0
		&& d->map_y < data->map->height)
	{
		if (d->side_x < d->side_y)
		{
			d->side_x += d->delta_x;
			d->map_x += d->step_x;
			d->side = 0;
		}
		else
		{
			d->side_y += d->delta_y;
			d->map_y += d->step_y;
			d->side = 1;
		}
		if (d->map_x < 0 || d->map_x >= data->map->width || d->map_y < 0
			|| d->map_y >= data->map->height)
			break ;
		if (data->map->grid[d->map_y][d->map_x] == '1')
			break ;
	}
}

void	set(t_game *data, t_dda *d, int id)
{
	if (d->side == 0)
		data->rays[id].hit_vertical = 1;
	else
		data->rays[id].hit_vertical = 0;
}

void	store_ray(t_game *data, int id, t_hit *h, t_dda *d)
{
	double	dist;
	double	perp;

	dist = h->perp * 64;
	set(data, d, id);
	data->rays[id].hit_x = data->player->x + d->dir_x * dist;
	data->rays[id].hit_y = data->player->y + d->dir_y * dist;
	perp = dist * cos(d->angle - data->player->angle);
	if (perp < 1.0)
		perp = 1.0;
	data->rays[id].perp_dist = perp;
	if (d->side == 0)
	{
		if (d->step_x == -1)
			data->rays[id].tex_id = 2;
		else
			data->rays[id].tex_id = 3;
	}
	else
	{
		if (d->step_y == -1)
			data->rays[id].tex_id = 0;
		else
			data->rays[id].tex_id = 1;
	}
}
