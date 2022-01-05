/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 23:08:45 by llima-ce          #+#    #+#             */
/*   Updated: 2022/01/05 16:39:27 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int	ft_error(int errnum, char *message)
{
	ft_printf("\033[31mError\n\033[35m");
	if (errnum > 0 && message != NULL)
		ft_printf("\t%s:%s\n", message, strerror(errnum));
	else
		perror(strerror(26));
	ft_printf("\033[0m");
	return (errnum);
}
