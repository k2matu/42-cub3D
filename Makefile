# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmatjuhi <kmatjuhi@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/05 15:16:43 by kmatjuhi          #+#    #+#              #
#    Updated: 2024/09/01 21:16:50 by kmatjuhi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# /Users/$(USER)/.brew/opt/glfw/lib/
# /usr/local/Cellar/glfw/3.4/lib

################################################################################
# COMPILATION
################################################################################
CC				=	cc
CC_FLAGS		=	-Wall -Wextra -Werror
DB_FLAGS		=	-g
INCLUDE_FLAGS	=	-I $(INCLUDES) -I ./libft -I ./MLX42/include/MLX42
MLX42_FLAGS		=	-Iinclude -lglfw -L"/Users/kale/.brew/opt/glfw/lib/"

################################################################################
# LIBRARIES
################################################################################
LIBFT			=	./libft/libft.a
MLX42			=	./MLX42/build/libmlx42.a

################################################################################
# GENERAL
################################################################################
NAME			=	cub
INCLUDES		=	./includes
OBJ_DIR			=	./obj
SRC_DIR			=	./src

SRCS			=	main.c \
					read_file.c \
					validate_map.c \
					safe_func.c

OBJECTS			=	$(addprefix $(OBJ_DIR)/, $(SRCS:%.c=%.o))

################################################################################
# RULES
################################################################################
vpath %.c $(SRC_DIR) $(SRC_DIR)/parsing $(SRC_DIR)/safe_func

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT) $(MLX42)
	@echo "--------------------------------------------"
	@$(CC) $(OBJECTS) $(CC_FLAGS) $(MLX42_FLAGS) $(LIBFT) -framework Cocoa -framework OpenGL -framework IOKit -o $(NAME)
	@echo "[$(NAME)] $(B)Built target $(NAME)$(RC)"
	@echo "--------------------------------------------"

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CC_FLAGS) $(INCLUDE_FLAGS) -c $< -o $@
	@echo "Compiled: $<"

$(LIBFT): 
	@make -C libft/

$(MLX42):
	cd MLX42 && cmake -B build
	cd MLX42 && cmake --build build -j4

clean:
	@rm -rf $(OBJ_DIR)
	@rm -rf cub.dSYM
	make clean -C libft
	make clean -C MLX42/build
	@echo "[$(NAME)] Object files cleaned."

fclean: clean
	rm -f $(NAME)
	make fclean -C libft
	make clean -C MLX42/build
	@echo "[$(NAME)] Everything deleted."

re: fclean all
	@echo "[$(NAME)] Everything rebuilt."

.PHONY: all clean fclean re