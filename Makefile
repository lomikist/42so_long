# Colors
RESET			= "\033[0m"
BLACK    		= "\033[30m"    # Black
RED      		= "\033[31m"    # Red
GREEN    		= "\033[32m"    # Green
YELLOW   		= "\033[33m"    # Yellow
BLUE     		= "\033[34m"    # Blue
MAGENTA  		= "\033[35m"    # Magenta
CYAN     		= "\033[36m"    # Cyan
WHITE    		= "\033[37m"    # White

# Compiler
NAME			= so_long
CC				= cc
CFLAGS			= -Wall -Wextra -Werror -g
OS				= $(shell uname)
MAKE			= make -sC
MKDIR			= mkdir -p
RM				= rm -rf

# Includes
INCLUDES_DIR 	= includes
INCLUDES_FLAG 	= -I$(INCLUDES_DIR)

INCLUDES		= $(wildcard $(INCLUDES_DIR)/*.h)

# Sources
SRCS_DIR		= src/
SRC_FILES		= main.c \
				  checker.c \
				  control.c \
				  utils.c \
				  draw.c \
				  events.c \
			 	  get_next_line_utils.c \
				  get_next_line.c \
#PRINTF
PRINTF_DIR	= ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a
LINKER	= -lftprintf -L $(PRINTF_DIR)

#LIBFT
LIBFT_DIR	= libft
LIBFT 		= $(LIBFT_DIR)/libft.a
LINKER 		+= -lft -L $(LIBFT_DIR)

# Objects
OBJS_DIR		= objs/
OBJ_FILES		= $(SRC_FILES:.c=.o)
OBJS			= $(addprefix $(OBJS_DIR), $(OBJ_FILES))

# Platform-dependent compilation
ifeq ($(OS), Linux)
	MLX_DIR			= mlx_linux
	MLX				= $(MLX_DIR)/libmlx.a
	LINKER			+= -lmlx -lm -lz -lXext -lX11 -L $(MLX_DIR)
	INCLUDES_FLAG	+= -I$(MLX_DIR)
else
	MLX_DIR			= mlx_macos
	MLX				= $(MLX_DIR)/libmlx.a
	LINKER			+= -lmlx -lm -framework OpenGl -framework Appkit -L $(MLX_DIR)
	INCLUDES_FLAG	+= -I$(MLX_DIR)
endif

all : $(MLX) $(PRINTF) $(LIBFT) $(OBJS_DIR) $(NAME)

$(MLX) :
	@echo $(CYAN) " - Making mlx..." $(RESET)
	@$(MAKE) $(MLX_DIR)
	@echo $(YELLOW) " - Made mlx!" $(RESET)
	
$(PRINTF) :
	@echo $(CYAN) " - Making printf..." $(RESET)
	@$(MAKE) $(PRINTF_DIR)
	@echo $(YELLOW) " - Made printf!" $(RESET)

$(LIBFT) :
	@echo $(CYAN) " - Making libft..." $(RESET)
	@$(MAKE) $(LIBFT_DIR)
	@echo $(YELLOW) " - Made libft!" $(RESET)

$(OBJS_DIR) :
	@$(MKDIR) $(OBJS_DIR)

$(NAME) : $(OBJS)
	@echo $(GREEN) " - Compiling $(NAME)..." $(RESET)
	@$(CC) $(CFLAGS) $(OBJS) $(LINKER) -o $(NAME)
	@echo $(YELLOW) " - Compiling FINISHED" $(RESET)

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c $(INCLUDES)
	@$(CC) $(CFLAGS) $(INCLUDES_FLAG) -c $< -o $@

clean :
	@$(RM) $(OBJS_DIR)
	@echo $(RED) " - Cleaned!" $(RESET)

fclean : clean
	@$(RM) $(NAME)
	@$(MAKE) $(MLX_DIR) clean
	@$(MAKE) $(PRINTF_DIR) fclean
	@$(MAKE) $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re