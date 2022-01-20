NAME = fdf

FLAGS = -Wall -Werror -Wextra 
SRC = 		main.c	check.c	init.c 	parse.c\
			free.c 	hooks.c draw.c	utils.c\
			move.c
INCLUDES = fdf.h
LIB = libft/libft.a
DIR_LIB = libft
COLOR = \033[48;5;57m
NO_COLOR =	\033[0m 

OBJ = $(patsubst %.c,%.o, $(SRC))

all : $(NAME)

$(NAME) ::
	@$(MAKE) -sC $(DIR_LIB)

$(NAME) :: $(OBJ) $(LIB)
	@gcc $(OBJ) $(LIB) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "$(COLOR)You compiled the mandatory part of project.$(NO_COLOR)"

%.o : %.c $(INCLUDES)
	@gcc $(FLAGS) -I . -c $< -o $@
	@echo "[$<] ---> [$@]"

clean :
	@rm -f $(OBJ)
	@$(MAKE) clean -C $(DIR_LIB)

fclean : clean
	@rm -f $(NAME)
	@$(MAKE) fclean -C $(DIR_LIB)

re : fclean all

.PHONY :
	all clean fclean re bonus lib
