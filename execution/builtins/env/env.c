/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:42:14 by zmoussam          #+#    #+#             */
/*   Updated: 2022/10/18 18:48:40 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"
#include "env.h"

void	print_list()
{
	t_env_node *head;

	head = env_list;
	while (head)
	{
		
		if (head->content[0] != '\0' )
		printf("%s=%s\n", head->name, head->content);
		head = head->next;
	}
}

void    env_cmd(int argc)
{
    if (argc != 1)
        printf("use env with no options or arguments\n");
    else
        print_list();
}