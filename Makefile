NAME	=	so_long

MLX		=	mlx/libmlx.dylib

SRCS	=	srcs/main.c					\
			srcs/create_map.c			\
			srcs/utils.c				\
			gnl/get_next_line.c			\
			gnl/get_next_line_utils.c	\


HEADER	=	include/so_long.h			\
			include/get_next_line.h

OBJ		=	$(patsubst %.c, %.o, $(SRCS))

CFLAGS	=	-I./include -Wall -Wextra -Werror
CC		=	gcc
RM		=	rm -f

all		:	$(MLX) $(NAME)

$(OBJ)	:	$(HEADER)

$(MLX)	:	
			$(MAKE) -C mlx/
			cp $(MLX) ./

$(NAME)	:	$(OBJ)
			$(CC) $(MLX) -framework OpenGL -framework AppKit -o $(NAME) $(OBJ)

clean	:
			$(RM) $(OBJ)

fclean	:	clean
			$(RM) $(NAME)
			$(RM) libmlx.dylib

re		:	fclean all

.PHONY	:	all clean fclean re