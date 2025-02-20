/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhairi <hkhairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:51:34 by hkhairi           #+#    #+#             */
/*   Updated: 2025/02/19 18:30:36 by hkhairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handel_error_init_enemies(t_game *game, char *str)
{
	print_error(str);
	free_game(game);
	exit(1);
}

void	handel_error_size(t_game *game, char *str)
{
	print_error(str);
	free_map(game->map);
	free(game);
	exit(1);
}

t_map	size_map(t_game *game)
{
	t_map	map_s;
	int		prev;
	char	**map;

	map_s.i = 0;
	map_s.j = 0;
	if (!game || !game->map)
		handel_error_size(game, "Error\ngame or game->map is NULL\n");
	map = game->map;
	prev = 0;
	while (map[map_s.i])
	{
		if (map[map_s.i][0] == '\0')
			handel_error_size(game, "Error\nempty line found\n");
		map_s.j = 0;
		while (map[map_s.i][map_s.j])
			map_s.j++;
		if (prev == 0)
			prev = map_s.j;
		else if (prev != map_s.j)
			handel_error_size(game, "Error\nmap is not rectongle\n");
		map_s.i++;
	}
	return (map_s);
}
