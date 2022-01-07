/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 13:14:31 by llima-ce          #+#    #+#             */
/*   Updated: 2022/01/05 22:05:08 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

char	*ft_strnstr(const char *str, const char *ptr, size_t n)
{
	size_t	ptrlen;

	ptrlen = ft_strlen(ptr);
	if (!ptrlen)
		return ((char *)str);
	while (*str && ptrlen <= n--)
	{
		if (ft_strncmp(str, ptr, ptrlen) == 0)
			return ((char *)str);
		str++;
	}
	return (NULL);
}
