/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevadni <alevadni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 16:13:12 by alevadni          #+#    #+#             */
/*   Updated: 2026/02/01 14:10:58 by alevadni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	if (to_find[i] == '\0')
	{
		return (str);
	}
	while (str[i])
	{
		j = 0;
		while (str[i + j] == to_find[j])
		{	
			if (to_find[j + 1] == 0)
			{
				return (str + i);
			}
			j++;
		}
		i++;
	}
	return (str + i);
}

/*#include <stdio.h>

int main()
{
	char str1[] = "hello world";
	char str2[] = "world1";

	printf("%s", ft_strstr(str1, str2));
	return (0);
}*/
