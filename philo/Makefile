NAME = philo
CC = gcc
CFLAGS = -Wall -Wextra -Werror -pthread

SRCS_DIR = src/
SRCS = main.c utils.c time.c filosofo.c error.c ft_mutex.c
SRCS_PATH = $(addprefix $(SRCS_DIR), $(SRCS))

OBJS_DIR = obj/
OBJS = $(SRCS:%.c=%.o)
OBJS_PATH = $(addprefix $(OBJS_DIR), $(OBJS))

# Colors
GREEN		= \033[0;32m
RED			= \033[0;31m
RESET		= \033[0m


all: $(NAME)

$(NAME): $(OBJS_PATH)
	@$(CC) $(CFLAGS) $^ -o $(NAME)
	@echo "$(GREEN)✅ $(NAME) compiled successfully!$(RESET)"

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)🔧 Compiling: $<$(RESET)"

clean:
	@rm -rf $(OBJS_DIR)
	@echo "$(RED)🧹 Object files removed!$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)🧹 $(NAME) removed!$(RESET)"

re: fclean all

.PHONY: all clean fclean re