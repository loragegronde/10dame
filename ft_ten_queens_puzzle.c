/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acampion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 12:52:43 by acampion          #+#    #+#             */
/*   Updated: 2025/07/21 22:31:48 by acampion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

void	write_queen(int grid[10][10], int *count);
int		ft_ten_queens_puzzle(void);
void	create_grid(int grid[10][10]);
int		check_col_row_diag(int grid[10][10], int row, int col);
int		solve(int grid[10][10], int pos, int num_q, int *count);
int		put_queen(int grid[10][10], int pos, int num_q);

int	ft_ten_queens_puzzle(void)
{
	int	grid[10][10];
	int	count;

	count = 0;
	create_grid(grid);
	solve(grid, 0, 0, &count);
	return (count);
}

void	create_grid(int grid[10][10])
{
	int	row;
	int	col;

	col = 0;
	while (col < 10)
	{
		row = 0;
		while (row < 10)
		{
			grid[row][col] = 0;
			row++;
		}
		col++;
	}
}

int	check_col_row_diag(int grid[10][10], int row, int col)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		if (grid[row][i] == 1 || grid[i][col] == 1)
			return (0);
		i++;
	}
	i = 1;
	while (row - i >= 0 && col + i < 10)
	{
		if (grid[row - i][col + i] == 1)
			return (0);
		i++;
	}
	i = 1;
	while (row - i >= 0 && col - i >= 0)
	{
		if (grid[row - i][col - i] == 1)
			return (0);
		i++;
	}
	return (1);
}

int	solve(int grid[10][10], int pos, int num_q, int *count)
{
	int	row;
	int	col;

	if (num_q == 10)
	{
		write_queen(grid, count);
		return (0);
	}
	if (pos >= 100)
		return (0);
	row = pos / 10;
	col = pos % 10;
	if (row > num_q)
		return(0);
	if (row == num_q && grid[row][col] == 0 &&
			check_col_row_diag(grid, row, col))
	{
		grid[row][col] = 1;
		solve(grid, pos + 1, num_q + 1, count);
		grid[row][col] = 0;
	}
	else
		solve(grid, pos + 1, num_q, count);
	return (0);
}

void	write_queen(int grid[10][10], int *count)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			if (grid[i][j] == 1)
			{
				c = j + '0';
				write(1, &c, 1);
			}
			j++;
		}
		i++;
	}
	write(1, "\n", 1);
	(*count)++;
}

int	main(void)
{
	int total;
	
	total = ft_ten_queens_puzzle();
	printf("Total solutions: %d\n", total);
}
