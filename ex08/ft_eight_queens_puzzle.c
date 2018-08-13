/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eight_queens_puzzle.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 14:49:37 by dabeloos          #+#    #+#             */
/*   Updated: 2018/08/13 21:59:45 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void	ft_initialize_array(int board[][8])
{
	int		l;
	int		c;

	l = -1;
	while (++l < 8)
	{
		c = -1;
		while (++c < 8)
		{
			board[l][c] = 0;
		}
	}
	return (0);

}

void	ft_restrict_lines(int board[][8], int cl, int cc, int d)
{
	int		l;
	int		c;

	l = -1;
	c = -1;
	while (++c < 8)
	{
		if (board[cl][c] == 0)
			board[cl][c] = d;
		if (board[c][cc] == 0)
			board[c][cc] = d;
	}
	c = -8;
	while (++c < 8)
	{
		if (cc - c > -1 && cl - c > -1 && cc - c < 8 && cl - c < 8 &&
				board[cl - c][cc - c] == 0)
			board[cl - c][cc - c] = d;
		if (cc + c > -1 && cl - c > -1 && cc + c < 8 && cl - c < 8 &&
				board[cl - c][cc + c] == 0)
			board[cl - c][cc + c] = d;
	}
}

void	ft_put_a_queen(int board[][8], int line)
{
	
}

int		ft_eight_queens_puzzle(void)
{
	int		board[8][8];

	ft_initialize_array(board);

}

int		main(int argc, char *argv[])
{
	int		board[8][8];
	int		l;
	int		c;

	l = -1;
	while (++l < 8)
	{
		c = -1;
		while (++c < 8)
		{
			board[l][c] = 0;
		}
	}
	if (argc == 3)
	{
		ft_restrict_lines(board, atoi(argv[1]), atoi(argv[2]), 1);
		l = -1;
		while (++l < 8)
		{
			c = -1;
			while (++c < 8)
			{
				printf(" %d ", board[l][c]);
			}
			printf("\n");
		}
	}
	return (0);
}
