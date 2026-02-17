/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevadni <alevadni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 16:38:36 by alevadni          #+#    #+#             */
/*   Updated: 2026/01/28 18:23:45 by alevadni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_numeric(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 48 | str[i] > 57)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

/*int main()
{
	char arr[] = "231f2313";
	ft_str_is_numeric(arr);
}*/
