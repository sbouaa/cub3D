/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouaa <sbouaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 22:10:15 by sbouaa            #+#    #+#             */
/*   Updated: 2026/01/19 22:34:42 by sbouaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	calculate_movement(t_game *data, double *move_x, double *move_y)
{
	*move_x = cos(data->player->angle) * data->player->walk_d
		* data->player->speed;
	*move_y = sin(data->player->angle) * data->player->walk_d
		* data->player->speed;
	*move_x += cos(data->player->angle + M_PI / 2) * data->player->strafe_d
		* data->player->speed;
	*move_y += sin(data->player->angle + M_PI / 2) * data->player->strafe_d
		* data->player->speed;
}

void	update_position(t_game *data, double new_x, double new_y)
{
	if (!check_collision(data, new_x, (double)data->player->y))
		data->player->x = (int)new_x;
	if (!check_collision(data, (double)data->player->x, new_y))
		data->player->y = (int)new_y;
}

void	ft_re(t_game *data)
{
	double	move_x;
	double	move_y;

	data->player->angle += data->player->turn_d * data->player->rotate_s;
	data->player->angle = normalize_angle(data->player->angle);
	calculate_movement(data, &move_x, &move_y);
	update_position(data, data->player->x + move_x, data->player->y + move_y);
	ft_memset(data->info->img_addr, 0, WIN_WIDTH
		* WIN_HEIGHT * (data->info->bits_per_pixel / 8));
	drawing(data);
}

int	get_texture_pixel(t_game *data, int tex_id, int x, int y)
{
	char	*pixel;
	int		offset;

	if (x < 0)
		x = 0;
	if (x >= data->wall[tex_id].width)
		x = data->wall[tex_id].width - 1;
	if (y < 0)
		y = 0;
	if (y >= data->wall[tex_id].height)
		y = data->wall[tex_id].height - 1;
	offset = y * data->wall[tex_id].line_len + x * (data->wall[tex_id].bpp / 8);
	pixel = data->wall[tex_id].addr + offset;
	return (*(unsigned int *)pixel);
}

double	calculate_wall_x(t_game *data, int ray_id)
{
	double	wall_x;
	double	tile;

	tile = 64;
	if (data->rays[ray_id].hit_vertical)
		wall_x = data->rays[ray_id].hit_y;
	else
		wall_x = data->rays[ray_id].hit_x;
	wall_x = wall_x / tile;
	wall_x = wall_x - floor(wall_x);
	return (wall_x);
}
