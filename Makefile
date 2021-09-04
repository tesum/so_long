NAME	=	so_long

MLX		=	mlx/libmlx.dylib
LIBFT	=	libft/libft.a

SRCS	=	srcs/main.c					\
			srcs/create_map.c			\
			srcs/print_map.c			\
			srcs/utils.c				\
			srcs/hook.c					\
			srcs/enemy.c				\


HEADER	=	include/so_long.h			\
			include/libft.h				\
			include/mlx.h				\

OBJ		=	$(patsubst %.c, %.o, $(SRCS))

CFLAGS	=	-I./include -Wall -Wextra -Werror
CC		=	gcc
RM		=	rm -f

all		:	$(LIBFT) $(MLX) $(NAME)

$(LIBFT):
			$(MAKE) -C libft/
			cp libft/libft.h ./include

$(MLX)	:
			$(MAKE) -C mlx/
			cp $(MLX) ./
			cp mlx/mlx.h ./include

$(NAME)	:	$(OBJ) $(HEADER)
			$(CC) $(MLX) $(LIBFT) -framework OpenGL -framework AppKit -o $(NAME) $(OBJ)

clean	:
			$(RM) $(OBJ)

fclean	:	clean
			$(RM) $(NAME)
			$(MAKE) fclean -C libft/
			$(MAKE) clean -C mlx/
			$(RM) libmlx.dylib libft.a ./include/libft.h ./include/mlx.h

re		:	fclean all

.PHONY	:	all clean fclean re