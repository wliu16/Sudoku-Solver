/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinfeld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 22:23:15 by jinfeld           #+#    #+#             */
/*   Updated: 2016/11/06 22:23:26 by jinfeld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

int		solve_sudoku(int grid[9][9])
{
	int	row;
	int	col;
	int	num;

	if (!find_missing(grid, &row, &col))
		return (1);
	num = 1;
	while (num <= 9)
	{
		if (is_safe(grid, row, col, num))
		{
			grid[row][col] = num;
			if (solve_sudoku(grid))
				return (1);
			grid[row][col] = 0;
		}
		num++;
	}
	return (0);
}

int		solve_test(int grid[9][9])
{
	int	row;
	int	col;
	int	num;

	if (!find_missing(grid, &row, &col))
		return (1);
	num = 9;
	while (num >= 1)
	{
		if (is_safe(grid, row, col, num))
		{
			grid[row][col] = num;
			if (solve_test(grid))
				return (1);
			grid[row][col] = 0;
		}
		num--;
	}
	return (0);
}

void	print_grid(int grid[9][9])
{
	int		row;
	int		col;
	char	c;

	row = 0;
	while (row < 9)
	{
		col = 0;
		while (col < 9)
		{
			c = grid[row][col] + 48;
			write(1, &c, 1);
			if (col < 8)
				write(1, " ", 1);
			else
				write(1, "\n", 1);
			col++;
		}
		row++;
	}
}

int		sudoku_input(int grid[9][9], int argc, char **argv)
{
	int	row;
	int col;

	row = 0;
	while (row < argc - 1)
	{
		col = 0;
		if (ft_strlen(argv[row + 1]) > 9)
			return (0);
		while (col < argc - 1)
		{
			if (argv[row + 1][col] >= '1' && argv[row + 1][col] <= '9')
				grid[row][col] = argv[row + 1][col] - 48;
			else if (argv[row + 1][col] == '.')
				grid[row][col] = 0;
			else
				return (0);
			col++;
		}
		row++;
	}
	return (1);
}

int		verif(int grid[9][9])
{
	int row;
	int col;

	row = 0;
	while (row < 9)
	{
		col = 0;
		while (col < 9)
		{
			if (!is_safe(grid, row, col, grid[row][col]))
				return (0);
			col++;
		}
		row++;
	}
	return (1);
}
