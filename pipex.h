/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 13:32:04 by hucorrei          #+#    #+#             */
/*   Updated: 2023/01/26 13:29:10 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <errno.h>
# include "./libft/libft.h"

char	*ft_path(char *cmd, char **envp);
void	ft_free(char **str);
void	ft_exit(char *a);
void	ft_cmd_not_found(char **cmd);
void	ft_argc_error(void);
void	ft_ctrl_arg(char **cmd);

#endif
