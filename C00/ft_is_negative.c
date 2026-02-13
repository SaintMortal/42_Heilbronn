/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevadni <alevadni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 16:23:11 by alevadni          #+#    #+#             */
/*   Updated: 2026/01/23 10:28:49 by alevadni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int n)
{
	char	po;
	char	ne;

	ne = 'N';
	po = 'P';
	if (n < 0)
	{
		write(1, &ne, 1);
	}
	else
	{
		write(1, &po, 1);
	}
}

/*int main(void)
{
	ft_is_negative(0);
	return (0);
}*/
