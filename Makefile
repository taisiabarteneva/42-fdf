NAME 		= fdf
FLAGS 		= -Wall -Werror -Wextra
MLX_FLAGS 	= -lmlx -framework OpenGL -framework AppKit
DIR_SRC 	= src
DIR_OBJ 	= obj

DIR_SRC_B = src_bonus
DIR_OBJ_B = obj_bonus
INC			=  -I ./libft -I ./mlx
SRC 	= 	main.c	check.c	init.c 	parse.c\
			free.c 	hooks.c draw.c	utils.c\
			move.c
B_SRC 	= 	main_bonus.c 	check_bonus.c 	init_bonus.c\
			draw_bonus.c	parse_bonus.c 	free_bonus.c\
			hooks_bonus.c 	utils_bonus.c 	move_bonus.c

LIB 		= libft/libft.a
DIR_LIB 	= libft
MLX_LIB 	= libmlx.dylib 
DIR_MLX		= mlx

LIBFT_H = libft/libft.h
FDF_H	= fdf.h
GNL_H   = libft/get_next_line.h
MLX_H 	= mlx/mlx.h

SRC := $(SRC:%.c=$(DIR_SRC)/%.c)
OBJ = $(SRC:$(DIR_SRC)/%.c=$(DIR_OBJ)/%.o)

B_SRC := $(B_SRC:%.c=$(DIR_SRC_B)/%.c)
B_OBJ = $(B_SRC:$(DIR_SRC_B)/%.c=$(DIR_OBJ_B)/%.o)

COLOR 		= \033[48;5;57m
NO_COLOR 	=	\033[0m 

all : $(NAME)

lib :
	$(MAKE) -sC $(DIR_LIB)

# $(NAME) :: $(LIBFT_H)
# 	@$(MAKE) -sC $(DIR_LIB)
# 	@echo "You compiled libft library."

$(NAME) ::
	$(MAKE) -sC $(DIR_MLX)
	@mv $(DIR_MLX)/$(MLX_LIB) .
	@echo "You compiled mlx library."

# $(NAME) :: lib $(OBJ) $(MLX_LIB)
# 	@gcc $(OBJ) $(LIB) $(MLX_LIB) $(MLX_FLAGS) -o $(NAME)
# 	@echo "$(COLOR)You compiled the mandatory part of project.$(NO_COLOR)"

$(NAME) :: $(OBJ)
	gcc $(OBJ) $(LIB) -L/usr/bin $(MLX_FLAGS) -o $(NAME)

$(DIR_OBJ)/%.o : $(DIR_SRC)/%.c $(FDF_H)
	@mkdir -p $(DIR_OBJ)
	@gcc $(FLAGS) -I . $(INC) -c $< -o $@
	@echo "[$<] ---> [$@]"

bonus : $(B_OBJ)
	@$(MAKE) -sC $(DIR_LIB)
	@$(MAKE) -sC $(DIR_MLX)
	@mv $(DIR_MLX)/$(MLX_LIB) .
	@gcc $(B_OBJ) $(LIB) $(MLX_LIB) $(MLX_FLAGS) $(NAME)
	@echo "$(COLOR)You compiled the bonus part of the project.$(NO_COLOR)"

$(DIR_OBJ_B)/%.o : $(DIR_SRC_B)/%.c $(FDF_H)
	@mkdir -p $(DIR_OBJ_B)
	@gcc $(FLAGS) -I . -c $< -o $@
	@echo "[$<] ---> [$@]"

clean :
	@rm -rf $(DIR_OBJ)
	@rm -rf $(DIR_OBJ_B)
	@$(MAKE) clean -C $(DIR_LIB)
	@$(MAKE) clean -C $(DIR_MLX)

fclean : clean
	@rm -f $(NAME)
	@$(MAKE) fclean -C $(DIR_LIB)
	@$(MAKE) clean -C $(DIR_MLX)
	@rm -f $(MLX_LIB)

re : fclean all

.PHONY :
	all clean fclean re bonus $(LIB)
