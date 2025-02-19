/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhairi <hkhairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:28:44 by hkhairi           #+#    #+#             */
/*   Updated: 2025/02/19 18:22:44 by hkhairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_name(char *str, char *str2)
{
	int	i;
	int	j;
	int	len_str;
	int	len_str2;

	len_str = 0;
	while (str[len_str])
		len_str++;
	len_str2 = 0;
	while (str2[len_str2])
		len_str2++;
	if (len_str < len_str2)
		handel_failed_check_name("Error\nInvalid name map\n");
	i = len_str - 1;
	j = len_str2 - 1;
	while (j >= 0)
	{
		if (str[i] != str2[j])
			handel_failed_check_name("Error\nInvalid name map\n");
		i--;
		j--;
	}
}

int	ft_close(t_game *game)
{
	free_game(game);
	exit(0);
}

void	free_game(t_game	*game)
{
	if (game)
		free_all_component(game);
}

void	bigen_game(t_game *game, char *str)
{
	init_game(game, str);
	render_map(game);
	mlx_key_hook(game->win, handle_keypress, game);
	find_enemy_positions(game);
	mlx_loop_hook(game->mlx, game_loop, game);
	mlx_hook(game->win, 17, 0, ft_close, game);
	mlx_loop(game->mlx);
}

int	main(int argc, char *argv[])
{
	t_game	*game;

	if (argc != 2)
	{
		print_error("Usage: ./so_long_bonus <map_file.ber>\n");
		return (1);
	}
	check_name(argv[1], ".ber");
	game = malloc(sizeof(t_game));
	if (!game)
	{
		print_error("Erorr\nMemory allocation failed\n");
		return (1);
	}
	bigen_game(game, argv[1]);
	free_game(game);
	return (0);
}
