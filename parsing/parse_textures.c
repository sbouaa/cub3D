/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kraoui <kraoui@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 14:40:10 by kraoui            #+#    #+#             */
/*   Updated: 2025/12/05 11:47:39 by kraoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_texture_path(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	return (1);
}

int	set_no_texture(char *path, t_game *game, int *found)
{
	if (game->tex->no)
		return (2);
	if (!check_texture_path(path))
		return (3);
	game->tex->no = ft_strdup(path);
	if (!game->tex->no)
		return (4);
	*found = *found | 1;
	return (1);
}

int	set_so_texture(char *path, t_game *game, int *found)
{
	if (game->tex->so)
		return (2);
	if (!check_texture_path(path))
		return (3);
	game->tex->so = ft_strdup(path);
	if (!game->tex->so)
		return (4);
	*found = *found | 2;
	return (1);
}

int	set_we_texture(char *path, t_game *game, int *found)
{
	if (game->tex->we)
		return (2);
	if (!check_texture_path(path))
		return (3);
	game->tex->we = ft_strdup(path);
	if (!game->tex->we)
		return (4);
	*found = *found | 4;
	return (1);
}

int	set_ea_texture(char *path, t_game *game, int *found)
{
	if (game->tex->ea)
		return (2);
	if (!check_texture_path(path))
		return (3);
	game->tex->ea = ft_strdup(path);
	if (!game->tex->ea)
		return (4);
	*found = *found | 8;
	return (1);
}
