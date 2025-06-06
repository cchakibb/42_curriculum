/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <chbachir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:26:33 by drongier          #+#    #+#             */
/*   Updated: 2024/12/17 18:07:52 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	handle_redirections_pipes(t_parser *parser)
{
	if (parser->infile != STDIN_FILENO)
	{
		dup2(parser->infile, STDIN_FILENO);
		close(parser->infile);
	}
	if (parser->outfile != STDOUT_FILENO)
	{
		dup2(parser->outfile, STDOUT_FILENO);
		close(parser->outfile);
	}
}

void	execute_command(t_shell *shell, t_parser *parser)
{
	char	**args;
	int		is_direct_path;
	char	*cmd_path;

	args = list_to_array(parser->args);
	if (args == NULL || args[0] == NULL)
		return (ft_error(shell, NULL, NULL, 130));
	is_direct_path = ft_strchr(args[0], '/') != NULL;
	if (ft_strcmp(args[0], "env") == 0)
		exec_env(*shell);
	else if (ft_strcmp(args[0], "export") == 0)
		exec_export(shell);
	else if (ft_strcmp(args[0], "exit") == 0)
		exec_exit(shell);
	else
	{
		cmd_path = get_command_path(shell, args[0], is_direct_path);
		if (cmd_path == NULL)
			ft_error(shell, "%s : command not found\n", args[0], -1);
		if (execve(cmd_path, args, NULL) == -1)
			ft_error(shell, "%s : command not found\n", args[0], -1);
		exit(127);
	}
}

void	wait_for_children(t_shell *shell)
{
	int	status;

	while (wait(&status) > 0)
	{
		if (WIFEXITED(status))
			shell->exit_status = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			shell->exit_status = 128 + WTERMSIG(status);
		else
			shell->exit_status = 1;
		shell->flag_pipe = 0;
	}
}

void	setup_pipe(t_parser *parser, int pipe_fd[2])
{
	if (pipe(pipe_fd) == -1)
	{
		perror("pipe");
		return ;
	}
	parser->outfile = pipe_fd[1];
	parser->next->infile = pipe_fd[0];
}

void	handle_pipe_error(int prev_fd, t_parser *parser)
{
	if (prev_fd != -1)
		close(prev_fd);
	if (parser->next)
	{
		close(parser->outfile);
		close(parser->next->infile);
	}
}
