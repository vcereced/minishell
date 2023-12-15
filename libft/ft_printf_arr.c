/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_arr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 19:54:02 by vcereced          #+#    #+#             */
/*   Updated: 2023/06/09 18:45:52 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../minishell.h"

int	ft_printf_arr(char **arr)
{
	int	n;

	n = 0;
	while (arr[n])
	{
		printf("%s\n", arr[n]);
		n++;
	}
	return (EXIT_SUCCESS);
}
