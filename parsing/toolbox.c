/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kraoui <kraoui@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 14:08:17 by kraoui            #+#    #+#             */
/*   Updated: 2026/01/20 02:28:01 by kraoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	is_valid_map_char(char c)
{
	return (c == '0' || c == '1' || c == ' '
		|| c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

int	is_map_line(char *line)
{
	int	i;

	if (!line)
		return (0);
	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (!line[i])
		return (0);
	while (line[i])
	{
		if (!is_valid_map_char(line[i]))
			return (0);
		i++;
	}
	return (1);
}

int	count_array(char **arr)
{
	int	i;

	if (!arr)
		return (0);
	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void	free_game(t_game *game)
{
	if (!game)
		return ;
	if (game->file)
		free_split(game->file, -1);
	if (game->tex)
	{
		if (game->tex->no)
			free(game->tex->no);
		if (game->tex->so)
			free(game->tex->so);
		if (game->tex->we)
			free(game->tex->we);
		if (game->tex->ea)
			free(game->tex->ea);
		free(game->tex);
	}
	if (game->map)
	{
		if (game->map->grid)
			free_split(game->map->grid, -1);
		free(game->map);
	}
	free(game);
}

int	ft_error_msg(char *message, t_game *game)
{
	if (!game)
		(ft_puterror(message), exit(1));
	if (game->player)
		free(game->player);
	if (game->info)
		free(game->info);
	free_game(game);
	ft_puterror(message);
	exit(EXIT_FAILURE);
}
