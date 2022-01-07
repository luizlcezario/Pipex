/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formatf_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:58:00 by luizz             #+#    #+#             */
/*   Updated: 2022/01/05 22:05:29 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*ft_formatf(const char *format, ...)
{
	t_format	*buffer;
	va_list		args;
	char		*formated;

	if (format == NULL)
		return (0);
	va_start(args, format);
	buffer = ft_start_struct(args);
	formated = ft_vformatf(format, buffer);
	ft_end_struct(buffer);
	va_end(args);
	return (formated);
}
