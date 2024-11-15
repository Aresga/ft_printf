CC = cc

CFLAGS = -Wall -Wextra -Werror

PRINTF_DIR = /home/agaga/Githubrepos/ft_printf
TESTS_DIR = /home/agaga/Githubrepos/ft_printf/tester

PRINTF = $(PRINTF_DIR)/libftprintf.a
#HEADER = $(PRINTF_DIR)/libft.h
#TESTER_HEADER = /home/agaga/Githubrepos/ft_printf/tester

# Test files .c
TEST_FILES = $(wildcard $(TESTS_DIR)/*.c)

# exe Names
TEST_EXECUTABLES = $(TEST_FILES:$(TESTS_DIR)/%.c=%)

# Rule for exe
$(TEST_EXECUTABLES): %: $(TESTS_DIR)/%.c $(PRINTF)
	@$(CC) $(CFLAGS) -I$(PRINTF_DIR) $< -L$(PRINTF_DIR) -lftprintf -o $@

# Debugging rule
DEBUG_CFLAGS = $(CFLAGS) -g
DEBUG_EXECUTABLES = $(TEST_FILES:$(TESTS_DIR)/%.c=%_debug)

$(DEBUG_EXECUTABLES): %_debug: $(TESTS_DIR)/%.c $(PRINTF)
	@$(CC) $(DEBUG_CFLAGS) -I$(PRINTF_DIR) $< -L$(PRINTF_DIR) -lftprintf -o $@


# Colors styling
RED = \033[31m
GREEN = \033[32m
RESET = \033[0m
BLUE = \033[34m
BOLD = \033[1m
CYAN = \033[36m
YELLOW = \033[33m
MAGENTA = \033[35m


debug: $(DEBUG_EXECUTABLES)
	@echo "Debug executables created"

test: $(TEST_EXECUTABLES)
		@for test_exec in $^; do \
			./$$test_exec; \
	done

clean:
	@rm -f $(TEST_EXECUTABLES) $(DEBUG_EXECUTABLES)
	@echo "Cleaned up all executables"

.PHONY : test clean debug
	
