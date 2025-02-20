/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valide_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhairi <hkhairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 13:46:13 by hkhairi           #+#    #+#             */
/*   Updated: 2025/02/19 20:09:51 by hkhairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	valid_first_wall_and_last_wall(t_game *game, int i, int j)
{
	char	**map;

	map = game->map;
	while (map[i][j])
	{
		if (map[i][j] != '1')
			free_one(game, "Erorr\nInvalid wall\n");
		j++;
	}
}

void	valid_midell_wall(t_game *game, int i, int j, int size_j)
{
	char	**map;

	map = game->map;
	while (map[i][j])
	{
		if ((j == 0 || j == size_j - 1) && map[i][j] != '1')
			free_one(game, "Erorr\nInvalid wall\n");
		j++;
	}
}

void	validate_wall(t_game *game)
{
	t_map	size;
	int		i;
	int		j;
	char	**map;

	i = 0;
	j = 0;
	map = game->map;
	size = size_map(game);
	check_width_and_height(game, size);
	while (map[i])
	{
		j = 0;
		if (i == 0 || i == size.i - 1)
			valid_first_wall_and_last_wall(game, i, j);
		else
			valid_midell_wall(game, i, j, size.j);
		i++;
	}
}

void	other_validation(t_game *game)
{
	validate_wall(game);
	validate_component_map(game);
	validate_map(game);
}

void	valide(t_game *game)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	j = 0;
	map = game->map;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if ((map[i][j] != '0') && (map[i][j] != '1') && (map[i][j] != 'E')
				&& (map[i][j] != 'P') && (map[i][j] != 'C'))
				free_one(game, "Error\nBad character in map\n");
			j++;
		}
		i++;
	}
	other_validation(game);
}
