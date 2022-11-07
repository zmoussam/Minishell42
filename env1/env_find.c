/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_find.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 13:38:13 by mel-hous          #+#    #+#             */
/*   Updated: 2022/11/06 18:44:05 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "../lexer/lexer.h"

void	print_list(void)
{
	t_env_list	*head;

	head = glb_v.list;
	while (head)
	{
		if (head->content[0] != '\0')
			printf("%s=%s\n", head->name, head->content);
		head = head->next;
	}
}

t_env_list *env_find(t_env_list *env, char  *s, int len)
{
    t_env_list *node;
    
    if (len == -1)
        len = ft_strlen(s);
    while(env)
    {
        if (len == env->len && !ft_strncmp(env->name, s, len))
        {
            node = env;
            return (node);
        }
        env = env->next;
    }
    return (NULL);
}

char *env_find2(t_env_list *env, char  *s, int len)
{   
    while(env)
    {
        if (!ft_strncmp(s, env->name, len))
            return (env->content);
        env = env->next;
    }
    return (NULL);
}

void	ft_list_remove_if(t_env_list **begin_list, void *data_ref)
{
	t_env_list	*cur;

	if (*begin_list == NULL || begin_list == NULL)
		return ;
	cur = *begin_list;
	if (ft_strcmp(cur->name, data_ref) == 0)
	{
		*begin_list = cur->next;
		free(cur->name);
		free(cur->content);
		free(cur);
		ft_list_remove_if(begin_list, data_ref);
	}
	else
		ft_list_remove_if(&cur->next, data_ref);
}

int	env_listsize(t_env_list *env)
{
	int	i;

	i = 0;
	while (env)
	{
		i++;
		env = env->next;
	}
	return (i);
}