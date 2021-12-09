GCC = gcc
NAME = pipex

LIBFT =  ft_isalpha.c		\
		ft_isdigit.c		\
		ft_isalnum.c		\
		ft_isascii.c		\
		ft_isprint.c		\
		ft_strlen.c			\
		ft_memset.c			\
		ft_bzero.c			\
		ft_memcpy.c			\
		ft_memmove.c		\
		ft_strlcpy.c		\
		ft_strlcat.c		\
		ft_toupper.c		\
		ft_tolower.c		\
		ft_strchr.c			\
		ft_strrchr.c		\
		ft_strncmp.c		\
		ft_memchr.c			\
		ft_memcmp.c			\
		ft_strnstr.c		\
		ft_atoi.c			\
		ft_calloc.c			\
		ft_strdup.c			\
		ft_substr.c			\
		ft_strjoin.c		\
		ft_strtrim.c		\
		ft_split.c			\
		ft_itoa.c			\
		ft_putchar_fd.c		\
		ft_putstr_fd.c		\
		ft_putendl_fd.c		\
		ft_strmapi.c		\
		ft_striteri.c		\
		ft_putnbr_fd.c		\
		ft_lstnew.c			\
		ft_lstadd_front.c	\
		ft_lstsize.c		\
		ft_lstlast.c		\
		ft_lstadd_back.c	\
		ft_lstdelone.c		\
		ft_lstclear.c		\
		ft_lstiter.c		\
		ft_lstmap.c			\
		get_next_line.c		\
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

LIB_PTH = ./libft
FLAGS = -Wall -Wextra -Werror
SRC = main.c init_pipex.c init_cmds.c init_cmds_utils.c errors.c pipex.c

all: $(NAME)
	./pipex ./files/teste "grep ola" "grep gosto" "wc -l" ./files/res 

$(NAME):
	@${GCC} -g3 -I ./headers $(addprefix ./src/, $(SRC)) $(addprefix ./libft/src/, $(LIBFT)) -o $(NAME)
	



clean: 
	rm ./a.out

fclean:
	rm $(NAME)

re: fclean all

.PHONY:clean all