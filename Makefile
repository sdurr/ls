#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/17 09:02:37 by sdurr             #+#    #+#              #
#    Updated: 2015/03/13 18:27:08 by sdurr            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		= ft_ls

SRC			= main.c \
				transfer.c \
				exchange_link.c \
				no_files.c \
				test_perm.c \
				tri_ascii.c \
				ft_create_elem.c \
				ft_ls_read.c \
				test_open.c \
				ft_ls_path.c \
				test_option.c \
				check_option_illegal.c \
				ret_ls.c \
				ft_ls.c \
				ft_permission.c \
				ft_count_sous_dossiers.c \
				name_owner.c \
				ft_time.c \
				opt_l.c \
				opt_uid_time.c \
				nb_blocks.c \
				opt_t.c \
				test_dir.c \
				open_list.c \

OBJ			= $(SRC:.c=.o)

CC			= gcc

export CFLAGS		= -Wall -Wextra -Werror

RM			= rm -rf

$(NAME)	:		$(OBJ)
				make -C libft
				$(CC) -o $(NAME) $(OBJ) -L libft/ -lft

clean	:
				$(RM) $(OBJ)

all		:		$(NAME)

fclean	:		clean
				Make -C libft fclean
				$(RM) $(NAME)
				$(RM) *~

re		:		fclean all

.c.o	:
				$(CC) $(CFLAGS) -I libft/includes/ -c $(SRC)
