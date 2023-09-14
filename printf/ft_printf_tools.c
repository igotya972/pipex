/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:37:16 by dferjul           #+#    #+#             */
/*   Updated: 2022/12/19 18:19:18 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putnbr(int nb)
{
	int	i;

	i = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	else
	{
		if (nb < 0)
		{
			nb = -nb;
			i += ft_putchar('-');
		}
		if (nb < 10)
			i += ft_putchar(nb + 48);
		else
		{
			i += ft_putnbr(nb / 10);
			i += ft_putnbr(nb % 10);
		}
	}
	return (i);
}

int	ft_putnbr_unsint(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb >= 10)
	{
		i += ft_putnbr_unsint(nb / 10);
		i += ft_putnbr_unsint(nb % 10);
	}
	else
		i += ft_putchar(nb + '0');
	return (i);
}

int	ft_putconv(unsigned int p, char *s)
{
	int	len;

	len = 0;
	if (p >= 16)
	{
		len += ft_putconv(p / 16, s);
		len += ft_putchar(s[p % 16]);
	}
	else
		len += ft_putchar(s[p]);
	return (len);
}

static void	ft_pl(unsigned long long nb, char *base, int *len)
{
	if (nb >= 16)
		ft_pl(nb / 16, base, len);
	ft_putchar(base[nb % 16]);
	(*len)++;
}

int	printf_ptr(unsigned long long ptr)
{
	int	len;

	len = 0;
	len += ft_putstr("0x");
	ft_pl(ptr, "0123456789abcdef", &len);
	return (len);
}
