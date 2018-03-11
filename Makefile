# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: ppichier <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/01/29 19:18:25 by ppichier     #+#   ##    ##    #+#        #
#   Updated: 2018/02/06 16:03:12 by ppichier    ###    #+. /#+    ###.fr     # #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = $(NAME1) $(NAME2)

FLAGS = -Wall -Wextra -Werror

FILES_PS = ft_pushswap.c

FILES_CHK = ft_checker.c

FILES_COM = ft_parsing.c ft_central.c ft_op_pab.c ft_op_rotateab.c \
 			ft_op_reverse_rotateab.c ft_algo_sort.c ft_verify_op.c \
 			ft_op_sab.c ft_pile_b.c ft_pile_a.c ft_tools_sort.c \
 			ft_split_arg.c ft_enormous.c ft_rec_tools.c \

HEADERS = ft_pushswap.h

LIBS = ./libft/libft.a

OBJ_PS = $(FILES_PS:.c=.o) 

OBJ_CHK = $(FILES_CHK:.c=.o)

OBJ_COM = $(FILES_COM:.c=.o)

NAME1 = push_swap

NAME2 = checker

.PHONY: all clean fclean re

all: $(NAME)

$(NAME1): $(OBJ_PS) $(OBJ_COM) $(LIBS)
	@echo "\033[33m"
	gcc -o $(NAME1) $(OBJ_PS) $(OBJ_COM) -L libft -l ft

$(NAME2): $(OBJ_CHK) $(OBJ_COM) $(LIBS)
	@echo "\033[33m"
	gcc -o $(NAME2) $(OBJ_CHK) $(OBJ_COM) -L libft -l ft

$(LIBS):
	make -C libft/

%.o: $(FILES_PS)%.c $(FILES_CHK)%.c $(FILES_COM)%.c
	@echo "\033[36m"
	gcc -I $(HEADERS) $(FLAGS) -c $(FILES_PS) $(FILES_CHK) $(FILES_COM)

clean:
	@echo "\033[31m"
	rm -f $(OBJ_PS) $(OBJ_CHK) $(OBJ_COM)
	make clean -C libft/

fclean: clean
	@echo "\033[31m"
	rm -f $(NAME1) $(NAME2)
	make fclean -C libft/

re: fclean all
