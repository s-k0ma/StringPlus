PROJECT_NAME	=s21_string
ODIR 			= ./obj
INC_PATH		= ./
LIB_SRC_DIR		= ./Functions
BUILD_LIB		= ./
TEST_FOLD		=./tests
UNAME_S 		:= $(shell uname -s)
TEST_NAME		= ${PROJECT_NAME}_test
TEST_SRC		= $(TEST_NAME).c
TEST_SUITE		= $(wildcard $(TEST_FOLD)/*.check)
Flags 			= -Wall -Wextra -Werror -pedantic -std=c11
gcc 			= gcc $(Flags)

LIB_SOURCES		= $(wildcard $(LIB_SRC_DIR)/*.c)
REPORT_FILES	= $(wildcard *.gcno) $(wildcard *.gcda)
INC				:= $(wildcard *.h)
OBJ 			= $(patsubst %.c,$(ODIR)/%.o, $(LIB_SOURCES))


ifeq ($(UNAME_S),Linux)
	TEST_CHECK_F= -lcheck -lsubunit
	OPEN_CMD = xdg-open
	ADD_LIB = -lm -lrt -lpthread 
	COND_COMP_FL = -DS21_LINUX

endif

ifeq ($(UNAME_S),Darwin)
	TEST_CHECK_F= $(shell pkg-config --cflags --libs check)
	OPEN_CMD = open
	ADD_LIB = 
	COND_COMP_FL = -DS21_MAC
endif

$(ODIR)/%.o: %.c $(INC)
	$(gcc) $(ADD_LIB) $(COND_COMP_FL) -I${INC_PATH} $<  -c -o $@

all: clear $(PROJECT_NAME).a

clear:
	clear

clean:
	rm -rf test *.out
	rm -rf $(ODIR)/*.o $(ODIR)/*.gc*
	rm -rf $(ODIR)/*/*.o $(ODIR)/*/*.gc*
	rm -rf ./gcov/*.o ./gcov/*.gc*
	rm -rf ./*.gc*
	rm -rf $(BUILD_LIB)/$(PROJECT_NAME).a
	rm -rf report*
	rm -rf $(TEST_SRC)
	rm -rf $(TEST_NAME)

obj: $(OBJ)

clang:
	clang-format --style=Google -n ./*.h ${LIB_SRC_DIR}/*.c

clang-replace:
	clang-format --style=Google -i  *.h ${LIB_SRC_DIR}/*.c
	clang-format --style=Google -i tests/*.c
$(PROJECT_NAME).a: obj
	ar rcs $@ $(ODIR)/$(LIB_SRC_DIR)/*.o
#$(PROJECT_NAME).a: $(BUILD_LIB)/$(PROJECT_NAME).a

set_debug_gcc:
	$(eval gcc += -g)
	@echo s21_string:Debug build

set_report_gcc:
	$(eval gcc += -fprofile-arcs -ftest-coverage -fPIC)
	@echo s21_string:Check build

#$(TEST_SRC) : $(TEST_SUITE) 
#	checkmk $(TEST_SUITE) > $(TEST_SRC)

test: $(BUILD_LIB)/$(PROJECT_NAME).a #$(TEST_SRC) 
	$(gcc) tests/*.c $^ -o $(TEST_NAME) $(TEST_CHECK_F) $(ADD_LIB)
	./$(TEST_NAME)

gcov_report: clean set_report_gcc test
	gcov ${LIB_SRC_DIR}/*.c -o $(ODIR)/*
	mv *.gcov ./gcov
	mv ./*.gc* $(ODIR)/*/*.gc* ./gcov
	lcov -t ./gcov -o report.info -c -d ./gcov
	genhtml -o report report.info
	$(OPEN_CMD) ./report/index.html

vlgrnd: clean valgring.c $(BUILD_LIB)/$(PROJECT_NAME).a
	gcc valgring.c $(BUILD_LIB)/$(PROJECT_NAME).a $(COND_COMP_FL) -I. -g -O0 -o vlgrnd -lm
	

sscanf: s21_string.a
	$(gcc) Functions/file/main.c s21_string.a -o sscanf

.PHONY: clean obj clear $(PROJECT_NAME) $(BUILD_LIB)/$(PROJECT_NAME).a test clang-replace all $(PROJECT_NAME).a set_debug_gcc set_report_gcc gcov_report

