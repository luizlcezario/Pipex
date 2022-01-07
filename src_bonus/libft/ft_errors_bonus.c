/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 23:08:45 by llima-ce          #+#    #+#             */
/*   Updated: 2022/01/05 22:05:08 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"
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
