MAKEFLAGS =			--no-print-directory

### colors ###
RESET = \033[0m
BOLD = \033[1m
RED = \033[31m
GREEN = \033[32m
GRAY = \033[2m
#########

NAME = libprintf.a

CC = gcc

SRC_DIR = src/
OBJ_DIR = obj/
INC_DIR = includes/ libft/includes

SRC_FILES = ft_printf.c \
			ft_addzero.c \
			ft_print1.c \
			ft_print2.c \
			ft_itoa_unsigned.c \
			ft_ftoa.c \
			ft_write_double.c \
			ft_print3.c \
			ft_itoa_ll.c \
			ft_type_size.c \
			ft_return.c \
			ft_print4.c

OBJ_FILES = $(SRC_FILES:.c=.o)
DEP_FILES = $(SRC_FILES:.c=.d)

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))
DEP = $(addprefix $(OBJ_DIR), $(DEP_FILES))

INCLUDES = $(addprefix -I, $(INC_DIR))
CFLAGS = -Wall -Werror -Wextra

all: libs $(NAME)

-include $(DEP)

libs:
	@$(MAKE) -C ./libft/

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $^
	@ranlib $(NAME)
	@echo "$(GREEN)$(BOLD)$(NAME) created!$(RESET)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	@$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $@ -MMD

clean:
	@$(MAKE) -C libft/ clean
	@echo "$(GRAY)Deleting...$(RESET)"
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)$(BOLD)Object files deleted!$(RESET)$(RED)$(RESET)"

fclean: clean
	@$(MAKE) -C libft/ fclean
	@rm -f $(NAME)
	@echo "$(RED)$(BOLD)$(NAME) deleted!$(RESET)"

re: fclean all

.PHONY: all clean fclean re libft
