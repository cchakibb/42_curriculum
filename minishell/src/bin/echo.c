/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <chbachir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 21:05:13 by emaydogd          #+#    #+#             */
/*   Updated: 2024/12/17 17:14:26 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	valid_quotes(char *str)
{
	int		inside_single;
	int		inside_double;
	size_t	i;

	inside_single = 0;
	inside_double = 0;
	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '\'' && !inside_double)
			inside_single = !inside_single;
		else if (str[i] == '\"' && !inside_single)
			inside_double = !inside_double;
		i++;
	}
	return (!inside_single && !inside_double);
}

static void	write_output(int fd, char *str, int has_next)
{
	if (fd != STDOUT_FILENO)
	{
		write(fd, str, ft_strlen(str));
		if (has_next)
			write(fd, " ", 1);
	}
	else
	{
		printf("%s", str);
		if (has_next)
			printf(" ");
	}
}

static int	check_n_option(t_list **args, char *content)
{
	char	*minus_n;

	if (!(*args) || !content)
		return (1);
	minus_n = remove_quotes(content);
	if (ft_strcmp(minus_n, "-n") == 0)
	{
		*args = (*args)->next;
		free(minus_n);
		return (0);
	}
	free(minus_n);
	return (1);
}

void	exec_echo(t_shell *shell, t_list *args)
{
	t_parser	*parser;
	int			newline;
	char		*original;

	parser = shell->parser;
	if (!args)
		return ((void)printf("\n"));
	newline = check_n_option(&args, args->content);
	if (ft_lstsize(args) == 1 && ft_strncmp(args->content, "~", 1) == 0)
		write_output(parser->outfile, ft_getenv(shell, "HOME"), 0);
	else
	{
		while (args)
		{
			original = remove_quotes((char *)args->content);
			write_output(parser->outfile, original, args->next != NULL);
			free(original);
			args = args->next;
		}
	}
	if (newline)
		write_output(parser->outfile, "\n", 0);
	shell->exit_status = 0;
}
