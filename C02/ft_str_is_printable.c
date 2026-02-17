/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevadni <alevadni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 17:45:45 by alevadni          #+#    #+#             */
/*   Updated: 2026/01/28 18:22:11 by alevadni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_printable(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] > 126 || str[i] < 32)
		{
			return (0);
		}
		i++;
	}
	return (1);
}
