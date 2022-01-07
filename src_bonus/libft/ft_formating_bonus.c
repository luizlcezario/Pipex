/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formating_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 18:19:55 by llima-ce          #+#    #+#             */
/*   Updated: 2022/01/05 22:05:29 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_formating(t_format *buffer)
{
	if (buffer->cf_now->conversion == 's')
		return (ft_get_string(buffer));
	else if (buffer->cf_now->conversion == 'c')
		return (ft_get_char(buffer));
	else if (buffer->cf_now->conversion == 'p')
		return (ft_get_adress(buffer));
	else if (buffer->cf_now->conversion == 'd'
		|| buffer->cf_now->conversion == 'i')
		return (ft_get_i_d(buffer));
	else if (buffer->cf_now->conversion == 'u')
		return (ft_get_u_x(buffer, "0123456789"));
	else if (buffer->cf_now->conversion == 'x')
		return (ft_get_u_x(buffer, HEX));
	else if (buffer->cf_now->conversion == 'X')
		return (ft_get_u_x(buffer, HEXU));
	else if (buffer->cf_now->conversion == '%')
		return (ft_get_percent(buffer));
}
