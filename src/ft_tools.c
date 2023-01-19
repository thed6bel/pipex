/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 12:36:51 by hucorrei          #+#    #+#             */
/*   Updated: 2023/01/19 13:26:29 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

/*
a faire
void	ft_cmd_not_found(*cmd); pas obliger mais gagne quelques lignes

*/
void	ft_terminer(char *a)
{
	if (errno == 0)
		write(2, "Error\n", 6);
	else
		perror(a);
	exit(EXIT_FAILURE);
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return ;
}
