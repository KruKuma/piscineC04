/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfurst <nfurst@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 21:56:06 by nfurst            #+#    #+#             */
/*   Updated: 2026/07/02 11:52:04 by nfurst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_space(char c)
{
	if (c == ' ' || c == '\f' || c == '\n')
		return (1);
	if (c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

int	ft_check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-' || ft_is_space(base[i]))
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

int	ft_get_base_value(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_get_sign(char *str, int *i)
{
	int	sign;

	sign = 1;
	while (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			sign *= -1;
		(*i)++;
	}
	return (sign);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	sign;
	int	result;
	int	base_len;
	int	value;

	base_len = ft_check_base(base);
	if (base_len == 0)
		return (0);
	i = 0;
	sign = 1;
	result = 0;
	while (ft_is_space(str[i]))
		i++;
	sign = ft_get_sign(str, &i);
	value = ft_get_base_value(str[i], base);
	while (value != -1)
	{
		result = result * base_len + value;
		i++;
		value = ft_get_base_value(str[i], base);
	}
	return (result * sign);
}

// #include <stdio.h>
// int main(void)
// {
//     char *str = "   --+++123";
//     char *base = "0123456789";
//     printf("%d\n", ft_atoi_base(str, base));
//     return (0);
// }