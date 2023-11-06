NAME = so_long

NAME_BONUS = so_long_bonus

SOLONG = so_long.a

SOLONGBONUS = so_long_bonus.a

FILES = src/check_map.c\
src/funciones.c\
src/inicializar_estructura.c\
src/moves.c\
src/open_game.c\
src/read_map.c\
src/so_long.c

FILES_BONUS = srcb/check_map_bonus.c\
srcb/enemy_bonus.c\
srcb/funciones_bonus.c\
srcb/inicializar_estructura_bonus.c\
srcb/moves_bonus.c\
srcb/open_game_bonus.c\
srcb/read_map_bonus.c\
srcb/so_long_bonus.c

OBJECTS = $(FILES:.c=.o)

OBJECTS_BONUS = $(FILES_BONUS:.c=.o)

FLAGS = -Wall -Werror -Wextra

LIBFT = ./Libft/libft.a

MLX42 = ./MLX42/libmlx42.a

LIB_SYS = -Iinclude -lglfw -L "/Users/etornay-/.brew/opt/glfw/lib/"

$(NAME):			$(OBJECTS) $(LIBFT) $(MLX42)
						ar rcs $(SOLONG) $(OBJECTS)
						gcc $(FLAGS) $(SOLONG) $(MLX42) $(LIBFT) $(LIB_SYS) -o $(NAME)

$(OBJECTS):	src/%.o : src/%.c
						gcc $(FLAGS) -c $< -o $@

$(LIBFT):
					make -s -C ./Libft

$(MLX42):
					make -s -C ./MLX42

all:				$(NAME)

bonus:				$(NAME_BONUS)

$(NAME_BONUS):		$(OBJECTS_BONUS) $(LIBFT) $(MLX42)
						ar rcs $(SOLONGBONUS) $(OBJECTS_BONUS)
						gcc $(FLAGS) $(SOLONGBONUS) $(MLX42) $(LIBFT) $(LIB_SYS) -o $(NAME_BONUS)

$(OBJECTS_BONUS):	srcb/%.o : srcb/%.c
						gcc $(FLAGS) -c $< -o $@

clean:
					@ rm -f $(OBJECTS) $(OBJECTS_BONUS)
					@ make clean -s -C ./MLX42
					@ make clean -s -C ./Libft

fclean:
					@ rm -f $(NAME_BONUS) $(NAME) $(OBJECTS) $(OBJECTS_BONUS) $(SOLONG) $(SOLONGBONUS) $(LIBFT) $(MLX42)
					@ make fclean -s -C ./MLX42
					@ make fclean -s -C ./Libft

re:					fclean all

.PHONY: all re clean fclean bonus