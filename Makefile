# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malluin <malluin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/22 14:56:26 by malluin           #+#    #+#              #
#    Updated: 2019/06/01 15:04:31 by malluin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC_NAME = main.c errors.c input.c line.c draw.c image.c projection.c color.c hook.c \
		   ui.c mouse.c rotate.c translate.c scale.c color2.c
SRC_PATH = src
OBJ_PATH = obj
INCLUDES = ./includes/
CC = gcc
CCFLAGS = -Wall -Wextra -Werror -O2 -O3
CPPFLAGS = -I ./libft/ -I $(INCLUDES)
LIBFLAGS = -L ./libft/ -lft
MLXFLAGS = -I ./minilibx_macos/ ./minilibx_macos/libmlx.a
FRMWORK = -framework OpenGL -framework AppKit


OBJ_NAME = $(SRC_NAME:.c=.o)
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@make -C minilibx_macos
	$(CC) $(CCFLAGS) $(CPPFLAGS) $(LIBFLAGS) $(MLXFLAGS) $(FRMWORK)  $^ -o $@

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CCFLAGS) $(CPPFLAGS) -ggdb -o $@ -c $<

clean:
	@make clean -C libft/
	@make clean -C minilibx_macos
	rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean:	clean
	@make fclean -C libft/
	@rm -f $(NAME)

re: fclean all

norme:
	norminette $(SRC)
	norminette $(INCLUDES)

.PHONY: make clean fclean re
