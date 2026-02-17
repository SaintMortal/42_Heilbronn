/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevadni <alevadni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 15:03:52 by alevadni          #+#    #+#             */
/*   Updated: 2026/01/28 18:23:47 by alevadni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_alpha(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] > 122 || str[i] < 65)
		{
			return (0);
		}
		else if (str[i] > 90 && str[i] < 97)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

// int main()
// {
// 	char arr[] = "rggrgF";
// 	ft_str_is_alpha(arr);
// }
