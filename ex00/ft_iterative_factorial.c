/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 14:46:24 by dabeloos          #+#    #+#             */
/*   Updated: 2018/08/12 15:10:54 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int ft_iterative_factorial(int nb)
{
	if (nb > 1)
		return (nb * ft_iterative_factorial(nb - 1));
	else if (nb > -1)
		return 1;
	else
		return 0;
}

int main(int argc, char *argv[])
{
	int k = atoi(argv[1]);
	if (argc == 2)
		printf("%d", ft_iterative_factorial(k));
}
