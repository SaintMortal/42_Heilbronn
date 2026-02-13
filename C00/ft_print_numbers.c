/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevadni <alevadni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:38:54 by alevadni          #+#    #+#             */
/*   Updated: 2026/01/23 11:39:52 by alevadni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void)
{
	char	a;

	a = 48;
	while (a <= 57)
	{
		write(1, &a, 1);
		a++;
	}
}

/*int main()
{
	ft_print_numbers();
	return (0);
}*/
