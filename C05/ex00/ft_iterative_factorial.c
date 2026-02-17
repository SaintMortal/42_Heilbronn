/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevadni <alevadni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 13:09:55 by alevadni          #+#    #+#             */
/*   Updated: 2026/02/05 17:47:50 by alevadni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	count_fa;

	if (nb == 0)
	{
		return (1);
	}
	if (nb < 0)
	{
		return (0);
	}
	i = 1;
	count_fa = 1;
	while (i <= nb)
	{
		count_fa = count_fa * i;
		i++;
	}
	return (count_fa);
}

// #include <stdio.h>

// int main()
// {
// 	printf("%d", ft_iterative_factorial(6));
// 	return (0);
// }
