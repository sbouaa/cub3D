/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kraoui <kraoui@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:47:47 by kraoui            #+#    #+#             */
/*   Updated: 2026/01/20 02:54:42 by kraoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	rgb_to_int(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

int	set_final_color(char **tokens, int *color_array, t_game *game, int *found)
{
	if (tokens[0][0] == 'F')
	{
		if (game->tex->floor_color != -1)
			return (free_split(tokens, -1), ft_error_msg(ERR_DUP_ID, game), 0);
		game->tex->floor_color = rgb_to_int(color_array[0],
				color_array[1], color_array[2]);
		*found = *found | 16;
	}
	else
	{
		if (game->tex->ceiling_color != -1)
			return (free_split(tokens, -1), ft_error_msg(ERR_DUP_ID, game), 0);
		game->tex->ceiling_color = rgb_to_int(color_array[0],
				color_array[1], color_array[2]);
		*found = *found | 32;
	}
	return (1);
}

void	fill_color_array(char **tokens,
	char **rgb, int *color_array, t_game *game)
{
	int	i;
	int	value;

	i = 0;
	while (i < 3)
	{
		value = ft_atoi(rgb[i]);
		if (value < 0 || value > 255)
		{
			free_split(tokens, -1);
			free_split(rgb, -1);
			ft_error_msg(ERR_COLOR, game);
		}
		color_array[i] = value;
		i++;
	}
}

int	parse_color(t_game *game, char **tokens, int *found)
{
	char	**rgb;
	int		*color_array;

	if (!tokens[0] || !tokens[1] || tokens[2]
		|| tokens[0][1] != '\0')
		return (free_split(tokens, -1), ft_error_msg(ERR_SPACE_TEX, game), 0);
	if (tokens[0][0] != 'F' && tokens[0][0] != 'C')
		return (0);
	rgb = ft_split_by_one(tokens[1], ',');
	if (!rgb || count_array(rgb) != 3)
	{
		if (rgb)
			free_split(rgb, -1);
		free_split(tokens, -1);
		ft_error_msg(ERR_COLOR, game);
	}
	if (tokens[0][0] == 'F')
		color_array = game->tex->floor;
	else
		color_array = game->tex->ceiling;
	fill_color_array(tokens, rgb, color_array, game);
	free_split(rgb, -1);
	set_final_color(tokens, color_array, game, found);
	return (1);
}
