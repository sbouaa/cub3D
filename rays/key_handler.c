/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouaa <sbouaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 22:30:00 by sbouaa            #+#    #+#             */
/*   Updated: 2026/01/19 22:34:54 by sbouaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	key_press(int key, t_game *data)
{
	if (key == KEY_ESC)
		(ft_terminate(data), exit(0));
	if (key == KEY_W)
		data->keys.w = 1;
	if (key == KEY_S)
		data->keys.s = 1;
	if (key == KEY_A)
		data->keys.a = 1;
	if (key == KEY_D)
		data->keys.d = 1;
	if (key == KEY_LEFT)
		data->keys.left = 1;
	if (key == KEY_RIGHT)
		data->keys.right = 1;
	return (0);
}

int	key_release(int key, t_game *data)
{
	if (key == KEY_W)
		data->keys.w = 0;
	if (key == KEY_S)
		data->keys.s = 0;
	if (key == KEY_A)
		data->keys.a = 0;
	if (key == KEY_D)
		data->keys.d = 0;
	if (key == KEY_LEFT)
		data->keys.left = 0;
	if (key == KEY_RIGHT)
		data->keys.right = 0;
	return (0);
}

int	game_loop(t_game *data)
{
	data->player->walk_d = 0;
	data->player->strafe_d = 0;
	data->player->turn_d = 0;
	if (data->keys.w)
		data->player->walk_d = 1;
	if (data->keys.s)
		data->player->walk_d = -1;
	if (data->keys.a)
		data->player->strafe_d = -1;
	if (data->keys.d)
		data->player->strafe_d = 1;
	if (data->keys.left)
		data->player->turn_d = -1;
	if (data->keys.right)
		data->player->turn_d = 1;
	ft_re(data);
	return (0);
}

void	calculate_wall_dim(t_game *data, int ray_id, t_wall_dim *dim)
{
	double	dist;
	double	proj_plane_dist;

	dist = data->rays[ray_id].perp_dist;
	if (dist < 0.1)
		dist = 0.1;
	proj_plane_dist = (WIN_WIDTH / 2.0) / tan((60 * M_PI / 180.0) / 2.0);
	dim->height = (64 / dist) * proj_plane_dist;
	dim->top = (int)((WIN_HEIGHT / 2.0) - (dim->height / 2.0));
	dim->bottom = (int)((WIN_HEIGHT / 2.0) + (dim->height / 2.0));
	if (dim->top < 0)
		dim->top = 0;
	if (dim->bottom > WIN_HEIGHT)
		dim->bottom = WIN_HEIGHT;
}
