/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhairi <hkhairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 20:02:44 by hkhairi           #+#    #+#             */
/*   Updated: 2025/02/19 20:29:36 by hkhairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void	free_one(t_game *game, char *str)
{
	print_error(str);
	free_map(game->map);
	free(game);
	exit(1);
}

void	free_tow(t_valid *sume, t_game *game, char *str)
{
	print_error(str);
	free(sume);
	free_map(game->map);
	free(game);
	exit(1);
}
