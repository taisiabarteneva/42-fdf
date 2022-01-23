NAME = fdf

SRC 	= 	main.c	check.c	init.c 	parse.c\
			free.c 	hooks.c draw.c	utils.c\
			move.c

BONUS	= 	main_bonus.c 	check_bonus.c 	init_bonus.c\
			draw_bonus.c	parse_bonus.c 	free_bonus.c\
			hooks_bonus.c 	utils_bonus.c 	move_bonus.c

D_SRC = src
D_OBJ = obj
D_OBJ_B = obj_bonus
D_SRC_B = src_bonus

COLOR 		=  \033[48;5;57m
NO_COLOR 	=	\033[0m 

SRC 	:= $(SRC:%.c=$(D_SRC)/%.c)
BONUS 	:= $(BONUS:%.c=src_bonus/%.c)

OBJ 		= $(SRC:$(D_RC)/%.c=$(D_OBJ)/%.o)
OBJ_BONUS 	= $(BONUS:src_bonus/%.c=obj_bonus/%.o)

INCLUDES = fdf.h

LIB = libft/libft.a
DIR_LIB = ./libft/

FLAGS 		= -Wall -Werror -Wextra -fsanitize=address

all : $(NAME)

$(NAME) : $(OBJ) subsystem
	@$(CC) $(LIB) $(OBJ) $(FLAGS) -Lmlx -lmlx -I. -framework OpenGL -framework AppKit -o $(NAME)
	@echo "$(COLOR)You compiled the mandatory part of project.$(NO_COLOR)"

$(DIR_OBJ)/%.o : $(DIR_SRC)/%.c subsystem
	@mkdir -p $(DIR_OBJ)
	$(CC) $(FLAGS) -Imlx -I. -c $< -o $@ - I $(DIR_LIB)

subsystem :
	@$(MAKE) -sC $(DIR_LIB)

bonus : $(OBJ_BONUS)
	@$(MAKE) -sC $(DIR_LIB)
	@$(CC) $(LIB) $(OBJ_BONUS) $(FLAGS) -Lmlx -lmlx -I. -framework OpenGL -framework AppKit -o $(NAME)
	@echo "$(COLOR)You compiled the bonus part of the project.$(NO_COLOR)"

$(D_OBJ_B)/%.o : $(D_SRC_B)/%.c
	@mkdir -p $(D_OBJ_B)
	$(CC) $(FLAGS) -Imlx -I. -c $< -o $@
	
clean :
	@rm -rf src/*.o
	@rm -rf $(D_OBJ)
	@rm -rf $(D_OBJ_B)
	@$(MAKE) clean -C $(DIR_LIB)

fclean : clean
	@rm -f $(NAME)
	@$(MAKE) fclean -C $(DIR_LIB)

re : fclean all

.PHONY :
	all clean fclean re bonus
