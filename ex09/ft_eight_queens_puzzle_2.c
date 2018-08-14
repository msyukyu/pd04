/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eight_queens_puzzle.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 14:49:37 by dabeloos          #+#    #+#             */
/*   Updated: 2018/08/14 16:04:20 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int					ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

struct				s_chessboard
{
	int		chessboard[8][8];
};

void				ft_show_board(struct s_chessboard board)
{
	int	l;
	int	c;

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

struct s_chessboard	ft_initialize_array(void)
{
	int					l;
	int					c;
	struct s_chessboard	board;

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

struct s_chessboard	ft_copy_board(struct s_chessboard board)
{
	struct s_chessboard	newboard;
	int					c;
	int					l;

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

struct s_chessboard	ft_restrict_lines(struct s_chessboard board, int cl, int cc)
{
	int		l;
	int		c;

	l = -1;
	c = -1;
	if (board.chessboard[cl][cc] == 0)
		board.chessboard[cl][cc] = cl + 1;
	while (++c < 8)
	{
		if (board.chessboard[cl][c] == 0)
			board.chessboard[cl][c] = 9;
		if (board.chessboard[c][cc] == 0)
			board.chessboard[c][cc] = 9;
	}
	c = -8;
	while (++c < 8)
	{
		if (cc - c > -1 && cl - c > -1 && cc - c < 8 && cl - c < 8 &&
				board.chessboard[cl - c][cc - c] == 0)
			board.chessboard[cl - c][cc - c] = 9;
		if (cc + c > -1 && cl - c > -1 && cc + c < 8 && cl - c < 8 &&
				board.chessboard[cl - c][cc + c] == 0)
			board.chessboard[cl - c][cc + c] = 9;
	}
	return (board);
}

void				ft_put_a_queen(struct s_chessboard board, int line)
{
	int					c;
	struct s_chessboard	newboard;

	c = -1;
	while (++c < 8)
	{
		if (board.chessboard[line][c] == 0)
		{
			newboard = ft_restrict_lines(board, line, c);
			if (line == 7)
			{
				line = -1;
				while (++line < 8)
				{
					c = -1;
					while (++c < 8)
						if (newboard.chessboard[line][c] != 9)
							ft_putchar('0' + c + 1);
				}
				ft_putchar('\n');
			}
			else
				ft_put_a_queen(ft_copy_board(newboard), line + 1);
		}
	}
}

void				ft_eight_queens_puzzle_2(void)
{
	struct s_chessboard	board;

	board = ft_initialize_array();
	ft_put_a_queen(board, 0);
}

int					main(int argc, char *argv[])
{
	struct s_chessboard	board;

	board = ft_initialize_array();
	if (argc == 3)
	{
		board = ft_restrict_lines(board, atoi(argv[1]), atoi(argv[2]));
		ft_show_board(board);
	}
	ft_eight_queens_puzzle_2();
	return (0);
}
