/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:50:04 by minkim3           #+#    #+#             */
/*   Updated: 2023/03/23 13:33:37 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/wait.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdbool.h>

enum e_definition
{
	ERROR = -1,
	EQUAL = 0,
	SUCCESS = 0,
};

typedef struct s_args
{
	char	*input_file;
	char	*output_file;
	char	**commands;
	int		num_commands;
	bool	here_doc;
	char	*limiter;
}	t_args;

typedef struct s_pipe
{
	int		input_fd;
	int		output_fd;
	int		*pipes;
	pid_t	*pid;
	char	**path;
	char	**commands;
	int		num_commands;
	bool	here_doc;
	char	*limiter;
}	t_pipe;

void	perror_return(const char *message, int status);
void	get_path(t_pipe *pipe, char *envp[]);
t_args	*get_args(int argc, char *argv[]);
char	*get_accessible_path(char **paths, char *command);
void	fork_childs(t_pipe *pipe, t_args *args, char *envp[]);
t_pipe	*init_pipe(t_args *args);
void	execute_pipeline(t_pipe *pipe, \
	t_args *args, int index, char *envp[]);
void	create_pipes_and_execute(t_pipe *pipe, t_args *args, char *envp[]);
void	close_pipe(t_pipe *pipe, t_args *args);

#endif