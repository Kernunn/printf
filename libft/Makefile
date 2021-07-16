### colors ###
RESET = \033[0m
BOLD = \033[1m
RED = \033[31m
GREEN = \033[32m
GRAY = \033[2m
#########

NAME = libft.a

CC = gcc

SRC_DIR = src/
OBJ_DIR = obj/
INC_DIR = includes/

SRC_FILES = ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memccpy.c \
			ft_memmove.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strlen.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strnstr.c \
			ft_strncmp.c \
			ft_atoi.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c 

OBJ_FILES = $(SRC_FILES:.c=.o)
DEP_FILES = $(SRC_FILES:.c=.d)

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))
DEP = $(addprefix $(OBJ_DIR), $(DEP_FILES))

INCLUDES = $(addprefix -I, $(INC_DIR))
CFLAGS = -Wall -Wextra -Werror 

all: $(NAME)

-include $(DEP)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $^
	@ranlib $(NAME)
	@echo "$(GREEN)$(BOLD)$(NAME) created!$(RESET)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	@$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $@ -MMD

clean:
	@echo "$(GRAY)Deleting...$(RESET)"
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)$(BOLD)Object files deleted!$(RESET)$(RED)$(RESET)"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(RED)$(BOLD)$(NAME) deleted!$(RESET)"

re: fclean all

.PHONY: all, re, clean, fclean
