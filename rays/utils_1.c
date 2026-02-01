/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouaa <sbouaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 05:18:34 by sbouaa            #+#    #+#             */
/*   Updated: 2026/01/19 22:33:17 by sbouaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	is_wall(t_game *data, int x, int y)
{
	x /= 64;
	y /= 64;
	if (x < 0 || x >= data->map->width || y < 0 || y >= data->map->height)
		return (1);
	return (data->map->grid[y][x] == '1');
}

int	check_collision(t_game *data, double x, double y)
{
	int	buffer;

	buffer = 10;
	if (is_wall(data, (int)(x + buffer), (int)y))
		return (1);
	if (is_wall(data, (int)(x - buffer), (int)y))
		return (1);
	if (is_wall(data, (int)x, (int)(y + buffer)))
		return (1);
	if (is_wall(data, (int)x, (int)(y - buffer)))
		return (1);
	if (is_wall(data, (int)(x + buffer), (int)(y + buffer)))
		return (1);
	if (is_wall(data, (int)(x - buffer), (int)(y - buffer)))
		return (1);
	if (is_wall(data, (int)(x + buffer), (int)(y - buffer)))
		return (1);
	if (is_wall(data, (int)(x - buffer), (int)(y + buffer)))
		return (1);
	return (0);
}

void	init_map(t_game *data)
{
	if (data->map->player_dir == 'N')
		data->player->angle = 3 * M_PI / 2;
	else if (data->map->player_dir == 'S')
		data->player->angle = M_PI / 2;
	else if (data->map->player_dir == 'E')
		data->player->angle = 0;
	else if (data->map->player_dir == 'W')
		data->player->angle = M_PI;
	data->player->x = data->map->player_x * 64 + 64 / 2;
	data->player->y = data->map->player_y * 64 + 64 / 2;
	data->player->turn_d = 0;
	data->player->walk_d = 0;
	data->player->strafe_d = 0;
	data->player->speed = 30;
	data->player->rotate_s = 0.045;
}
