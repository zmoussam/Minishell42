# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/23 11:32:30 by mel-hous          #+#    #+#              #
#    Updated: 2022/11/07 13:04:55 by zmoussam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DEBUG := 0
CC := cc
INCLUDES := -I include -I$(HOME)/.brew/opt/readline/include
CFLAGS := $(INCLUDES) -Wall -Wextra -Werror -MMD $(shell [ "$(DEBUG)" = "1" ] && echo " -g") -g
LDFLAGS := -L$(HOME)/.brew/opt/readline/lib  -lreadline
NAME := minishell
SRC =	env1/create_env.c\
		env1/env_find.c\
		env1/env_ld.c\
	    lexer/change_mode.c\
		lexer/check_next_token.c\
		lexer/ft_expand_var.c\
		lexer/ft_expand_wldc.c\
		lexer/get_next_token.c\
		lexer/get_token.c\
		lexer/initialisation.c\
		lexer/is_match.c\
		lexer/lex_search.c\
		lexer/quote_def.c\
		lexer/wc_ld_create.c\
		utils/cmd_list.c\
		utils/remove_q.c\
		utils/wc_ld.c\
		av_creat.c\
		check_pipe.c\
		cmd_components.c\
		collect_cmd.c\
		collect_rdr.c\
		ft_pipe_line.c\
		node_creat.c\
		node_del.c\
		parse_input.c\
		parser_start.c\
		rdr_addback.c\
		execution/execution_utils.c\
		execution/execution_utils2.c\
		execution/execution.c\
		execution/builtins/cd.c\
		execution/builtins/echo.c\
		execution/builtins/env.c\
		execution/builtins/exit.c\
		execution/builtins/export.c\
		execution/builtins/pwd.c\
		execution/builtins/unset.c\
		main.c\

OBJ := $(SRC:.c=.o)
DEP := $(SRC:.c=.d)

.PHONY: all re clean fclean bonus

all: $(NAME)

clean:
	$(MAKE) -C libft clean
	rm -rf $(OBJ) $(DEP)

fclean:
	$(MAKE) -C libft fclean
	rm -f libft.a
	rm -rf $(NAME) $(OBJ) $(DEP)

re: fclean all

libft.a:
	$(MAKE) -C libft
	mv libft/libft.a .

$(NAME): libft.a $(OBJ)
	$(CC) -o $(NAME) $(OBJ) libft.a $(LDFLAGS)

-include $(DEP)