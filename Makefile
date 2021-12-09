GCC = gcc
NAME = pipex
LIBFT = ./libft/libft.a
LIB_PTH = ./libft
FLAGS = -Wall -Wextra -Werror
SRC = main.c init_pipex.c init_cmds.c init_cmds_utils.c errors.c pipex.c

all: $(NAME)
	./pipex ./files/teste "grep ola" "wc -l" ./files/res 

$(NAME):$(LIBFT)
	@${GCC} -g3 -I . $(addprefix ./src/, $(SRC)) -L $(LIB_PTH) -lft -o $(NAME)
	

$(LIBFT):
	make others -C $(LIB_PTH)

clean: 
	rm ./a.out

fclean:
	rm $(NAME)

re: fclean all

.PHONY:clean all