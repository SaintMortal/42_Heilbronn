/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevadni <alevadni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 16:22:37 by alevadni          #+#    #+#             */
/*   Updated: 2026/02/05 17:46:54 by alevadni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	first_nb;

	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	first_nb = nb;
	i = 1;
	while (i < power)
	{
		nb = nb * first_nb;
		i++;
	}
	return (nb);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("%d", ft_recursive_power(-3, 3));
// 	return (0);
// }