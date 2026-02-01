/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_identifiers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kraoui <kraoui@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 14:08:02 by kraoui            #+#    #+#             */
/*   Updated: 2025/12/17 15:42:43 by kraoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	parse_texture(t_game *game, char **tokens, int *found)
{
	int	result;

	result = 0;
	if (!tokens[0] || !tokens[1] || tokens[2])
		return (result);
	if (ft_strcmp(tokens[0], "NO") == 0)
		result = set_no_texture(tokens[1], game, found);
	if (ft_strcmp(tokens[0], "SO") == 0)
		result = set_so_texture(tokens[1], game, found);
	if (ft_strcmp(tokens[0], "WE") == 0)
		result = set_we_texture(tokens[1], game, found);
	if (ft_strcmp(tokens[0], "EA") == 0)
		result = set_ea_texture(tokens[1], game, found);
	if (result > 1)
	{
		free_split(tokens, -1);
		if (result == 2)
			ft_error_msg(ERR_DUP_ID, game);
		if (result == 3)
			ft_error_msg(ERR_TEX_FILE, game);
		if (result == 4)
			ft_error_msg(ERR_MEM, game);
	}
	return (result);
}

int	handle_line(t_game *game, char *line, int *found)
{
	char	*trimmed;
	char	**tokens;

	trimmed = ft_strtrim(line, " \t");
	if (!trimmed)
		ft_error_msg(ERR_MEM, game);
	if (trimmed[0] == '\0')
		return (free(trimmed), 0);
	if (is_map_line(trimmed))
		return (free(trimmed), 2);
	tokens = ft_split_sp(trimmed);
	free(trimmed);
	if (!tokens)
		ft_error_msg(ERR_MEM, game);
	if (!parse_texture(game, tokens, found)
		&& !parse_color(game, tokens, found))
	{
		free_split(tokens, -1);
		ft_error_msg(ERR_ID_FORMAT, game);
	}
	free_split(tokens, -1);
	return (1);
}

int	parse_identifiers(t_game *game)
{
	int	i;
	int	found;
	int	ret;

	i = 0;
	found = 0;
	while (game->file[i])
	{
		ret = handle_line(game, game->file[i], &found);
		if (ret == 0)
		{
			i++;
			continue ;
		}
		if (ret == 2)
			break ;
		i++;
	}
	if (found != 63)
		ft_error_msg(ERR_MISS_ID, game);
	return (1);
}
