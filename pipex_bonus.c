/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 21:57:00 by minkim3           #+#    #+#             */
/*   Updated: 2023/03/21 21:59:18 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_pipe	*pipe;
	char	*input_file;
	char	**commands;
	char	*output_file;

	if (argc < 4)
		perror_return("Incorrect number of arguments", 1);
	input_file = argv[1];
	first_command = argv[2];
	second_command = argv[3];
	output_file = argv[4];
	pipe = init_pipe(input_file, output_file);
	get_path(pipe, envp);
	fork_child_one(pipe, first_command, envp);
	fork_child_two(pipe, second_command, envp);
	close_parent(pipe);
	waitpid(pipe->pid_one, NULL, 0);
	waitpid(pipe->pid_two, NULL, 0);
	free_two_dementional_array(pipe->path);
	free(pipe);
	return (0);
}
