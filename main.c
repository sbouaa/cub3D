/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kraoui <kraoui@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 05:18:21 by sbouaa            #+#    #+#             */
/*   Updated: 2026/01/20 02:57:25 by kraoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check(void)
{
	if (WIN_HEIGHT < 200 || WIN_HEIGHT > 1500)
		return (1);
	if (WIN_WIDTH < 200 || WIN_WIDTH > 2540)
		return (1);
	return (0);
}

int	init_setup(t_game *data)
{
	data->info->mlx_ptr = mlx_init();
	if (check() || !data->info->mlx_ptr)
		return (1);
	data->info->win_ptr = mlx_new_window(data->info->mlx_ptr,
			WIN_WIDTH, WIN_HEIGHT, "CUB3D");
	if (!data->info->win_ptr)
		return (1);
	data->info->mlx_img = mlx_new_image(data->info->mlx_ptr,
			WIN_WIDTH, WIN_HEIGHT);
	if (!data->info->mlx_img)
		return (1);
	data->info->img_addr = mlx_get_data_addr(data->info->mlx_img,
			&data->info->bits_per_pixel, &data->info->line_length,
			&data->info->endian);
	if (!data->info->img_addr)
		return (1);
	init_map(data);
	data->keys.w = 0;
	data->keys.a = 0;
	data->keys.s = 0;
	data->keys.d = 0;
	data->keys.left = 0;
	data->keys.right = 0;
	return (0);
}

static int	exit_handle(t_game *data)
{
	(void)data;
	ft_terminate(data);
	exit(0);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	*data;

	data = parse_cub_file(ac, av);
	if (init_setup(data))
		return (ft_terminate(data), ft_putstr_fd("Error\n", 2), 1);
	load_textures(data);
	drawing(data);
	mlx_hook(data->info->win_ptr, 2, 1L << 0, key_press, data);
	mlx_hook(data->info->win_ptr, 3, 1L << 1, key_release, data);
	mlx_hook(data->info->win_ptr, 17, 0, exit_handle, data);
	mlx_loop_hook(data->info->mlx_ptr, game_loop, data);
	mlx_loop(data->info->mlx_ptr);
	return (0);
}
