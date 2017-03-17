/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 12:54:49 by wliu              #+#    #+#             */
/*   Updated: 2016/11/06 21:08:53 by jinfeld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUDOKU_H
# define SUDOKU_H

# include <unistd.h>

int		find_missing(int grid[9][9], int *row_ptr, int *col_ptr);
int		used_in_row(int grid[9][9], int row, int ex_col, int num);
int		used_in_col(int grid[9][9], int row, int ex_col, int num);
int		used_in_box(int grid[9][9], int row, int col, int num);
int		is_safe(int grid[9][9], int row, int col, int num);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
void	print_grid(int grid[9][9]);
int		sudoku_input(int grid[9][9], int argc, char **argv);
int		solve_sudoku(int grid[9][9]);
int		solve_test(int grid[9][9]);
int		verif(int grid[9][9]);

#endif
