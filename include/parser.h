/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syakoubi <splentercell.1997@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 18:21:39 by syakoubi          #+#    #+#             */
/*   Updated: 2022/06/25 18:18:04 by syakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "libft.h"
# include "lexer.h"
# include <stdbool.h>

typedef enum e_rdr_type
{
	RDR_IN,
	RDR_HEREDOC,
	RDR_OUT,
	RDR_OUT_APP,
}	t_rdr_type;

typedef enum e_node_type
{
	SIMPLE_CMD,
	SUBSHELL,
	PIPE,
	OR,
	AND,
}	t_node_type;

typedef struct s_rdr
{
	t_rdr_type	type;
	char		*f;
}	t_rdr;

typedef struct s_node
{
	t_node_type		type;
	t_list			*rdrlst;
	int				argc;
	char			**argv;
	struct s_node	*left;
	struct s_node	*right;
}	t_node;

void	node_tree_clear(t_node **node);
t_node	*parse(char *line);

#endif /* PARSER_H */
