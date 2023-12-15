/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   untoken.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarizad <dgarizad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:55:54 by dgarizad          #+#    #+#             */
/*   Updated: 2023/06/11 13:55:23 by dgarizad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_data	g_data;

/**
 * @brief Copies the content of src into 
 * dest. Starts the copy to dest from index.
 * @param dest 
 * @param src 
 * @param index 
 * @return char* 
 */
char	*ft_copyy(char *dest, const char *src, size_t index)
{
	unsigned int	i;

	i = 0;
	while (i < ft_strlen(src))
	{
		dest[index] = src[i];
		index++;
		i++;
	}
	dest[index] = '\0';
	return (dest);
}

/**
 * @brief Modified version of strjoin.
 * This adds up a space between words.
 * @param s1 
 * @param s2 
 * @return int 
 */
static char	*ft_join(char *s1, char *s2)
{
	char	*new_string;
	int		last;

	new_string = (char *)ft_calloc(1, ft_strlen(s1) + ft_strlen(s2) + 2);
	if (!new_string)
		return (NULL);
	new_string = ft_copyy(new_string, s1, 0);
	last = ft_strlen(s1);
	new_string[last] = ' ';
	new_string = ft_copyy(new_string, s2, last + 1);
	return (new_string);
}

/**
 * @brief Iterates the **str and joins all rows 
 * in one line, adding a space between rows. 
 * 
 * @return char* 
 */
char	*ft_untoken(void)
{
	char	*newstr;
	char	*aux;
	int		i;

	i = 1;
	newstr = g_data.token1[0];
	while (g_data.token1[i] != NULL)
	{
		aux = newstr;
		newstr = ft_join(aux, g_data.token1[i]);
		if (i > 1)
			free (aux);
		aux = NULL;
		i++;
	}
	if (i == 1)
		g_data.flags.free_expanded = 1;
	return (newstr);
}
