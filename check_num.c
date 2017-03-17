/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 13:02:32 by wliu              #+#    #+#             */
/*   Updated: 2016/11/06 16:39:12 by wliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

int	find_missing(int grid[9][9], int *row_ptr, int *col_ptr)
{
	int row;
	int col;

	row = 0;
	while (row < 9)
	{
		col = 0;
		while (col < 9)
		{
			if (grid[row][col] == 0)
			{
				*row_ptr = row;
				*col_ptr = col;
				return (1);
			}
			col++;
		}
		row++;
	}
	return (0);
}

int	used_in_row(int grid[9][9], int row, int ex_col, int num)
{
	int col;

	col = 0;
	while (col < 9)
	{
		if (ex_col != col && grid[row][col] == (num))
			return (1);
		col++;
	}
	return (0);
}

int	used_in_col(int grid[9][9], int ex_row, int col, int num)
{
	int row;

	row = 0;
	while (row < 9)
	{
		if (ex_row != row && grid[row][col] == num)
			return (1);
		row++;
	}
	return (0);
}

int	used_in_box(int grid[9][9], int row, int col, int num)
{
	int start_row;
	int start_col;
	int i;
	int j;

	start_row = (row - row % 3);
	start_col = (col - col % 3);
	i = start_row;
	while (i < start_row + 3)
	{
		j = start_col;
		while (j < start_col + 3)
		{
			if (!(i == row && j == col) && grid[i][j] == (num))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_safe(int grid[9][9], int row, int col, int num)
{
	if (!used_in_row(grid, row, col, num)
			&& !used_in_col(grid, row, col, num)
			&& !used_in_box(grid, row, col, num))
		return (1);
	else
		return (0);
}
