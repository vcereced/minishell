/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:59:17 by dgarizad          #+#    #+#             */
/*   Updated: 2023/06/13 17:23:55 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_data	g_data;

static int	ft_execve(char **arr)
{
	char	*str_path;
	char	**matriz_command;

	gen_command_and_path(arr, g_data.env, &str_path, &matriz_command);
	execve(str_path, matriz_command, g_data.env);
	free(str_path);
	str_error(arr[0], "command not found");
	return (127);
}

static int	ft_built_in(char **arr)
{
	if (!ft_strncmp(arr[0], "echo", ft_strlen("echo")) && \
	(ft_strlen("echo") == ft_strlen(arr[0])))
		return (ft_echo(arr));
	else if (!ft_strncmp(arr[0], "export", ft_strlen("export")) \
	&& (ft_strlen("export") == ft_strlen(arr[0])))
		return (ft_export(arr));
	else if (!ft_strncmp(arr[0], "unset", ft_strlen("unset")) \
	&& (ft_strlen("unset") == ft_strlen(arr[0])))
		return (ft_unset(arr));
	else if (!ft_strncmp(arr[0], "cd", ft_strlen("cd")) \
	&& (ft_strlen("cd") == ft_strlen(arr[0])))
		return (ft_cd(arr));
	else if (!ft_strncmp(arr[0], "pwd", ft_strlen("pwd")) \
	&& (ft_strlen("pwd") == ft_strlen(arr[0])))
		return (ft_pwd(arr));
	else if (!ft_strncmp(arr[0], "env", ft_strlen("env")) \
	&& (ft_strlen("env") == ft_strlen(arr[0])))
		return (ft_env());
	else if (!ft_strncmp(arr[0], "exit", ft_strlen("exit")) \
	&& (ft_strlen("exit") == ft_strlen(arr[0])))
		return (ft_exit());
	else
		return (-1);
}

static int	ft_execute(char **arr)
{
	int	status;

	if (!arr)
		return (0);
	status = ft_built_in(arr);
	if (status != -1)
		return (status);
	else
		return (ft_execve(arr));
}

/**
 * @brief Reveives a unique string containing only one command and
 * their redirections. 
 * Checks if there are redirections and removes them from
 * the arguments.
 * Stores the redirection names in two arrays (for infiles and for outifiles)
 * @param str 
 * @return int 
 */
int	ft_program(char *str)
{
	int	i;

	g_data.tokenized_cmd = specialsplit(str, ' ');
	i = ft_check_exe();
	if (i == 0)
		return (ft_built_in(g_data.tokenized_cmd));
	else
	{
		ft_free_split(g_data.tokenized_cmd);
		g_data.tokenized_cmd = NULL;
	}
	ft_redicc(str);
	if (is_space(str))
		ft_exit();
	g_data.flags.token1 = 1;
	g_data.tokenized_cmd = specialsplit(str, ' ');
	return (ft_execute(g_data.tokenized_cmd));
}
