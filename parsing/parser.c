/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kraoui <kraoui@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:05:28 by kraoui            #+#    #+#             */
/*   Updated: 2026/01/20 02:20:58 by kraoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	ft_check_command_line(int argc, char **argv)
{
	int	file_name_len;

	if (argc > 2)
		ft_error_msg(ERR_ARGS, NULL);
	if (argc < 2)
		ft_error_msg(ERR_NO_FILE, NULL);
	file_name_len = ft_strlen(argv[1]);
	if (!ft_strnstr(&argv[1][file_name_len - 4], ".cub", 4))
		ft_error_msg(ERR_EXT, NULL);
}

static int	read_file_to_array(char *filename, t_game *game)
{
	int		fd;
	char	*line;
	char	*content;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_error_msg(ERR_FILE, game);
	content = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		content = ft_strappend(&content, line);
		free(line);
		if (!content)
			(close(fd), ft_error_msg(ERR_MEM, game));
	}
	close(fd);
	game->file = ft_split_by_one(content, '\n');
	free(content);
	if (!game->file)
		ft_error_msg(ERR_MEM, game);
	return (1);
}

t_game	*parse_cub_file(int ac, char **av)
{
	t_game	*game;

	ft_check_command_line(ac, av);
	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		ft_error_msg(ERR_MEM, NULL);
	game->tex = ft_calloc(1, sizeof(t_tex));
	if (!game->tex)
		ft_error_msg(ERR_MEM, game);
	game->map = ft_calloc(1, sizeof(t_map));
	if (!game->map)
		ft_error_msg(ERR_MEM, game);
	game->tex->floor[0] = -1;
	game->tex->ceiling[0] = -1;
	game->tex->floor_color = -1;
	game->tex->ceiling_color = -1;
	read_file_to_array(av[1], game);
	parse_identifiers(game);
	parse_map(game);
	check_map(game);
	game->info = ft_calloc(1, sizeof(t_mlx));
	game->player = ft_calloc(1, sizeof(t_player));
	if (!game->info || !game->player)
		ft_error_msg(ERR_MEM, game);
	return (game);
}
