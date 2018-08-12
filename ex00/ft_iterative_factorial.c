/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 14:46:24 by dabeloos          #+#    #+#             */
/*   Updated: 2018/08/12 15:38:50 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	if (nb > 1)
		return (nb * ft_iterative_factorial(nb - 1));
	else if (nb > -1)
		return (1);
	else
		return (0);
}
