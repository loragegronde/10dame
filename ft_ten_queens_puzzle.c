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

// Vérifie si une reine peut être placée à la position (row, col) sans conflit avec les autres
int	is_safe(int queens[10], int row, int col)
{
	int i;
	i = 0;
	while (i < row)
	{
		// Vérifie la colonne et les deux diagonales
		if (queens[i] == col || (i - row) == (queens[i] - col) || (row - i) == (queens[i] - col))
			return (0);
		i++;
	}
	return (1);
}

// Affiche une solution valide (une position possible des 10 reines)
// et incrémente le compteur de solutions
void	write_queen(int queens[10], int *count)
{
	int i;
	char c;
	i = 0;
	while (i < 10)
	{
		// Affiche la colonne de chaque reine pour chaque ligne
		c = queens[i] + '0';
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
	(*count)++;
}

// Place les reines une par une, ligne par ligne, de façon récursive
void	solve(int queens[10], int row, int *count)
{
	int col;
	// Si on a placé 10 reines, on affiche la solution
	if (row == 10)
	{
		write_queen(queens, count);
		return;
	}
	col = 0;
	while (col < 10)
	{
		// Tente de placer une reine à la colonne col si c'est possible
		if (is_safe(queens, row, col))
		{
			queens[row] = col;
			// Passe à la ligne suivante
			solve(queens, row + 1, count);
		}
		col++;
	}
}

// Fonction principale qui initialise le tableau et lance la recherche
int	ft_ten_queens_puzzle(void)
{
	int queens[10]; // queens[i] = colonne de la reine sur la ligne i
	int count;
	count = 0;
	// Commence la résolution à partir de la première ligne
	solve(queens, 0, &count);
	return (count);
}

// Point d'entrée du programme
int	main(void)
{
	int total;
	// Calcule le nombre total de solutions et l'affiche
	total = ft_ten_queens_puzzle();
	printf("Total solutions: %d\n", total);
	return (0);
}
