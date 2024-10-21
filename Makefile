# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: halgordzibari <halgordzibari@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/05 15:16:43 by kmatjuhi          #+#    #+#              #
#    Updated: 2024/10/18 19:27:02 by halgordziba      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# /Users/$(USER)/.brew/opt/glfw/lib/
# /usr/local/Cellar/glfw/3.4/lib

################################################################################
# COMPILATION
################################################################################
CC				=	cc
# CC_FLAGS		=	-Wall -Wextra -Werror
DB_FLAGS		=	-g
INCLUDE_FLAGS	=	-I $(INCLUDES) -I ./libft -I ./MLX42/include/MLX42 -I ./usr/include/GLFW
MLX42_FLAGS		=	-Iinclude -lglfw -L"/usr/local/opt/glfw/lib"

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
					parse.c \
					save_file_content.c \
					save_info.c \
					safe_func.c \
					safe_mlx.c \
					free_func.c \
					arr_pop.c \
					validate_map.c \
					validate_elems.c \
					flood_fill.c \
					ft_arrdup.c \
					ray_utils.c \
					ray.c

OBJECTS			=	$(addprefix $(OBJ_DIR)/, $(SRCS:%.c=%.o))

################################################################################
# RULES
################################################################################
vpath %.c $(SRC_DIR) $(SRC_DIR)/parse $(SRC_DIR)/safe_func $(SRC_DIR)/ray_casting

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT) $(MLX42)
	@echo "--------------------------------------------"
	@$(CC) $(OBJECTS) $(CC_FLAGS) $(INCLUDE_FLAGS) $(DB_FLAGS) $(LIBFT) $(MLX42) -o $(NAME) -lglfw -lm
	@echo "[$(NAME)] $(B)Built target $(NAME)$(RC)"
	@echo "--------------------------------------------"

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CC_FLAGS) $(DB_FLAGS) $(INCLUDE_FLAGS) -c $< -o $@
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