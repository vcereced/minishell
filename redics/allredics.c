/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allredics.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:59:17 by dgarizad          #+#    #+#             */
/*   Updated: 2023/06/13 19:29:45 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_data	g_data;

/**
 * @brief Counts the number of redirections in order
 * to allocate enough strings for storing them.
 * It doesnt properly count if there is >>>>>>>
 * this can be improved. otherwise it will allocate
 * extra spaces, that wont generate errors.
 * @param str 
 * @param c 
 * @return int 
 */
static int	ft_count_redicc(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (*str)
	{
		if (str[0] == c)
		{
			count++;
			if (str[1] == c)
				str++;
		}
		str++;
	}
	return (count);
}

/**
 * @brief Auxc function for norminette issues.
 * Here is finally where the redirections are stored.
 * @param i 
 * @param j 
 * @param k 
 * @param c 
 * @return int 
 */
static int	auxc_auxc(int *i, int *j, int *k, char c)
{
	(*j)++;
	if (g_data.str_redic[*j] == '\0' || g_data.str_redic[*j] == ' ' \
	|| g_data.str_redic[*j] == c)
	{
		g_data.redics[*k] = ft_substr(g_data.str_redic, *i, *j - *i);
		delete_str(*i, *j, g_data.str_redic);
		(*k)++;
	}
	return (0);
}

/**
 * @brief Auxc function for norminette issues. 
 * Here the redirections are managed to be stored in a different array.
 *  data.infiles or data.outfiles.
 * Also here, the text for redirections is removed. 
 * @param i 
 * @param j 
 * @param k 
 * @param c 
 * @param str 
 * @return int 
 */
static int	auxc(int *i, int *j, int *k, char c)
{
	char	flag;

	flag = 0;
	c = 0;
	if (g_data.str_redic[*i] == '<' || g_data.str_redic[*i] == '>')
	{
		flag = g_data.str_redic[*i];
		(*j) = *i + 1;
		while (g_data.str_redic[*j] == ' ' || g_data.str_redic[*j] == flag)
			(*j)++;
		while (g_data.str_redic[*j] && g_data.str_redic[*j] != ' ' \
		&& g_data.str_redic[*j] != flag)
		{
			auxc_auxc(i, j, k, flag);
		}
		if (g_data.str_redic[*i + 1] == flag)
			(*i)++;
	}
			(*i)++;
	return (0);
}

/**
 * @brief Get the next redic character And build the appropriate
 * string to store it.
 * 
 * @param str 
 * @param c 
 * @return char 
 */
static char	get_next_redicc(char *str, char c)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	j = 0;
	g_data.str_redic = str;
	while (str[i] != '\0')
	{
		ignore_redics(str, &i);
		auxc(&i, &j, &k, c);
		if ((size_t)i > ft_strlen(str))
			break ;
	}
	g_data.str_redic = NULL;
	return (0);
}

/**
 * @brief Stores the redirections in the appropriate array.
 * 
 * @param str 
 * @return int 
 */
int	ft_redicc(char *str)
{
	int		i;
	int		all;
	char	*aux;

	i = ft_count_redicc(str, '>');
	aux = ft_strdup(str);
	if (i > 0)
		g_data.outfiles = ft_calloc(sizeof(char *), i + 1);
	get_next_redic(str, '>');
	all = i;
	i = ft_count_redicc(str, '<');
	all += i;
	if (i > 0)
	{
		g_data.infiles = ft_calloc(sizeof(char *), i + 1);
		get_next_redic(str, '<');
	}
	if (all > 0)
	{
		g_data.redics = ft_calloc(sizeof(char *), all + 1);
		get_next_redicc(aux, '<');
		analyze_redicc();
	}
	free(aux);
	return (0);
}
