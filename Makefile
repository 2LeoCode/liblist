# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/19 23:12:58 by lsuardi           #+#    #+#              #
#    Updated: 2021/03/18 22:04:23 by lsuardi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL =		/bin/sh
.SUFFIXES =	.c .h .o

NAME =		liblist.a

SRCD =		src
INCD =		inc
OBJD =		.obj

SRC =		$(addsuffix $(word 1, $(.SUFFIXES)),\
			dup_f\
			free_f\
			utils\
			$(addprefix lst_,\
			apply\
			at\
			clear\
			create\
			dup\
			last\
			merge\
			new\
			push\
			rev\
			rm\
			shuffle\
			size\
			sort\
			prev))
INC =		$(addsuffix $(word 2, $(.SUFFIXES)),\
			list)
OBJ =		$(SRC:$(word 1, $(.SUFFIXES))=$(word 3, $(.SUFFIXES)))

CC =		gcc
CFLAGS =	-Wall\
			-Werror\
			-Wextra\
			-I $(INCD)

COUNT =		$(shell cat file.count 2>/dev/null)

ifeq ($(COUNT),)
all:
	@echo $(words $(SRC)) > file.count && $(MAKE) -n | grep $(CC) | wc -l | tr -d ' ' > tmp.txt && rm -f file.count && echo $$(($$(cat tmp.txt) - 1)) > file.count && rm -f tmp.txt && ./make/remake.sh
else
all: $(NAME)
endif

$(NAME): $(addprefix $(OBJD)/, $(OBJ)) | $(addprefix $(INCD)/, $(INC))
	@rm -f file.count && ar -rcs $@ $^ && echo '\r\033[2KCompiling [\033[32mOK\033[0m]'

$(OBJD):
	@mkdir $@

$(OBJD)/%$(word 3, $(.SUFFIXES)): $(SRCD)/%$(word 1, $(.SUFFIXES)) | $(OBJD)
	@./make/prc.sh 2>/dev/null && $(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJD)

fclean: clean
	@rm -f $(NAME)

re: fclean all
