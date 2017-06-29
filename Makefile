.PHONY: libft.a

NAME = filler
FLAGS = -Wextra -Wall -Werror
LIBOBJ = ./libft/*.o
OBJECTS =					\
		main.o				\
		read_clear.o		\
		compute_func.o		\
		small_middle_map.o	\
		big_map.o			\

all : $(NAME)

$(NAME) : libft.a $(OBJECTS)
	gcc $(FLAGS) $(OBJECTS) -o $(NAME) -I . -I ./libft ./libft/libft.a

libft.a:
	make -C ./libft

%.o : %.c
	gcc $(FLAGS) -o $@ -c $< -I . -I ./libft

clean :
	make clean -C ./libft
	rm -f $(OBJECTS)
	rm -f *.c~
fclean : clean
	rm -f $(NAME)
	rm -f ./libft/libft.a
re : fclean all
