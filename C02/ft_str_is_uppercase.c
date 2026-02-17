/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevadni <alevadni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 17:17:28 by alevadni          #+#    #+#             */
/*   Updated: 2026/01/28 15:45:29 by alevadni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_uppercase(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] > 90 || str[i] < 65)
		{
			return (0);
		}
		i++;
	}
	return (1);
}
