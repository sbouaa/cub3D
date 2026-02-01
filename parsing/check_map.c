/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kraoui <kraoui@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 16:52:32 by kraoui            #+#    #+#             */
/*   Updated: 2026/01/20 02:17:25 by kraoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_map_chars(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map->height)
	{
		j = 0;
		while (j < (int)ft_strlen(game->map->grid[i]))
		{
			if (!is_valid_map_char(game->map->grid[i][j]))
				ft_error_msg(ERR_MAP_CHAR, game);
			if (game->map->grid[i][j] == 'N' || game->map->grid[i][j] == 'S'
				|| game->map->grid[i][j] == 'E' || game->map->grid[i][j] == 'W')
			{
				game->map->player_count++;
				game->map->player_x = j;
				game->map->player_y = i;
				game->map->player_dir = game->map->grid[i][j];
			}
			j++;
		}
		i++;
	}
	if (game->map->player_count != 1)
		ft_error_msg(ERR_MAP_PLAYER, game);
}

void	check_map_borders(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map->height)
	{
		j = 0;
		while (j < (int)ft_strlen(game->map->grid[i]))
		{
			if ((i == 0 || i == game->map->height - 1
					|| j == 0 || j == (int)ft_strlen(game->map->grid[i]) - 1)
				&& game->map->grid[i][j] != '1')
				ft_error_msg(ERR_MAP_WALLS, game);
			j++;
		}
		i++;
	}
}

void	check_sides(t_game *game, int x, int y)
{
	if (((y + 1 < game->map->height)
			&& (game->map->grid[y + 1][x] == '\0'
			|| game->map->grid[y + 1][x] == ' '))
			|| (game->map->grid[y - 1][x] == '\0'
			|| game->map->grid[y - 1][x] == ' ')
			|| ((x + 1 < game->map->width)
			&& (game->map->grid[y][x + 1] == '\0'
			|| game->map->grid[y][x + 1] == ' '))
			|| (game->map->grid[y][x - 1] == '\0'
			|| game->map->grid[y][x - 1] == ' '))
	{
		ft_error_msg(ERR_MAP_HOLE, game);
	}
}

void	holes_check(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->map->grid[y][x] == '0'
				|| game->map->grid[y][x] == 'N' || game->map->grid[y][x] == 'S'
				|| game->map->grid[y][x] == 'E' || game->map->grid[y][x] == 'W')
				check_sides(game, x, y);
			x++;
		}
		y++;
	}
}

void	check_map(t_game *game)
{
	check_map_chars(game);
	check_map_borders(game);
	holes_check(game);
}
