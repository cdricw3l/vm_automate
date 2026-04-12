/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 00:06:05 by cdric.b           #+#    #+#             */
/*   Updated: 2026/03/30 06:43:22 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	is_on_set(char c, char const *set)
{
	char	*ptr;

	ptr = (char *)set;
	while (*ptr)
	{
		if (*ptr == c)
			return (1);
		ptr++;
	}
	return (0);
}

static size_t	get_string_size(char const *str, char const *set)
{
	size_t	i;

	i = 0;
	while (str[i] && !is_on_set(str[i], set))
		i++;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	size;
	size_t	bytes_cp;
	char	*new_str;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	i = 0;
	while (s1[i] && is_on_set(s1[i], set))
		i++;
	size = get_string_size(&(s1[i]), set);
	new_str = malloc(sizeof(char) * (size + 1));
	if (!new_str)
		return (NULL);
	bytes_cp = ft_strlcpy(new_str, &s1[i], (size + 1));
	if (bytes_cp != ft_strlen(&s1[i]))
	{
		free(new_str);
		return (NULL);
	}
	return (new_str);
}
