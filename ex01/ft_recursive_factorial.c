/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 14:46:24 by dabeloos          #+#    #+#             */
/*   Updated: 2018/08/13 11:56:12 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_factorial(int nb)
{
	if (nb > 12)
		return (0);
	if (nb > 1)
		return (nb * ft_recursive_factorial(nb - 1));
	else if (nb > -1)
		return (1);
	else
		return (0);
}
