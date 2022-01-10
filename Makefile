GCC = gcc

NAME = pipex

LIBFT = ft_isdigit.c		\
		ft_memcpy.c			\
		ft_memmove.c		\
		ft_strlen.c			\
		ft_memset.c			\
		ft_bzero.c			\
		ft_strlcpy.c		\
		ft_strchr.c			\
		ft_strncmp.c		\
		ft_strnstr.c		\
		ft_atoi.c			\
		ft_strdup.c			\
		ft_substr.c			\
		ft_strjoin.c		\
		ft_strtrim.c		\
		ft_split.c			\
		ft_itoa.c			\
		ft_itoa_base.c		\
		ft_strfstr.c		\
		ft_errors.c			\
		ft_printf.c			\
		ft_vformatf.c		\
		ft_formatf.c		\
		struct_functions.c	\
		ft_check_all.c		\
		ft_formating.c		\
		ft_gets_s_c_p.c		\
		ft_gets_i_d.c		\
		ft_gets_u_x.c		\
		flags_formating.c	\
		flags_formating2.c	\
		ft_check_errors.c	\
		flags_pointer.c

FLAGS = -Wall -Wextra -Werror

SRC = main.c init_pipex.c init_cmds.c init_cmds_utils.c errors.c pipex.c \
pipex_utils.c ft_split_pipex.c

BONUS = $(SRC:.c=_bonus.c)

BONUS_LIBFT = $(LIBFT:.c=_bonus.c)

all: $(NAME)

$(NAME):
	${GCC} $(FLAGS) -I ./src/headers $(addprefix ./src/, $(SRC)) $(addprefix ./src/libft/, $(LIBFT)) -o $(NAME)

clean:
	rm $(NAME)

fclean:
	rm $(NAME)

re: fclean all

bonus: $(addprefix ./src_bonus/,$(BONUS))
	${GCC}  $(FLAGS)  -I ./src_bonus/headers $(addprefix ./src_bonus/, $(BONUS)) $(addprefix ./src_bonus/libft/, $(BONUS_LIBFT)) -o $(NAME)

re_bonus: fclean bonus

teste: re
	./pipex "./files/teste" "echo $FT_NBR2 + $FT_NBR1" "tr 'mrdoc' 01234" "tr ''\\\\\"?\!' 01234" "xargs echo 'obase=13;ibase=5;'" "bc" "tr '0123456789ABC' 'gtaio luSnemf' " "./files/res"

#  "cat" "tr ' ' '+'" "tr 'mrdoc' 01234" "tr ''\\\\\"?\!' 01234"  " xargs echo 'obase=13;ibase=5;'" "bc" "tr '0123456789ABC' 'gtaio luSnemf' "
.PHONY:clean all re fclean bonus re_bonus