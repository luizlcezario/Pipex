/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_errors_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 18:19:50 by llima-ce          #+#    #+#             */
/*   Updated: 2022/01/05 22:05:29 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_new_errors(t_format *buffer, int type)
{
	if (type == 1)
	{
		buffer->len = buffer->len + 1;
		write(1, "%", 1);
		return (1);
	}
	else if (type == 2)
	{
		write(1, "", 1);
		return (2);
	}
	return (1);
}
