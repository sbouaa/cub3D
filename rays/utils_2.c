/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouaa <sbouaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 03:46:09 by sbouaa            #+#    #+#             */
/*   Updated: 2026/01/19 06:32:18 by sbouaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	put_pixel(t_game *info, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	dst = info->info->img_addr
		+ (y * info->info->line_length + x * (info->info->bits_per_pixel / 8));
	*(unsigned int *)dst = (unsigned int)color;
}

void	ft_terminate(t_game *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		destroy_textures(data, i);
		i++;
	}
	if (data->info->win_ptr)
		mlx_destroy_window(data->info->mlx_ptr, data->info->win_ptr);
	if (data->info->mlx_img)
		mlx_destroy_image(data->info->mlx_ptr, data->info->mlx_img);
	if (data->info->mlx_ptr)
		mlx_destroy_display(data->info->mlx_ptr);
	if (data->info->mlx_ptr)
		free(data->info->mlx_ptr);
	if (data->player)
		free(data->player);
	if (data->info)
		free(data->info);
	free_game(data);
}

void	destroy_textures(t_game *tex, int id)
{
	if (tex->wall[id].img)
	{
		mlx_destroy_image(tex->info->mlx_ptr, tex->wall[id].img);
		tex->wall[id].img = NULL;
		tex->wall[id].addr = NULL;
	}
}

static void	load_texture(t_game *data, int id, char *path)
{
	void	*img;

	img = mlx_xpm_file_to_image(data->info->mlx_ptr, path,
			&data->wall[id].width, &data->wall[id].height);
	if (!img)
		(ft_terminate(data), ft_putstr_fd("Error\n", 2), exit(1));
	data->wall[id].img = img;
	data->wall[id].addr = mlx_get_data_addr(img, &data->wall[id].bpp,
			&data->wall[id].line_len, &data->wall[id].endian);
	if (!data->wall[id].addr)
		(ft_terminate(data), ft_putstr_fd("Error\n", 2), exit(1));
}

void	load_textures(t_game *data)
{
	load_texture(data, 0, data->tex->no);
	load_texture(data, 1, data->tex->so);
	load_texture(data, 2, data->tex->we);
	load_texture(data, 3, data->tex->ea);
}
