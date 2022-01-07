/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfstr_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 22:02:08 by llima-ce          #+#    #+#             */
/*   Updated: 2022/01/05 22:05:08 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

char	*ft_strfstr(const char *str, const char *ptr)
{
	if (str == NULL || ptr == NULL)
		return (NULL);
	while (*str && !ft_strchr(ptr, *str))
		str++;
	if (*str == 0)
		return (NULL);
	return ((char *)str);
}
