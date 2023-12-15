/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 13:51:28 by vcereced          #+#    #+#             */
/*   Updated: 2023/06/13 19:29:00 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_data	g_data;

static char	*gen_string_with(char *str, int *j, char c)
{
	int		n;
	char	flag;

	n = 0;
	while ((str[*j] != c) && str[*j] != 0)
	{
		if (str[*j] == '\'' || str[*j] == '"')
		{
			flag = str[*j];
			n++;
			(*j)++;
			while (str[*j] != flag)
			{
				n++;
				(*j)++;
			}
		}
		n++;
		(*j)++;
	}
	return (ft_substr(&str[((*j) - n)], 0, n));
}

static unsigned char	*skip_marked_chars(unsigned char *tmp)
{
	int	i;

	i = 0;
	while (tmp[i] != '\0')
	{
		if (tmp[i] == 254)
		{
			while (tmp[i])
			{
				tmp[i] = tmp[i + 1];
				i++;
			}
			i = 0;
		}
		else
			i++;
	}
	return (tmp);
}

static char	*gen_string_without(char *str, int *j, char c)
{
	unsigned char	*tmp;

	tmp = (unsigned char *)gen_string_with(str, j, c);
	tmp = find_and_mark_chars(tmp);
	tmp = skip_marked_chars(tmp);
	return ((char *)tmp);
}

static char	*gen_str(char *str, int *j, char c)
{
	while (str[*j] != '\0')
	{
		if (str[*j] != c && str[*j] != 0)
		{
			if (g_data.flags.token1 == 0)
				return (gen_string_with(str, j, c));
			else
				return (gen_string_without(str, j, c));
		}
		else
			(*j)++;
	}
	return (NULL);
}

char	**specialsplit(char *str, char c)
{
	int		i;
	int		j;
	int		n;
	char	**matriz;

	if (!str || !(str[0]))
		return (NULL);
	n = count_str(str, c);
	matriz = malloc((n + 1) * sizeof(char *));
	matriz[n] = NULL;
	i = 0;
	j = 0;
	while (str[j] != '\0')
		matriz[i++] = gen_str(str, &j, c);
	return (matriz);
}
