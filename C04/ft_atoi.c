/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevadni <alevadni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 16:42:48 by alevadni          #+#    #+#             */
/*   Updated: 2026/02/03 16:56:50 by alevadni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	if_spaces(char *str)
{
	if (*str == '\t' || *str == '\n' || *str == '\v' || *str == '\f'
		|| *str == '\r' || *str == ' ')
	{
		return (1);
	}
	return (0);
}

int	which_sign(char *str)
{
	int	sign;

	sign = 1;
	while (*str)
	{
		if (*str == '-')
		{
			sign = sign * (-1);
		}
		str++;
	}
	return (sign);
}

int	ft_atoi(char *str)
{
	int	sign;
	int	num;
	int	final_num;
	int	count;

	count = 0;
	while (str[count] && if_spaces(&str[count]))
	{
		count++;
	}
	while (str[count] && (str[count] == '+' || str[count] == '-'))
	{
		count++;
	}
	sign = which_sign(str);
	final_num = 0;
	while (str[count] != '\0' && str[count] >= '0' && str[count] <= '9')
	{
		num = (str[count] - '0');
		final_num = (final_num * 10) + num;
		count++;
	}
	return (final_num * sign);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char string[] = "     --     +++----123 345";

// 	printf("The result is : %d\n", ft_atoi(string));

// 	return (0);
// }