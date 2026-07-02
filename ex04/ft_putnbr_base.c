/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfurst <nfurst@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 21:46:46 by nfurst            #+#    #+#             */
/*   Updated: 2026/07/02 11:21:30 by nfurst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
        i++;
    return i;
}

int ft_is_valid_base(char *base)
{
    int i;
    int j;

    if (ft_strlen(base) < 2)
        return 0;
    i = 0;
    while (base[i] != '\0')
    {
        if (base[i] == '+' || base[i] == '-')
            return 0;
        j = i + 1;
        while (base[j] != '\0')
        {
            if (base[i] == base[j])
                return 0;
            j++;
        }
        i++;
    }
    return 1;
}

void ft_print_base(long nb, char *base, int base_len)
{
    char c;

    if (nb >= base_len)
        ft_print_base(nb / base_len, base, base_len);
    c = base[nb % base_len];
    write(1, &c, 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
    long nb;
    int base_len;

    if (!ft_is_valid_base(base))
        return;
    nb = (long)nbr;
    base_len = ft_strlen(base);
    if (nb < 0)
    {
        write(1, "-", 1);
        nb = -nb;
    }
    ft_print_base(nb, base, base_len);
}

// #include <stdlib.h>
// int main(int argc, char *argv[])
// {
// 	if (argc != 3)
// 		return (1);
//     ft_putnbr_base(atoi(argv[1]), argv[2]);
//     return 0;
// }