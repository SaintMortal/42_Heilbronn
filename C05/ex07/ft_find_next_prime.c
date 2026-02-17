/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevadni <alevadni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 20:38:43 by alevadni          #+#    #+#             */
/*   Updated: 2026/02/08 12:52:35 by alevadni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	flag;
	int	i;

	if (nb < 2)
	{
		return (0);
	}
	i = 1;
	flag = 0;
	while (i <= nb)
	{
		if (nb % i == 0)
		{
			flag++;
		}
		i++;
	}
	if (flag == 2)
		return (1);
	else
		return (0);
}

int	ft_find_next_prime(int nb)
{
	int	count;

	count = nb;
	while (!ft_is_prime(nb))
	{
		nb++;
	}
	return (nb);
}
