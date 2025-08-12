# Компилятор и флаги
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I/opt/homebrew/include #-std=c11
CHECK_FLAGS = -lcheck -lm -lpthread -L/opt/homebrew/lib $(SUBUNIT_FLAGS)
GCOV_FLAGS = --coverage
LCOV_FLAGS = -c -d . -o coverage.info
GENHTML_FLAGS = coverage.info -o coverage_report

# Директории
SRC_DIR = .
TEST_DIR = tests
OBJ_DIR = obj
REPORT_DIR = coverage_report

# Список исходных файлов (все s21_*.c, кроме sprintf и sscanf)
SOURCES = $(filter-out $(SRC_DIR)/s21_sprintf.c $(SRC_DIR)/s21_sscanf.c, $(wildcard $(SRC_DIR)/s21_*.c))
OBJECTS = $(SOURCES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Список тестовых файлов (все test_*.c, кроме test_all.c, который обрабатывается отдельно)
TEST_SOURCES = $(filter-out $(TEST_DIR)/test_all.c, $(wildcard $(TEST_DIR)/test_*.c))
TEST_OBJECTS = $(TEST_SOURCES:$(TEST_DIR)/%.c=$(OBJ_DIR)/%.o)
TEST_ALL_OBJ = $(OBJ_DIR)/test_all.o

# Определение флага для subunit в зависимости от операционной системы
ifeq ($(shell uname), Linux)
    SUBUNIT_FLAGS = -lsubunit
else
    SUBUNIT_FLAGS = 
endif

# Создание директорий
$(shell mkdir -p $(OBJ_DIR))
$(shell mkdir -p $(REPORT_DIR))

# Цель по умолчанию
all: s21_string.a test

# Создание статической библиотеки
s21_string.a: $(OBJECTS)
	ar rcs $@ $^

# Компиляция исходных файлов
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Компиляция тестовых файлов
$(OBJ_DIR)/%.o: $(TEST_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Сборка и запуск тестов
test: s21_string.a $(TEST_OBJECTS) $(TEST_ALL_OBJ)
	$(CC) $(CFLAGS) $(TEST_OBJECTS) $(TEST_ALL_OBJ) s21_string.a -o test $(CHECK_FLAGS)
	./test

# Создание отчета покрытия
gcov_report: s21_string.a $(TEST_OBJECTS) $(TEST_ALL_OBJ)
	$(CC) $(CFLAGS) $(GCOV_FLAGS) $(SOURCES) $(TEST_SOURCES) $(TEST_DIR)/test_all.c -o test $(CHECK_FLAGS)
	./test
	gcov $(SOURCES)
	lcov $(LCOV_FLAGS)
	genhtml $(GENHTML_FLAGS)
	rm -f *.gcno *.gcda *.gcov coverage.info
	open $(REPORT_DIR)/index.html

# Очистка
clean:
	rm -rf $(OBJ_DIR) *.a test $(REPORT_DIR)

# Фиктивные цели
.PHONY: all clean test gcov_report