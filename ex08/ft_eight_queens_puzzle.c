/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eight_queens_puzzle.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 14:49:37 by dabeloos          #+#    #+#             */
/*   Updated: 2018/08/14 14:33:35 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

struct		chessboard
{
	int		chessboard[8][8];
};

void	ft_show_board(struct chessboard board)
{
	int     l;
	int     c;

	l = -1;
	while (++l < 8)
	{
		c = -1;
		while (++c < 8)
		{
			printf(" %d ", board.chessboard[l][c]);
		}
		printf("\n");
	}
}

struct chessboard	ft_initialize_array(void)
{
	int		l;
	int		c;
	struct chessboard	board;

	l = -1;
	while (++l < 8)
	{
		c = -1;
		while (++c < 8)
		{
			board.chessboard[l][c] = 0;
		}
	}
	return (board);
}

struct chessboard	ft_copy_board(struct chessboard board)
{
	struct chessboard	newboard;
	int			c;
	int			l;

	newboard = ft_initialize_array();
	l = -1;
	while (++l < 8)
	{
		c = -1;
		while (++c < 8)
		{
			newboard.chessboard[l][c] = board.chessboard[l][c];
		}
	}
	return (newboard);
}

struct chessboard	ft_restrict_lines(struct chessboard board, int cl, int cc)
{
	int		l;
	int		c;

	l = -1;
	c = -1;
	while (++c < 8)
	{
		if (board.chessboard[cl][c] == 0)
			board.chessboard[cl][c] = cl + 1;
		if (board.chessboard[c][cc] == 0)
			board.chessboard[c][cc] = cl + 1;
	}
	c = -8;
	while (++c < 8)
	{
		if (cc - c > -1 && cl - c > -1 && cc - c < 8 && cl - c < 8 &&
				board.chessboard[cl - c][cc - c] == 0)
			board.chessboard[cl - c][cc - c] = cl + 1;
		if (cc + c > -1 && cl - c > -1 && cc + c < 8 && cl - c < 8 &&
				board.chessboard[cl - c][cc + c] == 0)
			board.chessboard[cl - c][cc + c] = cl + 1;
	}
	return (board);
}

int		ft_put_a_queen(struct chessboard board, int line)
{
	int		c;
	int		count;
	struct chessboard	newboard;

	count = 0;
	c = 0;
	while (c < 8)
	{
		if (board.chessboard[line][c] == 0)
		{
			newboard = ft_restrict_lines(board, line, c);
			if (line == 7)
			{
				count++;
			}
			else
				count += ft_put_a_queen(ft_copy_board(newboard), line + 1);
		}
		c++;
	}
	return (count);
}

int		ft_eight_queens_puzzle(void)
{
	struct chessboard	board;

	board = ft_initialize_array();
	return (ft_put_a_queen(board, 0));
}

int		main(int argc, char *argv[])
{
	struct chessboard	board;
	int		c;

	board = ft_initialize_array();
	if (argc == 3)
	{
		board = ft_restrict_lines(board, atoi(argv[1]), atoi(argv[2]));
		ft_show_board(board);
	}
	c = ft_eight_queens_puzzle();
	printf("%d", c);
	return (0);
}
