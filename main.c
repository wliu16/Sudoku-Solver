/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 13:17:55 by wliu              #+#    #+#             */
/*   Updated: 2016/11/06 22:20:03 by jinfeld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

int	gridcomp(int grid[9][9], int test[9][9])
{
	int i;
	int j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			if (grid[i][j] == test[i][j])
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int grid[9][9];
	int test_grid[9][9];

	if (argc != 10)
	{
		ft_putstr("error\n");
		return (0);
	}
	if (sudoku_input(grid, argc, argv) == 0)
	{
		ft_putstr("error\n");
		return (0);
	}
	sudoku_input(test_grid, argc, argv);
	solve_test(test_grid);
	if (solve_sudoku(grid) == 1 && verif(grid) == 1 &&
			verif(test_grid) == 1 && gridcomp(grid, test_grid) == 1)
	{
		print_grid(grid);
	}
	//vaild sudoku: could be solved, only 1 answer, result is valid grid
	//notes: solve_sudoku solves & fills the grid from 1 to 9, verif from 9 to 1
	//if both get same answer (gridcomp == 1), it will be the only answer
	else
	{
		ft_putstr("Error\n");
	}
	return (0);
}
