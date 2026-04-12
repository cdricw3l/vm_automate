/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 22:18:52 by cdric.b           #+#    #+#             */
/*   Updated: 2026/03/09 00:16:11 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define MODE_SIZE 0
#define MODE_FILL 1

static void	ft_putnbr_custom(int n, char **buffer, size_t *size, int mode)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		if (mode == MODE_FILL)
			(*buffer)[0] = '-';
		nb = nb * -1;
		(*size)++;
	}
	if (nb >= 10)
		ft_putnbr_custom(nb / 10, buffer, size, mode);
	if (mode == MODE_FILL && *buffer)
		(*buffer)[(*size)] = (nb % 10) + '0';
	(*size)++;
}

char	*ft_itoa(int n)
{
	char	*buffer;
	size_t	size;

	size = 0;
	ft_putnbr_custom(n, &buffer, &size, MODE_SIZE);
	if (size <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (size + 1));
	if (!buffer)
		return (NULL);
	buffer[size] = '\0';
	size = 0;
	ft_putnbr_custom(n, &buffer, &size, MODE_FILL);
	return (buffer);
}
