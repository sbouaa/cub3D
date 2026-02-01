/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouaa <sbouaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 05:24:26 by sbouaa            #+#    #+#             */
/*   Updated: 2026/01/19 21:58:27 by sbouaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double	normalize_angle(double a)
{
	while (a < 0)
		a += 2 * M_PI;
	while (a >= 2 * M_PI)
		a -= 2 * M_PI;
	return (a);
}

static double	get_ray_angle(t_game *data, int i)
{
	double	fov;
	double	start;
	double	step;

	fov = (60 * M_PI) / 180.0;
	start = data->player->angle - (fov / 2.0);
	step = fov / (double)WIN_WIDTH;
	return (normalize_angle(start + i * step));
}

void	drawing(t_game *data)
{
	int		i;
	t_dda	dda;
	t_hit	hit;
	double	angel;

	i = 0;
	while (i < WIN_WIDTH)
	{
		angel = get_ray_angle(data, i);
		dda_setup(&dda, data, angel);
		dda_trace(&dda, data);
		if (dda.side == 0)
			hit.perp = dda.side_x - dda.delta_x;
		else
			hit.perp = dda.side_y - dda.delta_y;
		store_ray(data, i, &hit, &dda);
		i++;
	}
	render_3d_view(data);
	mlx_put_image_to_window(data->info->mlx_ptr, data->info->win_ptr,
		data->info->mlx_img, 0, 0);
}
