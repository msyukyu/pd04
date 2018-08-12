/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 18:23:15 by dabeloos          #+#    #+#             */
/*   Updated: 2018/08/12 18:42:12 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_power(int nb, int power)
{
	int		i;
	int		result;

	result = 1;
	i = 0;
	while (i < power)
	{
		result *= nb;
		i++;
	}
	if (power < 0)
		result = 0;
	return (result);
}
