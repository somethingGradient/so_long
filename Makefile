NAME		=	so_long

FLAGS		=	-Wall -Wextra -Werror

MAIN		=	game_start.c \
				handlers.c \
				keys_hook.c \

SRC			=	$(SRC_MAIN) $(SRC_MAP) $(SRC_UTLS)

SRC_MAIN	=	$(addprefix gameplay/, $(MAIN))


MAP			=	check_map.c map_options.c \
				open_sprites.c open_player_sprites.c \
				draw_static_items.c animations.c \

SRC_MAP		=	$(addprefix map_rendering/, $(MAP))


UTLS		=	ft_itoa.c ft_strlen.c \
				utils1.c utils_mlx.c \

SRC_UTLS	=	$(addprefix utils/, $(UTLS))


OBJ			=	*.o

INC			=	-I includes/so_long.h

LIB			=	-lmlx -framework OpenGL -framework AppKit


all: $(NAME)

$(NAME): $(OBJ)
		gcc $(FLAGS) $(OBJ) $(INC) $(LIB) -o $(NAME)


$(OBJ): $(SRC)
		gcc $(FLAGS) -c $(SRC)

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -rf $(NAME)

re: fclean all