OS = $(shell uname)
CC = gcc
GENFLAGS = -std=c11 -Wall -Wextra -Werror 
COVLAGS =-fprofile-arcs -ftest-coverage #-g
CHLIB  = -lcheck -lm #-lsubunit
ifeq ($(OS), Linux)
	CHLIB += -lsubunit
endif

DFLAG = -D_POSIX_C_SOURCE=200809L

VALG = valgrind --tool=memcheck  --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=RESULT_VALGRIND.txt ./
#VALG = valgrind --tool=memcheck  --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=RESULT_VALGRIND.txt ./
CPPCH = cppcheck --enable=all --suppress=missingIncludeSystem --suppress=invalidFunctionArg --force --checkers-report=RESULT_CPPCHECK.txt

# format src
SRC_CL=../materials/linters/.clang-format

BUILD_DIR=../build
OBJ_DIR=$(BUILD_DIR)/objects
COV_DIR=$(BUILD_DIR)/coverage

SRC_FILES = $(shell find */ ! -path 'test/*' -type f -name '*.c')
HEAD_FILES = $(shell find */ ! -path 'test/*' -type f -name '*.h')
OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC_FILES:.c=.o)))

# tests
INSIDE_TEST_SRC = test/s21_inside_tests.c
INSIDE_TEST = $(addprefix $(BUILD_DIR)/, $(notdir $(INSIDE_TEST_SRC:.c=)))
INSIDE_TEST_OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(INSIDE_TEST_SRC:.c=.o)))
OPEN_TEST_SRC = test/s21_open_tests.c
OPEN_TEST = $(addprefix $(BUILD_DIR)/, $(notdir $(OPEN_TEST_SRC:.c=)))
OPEN_TEST_OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(OPEN_TEST_SRC:.c=.o)))
TEST_SRC = test/s21_ultimate_tests.c
TEST = $(addprefix $(BUILD_DIR)/, $(notdir $(TEST_SRC:.c=)))
TEST_OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(TEST_SRC:.c=.o)))
TEST_COV_SRC = $(TEST_SRC) #$(OPEN_TEST_SRC) $(INSIDE_TEST_SRC )
TEST_COV = $(addprefix $(BUILD_DIR)/, $(notdir $(TEST_COV_SRC:.c=_cov)))
TEST_COV_OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(TEST_COV_SRC:.c=.o)))

THE_NAME = s21_decimal
THE_HAED = $(THE_NAME:=.h)
LIBRARY = $(THE_NAME:=.a)
COVLIBRARY = $(THE_NAME:=.cov.a)

#Target-specific Variable
$(INSIDE_TEST): GENFLAGS := $(GENFLAGS) $(DFLAG)
$(OPEN_TEST): GENFLAGS := $(GENFLAGS) $(DFLAG)
$(TEST): GENFLAGS := $(GENFLAGS) $(DFLAG)
$(LIBRARY): GENFLAGS := $(GENFLAGS) $(DFLAG)
$(TEST_COV): GENFLAGS := $(GENFLAGS) $(DFLAG) $(COVLAGS)
$(COVLIBRARY): GENFLAGS := $(GENFLAGS) $(DFLAG) $(COVLAGS)


all: $(LIBRARY)
# test stagies--------------------------------------------------------------------------------------------------------------------
$(LIBRARY): clear_o $(OBJ_DIR) $(OBJ_FILES)
	ar rcs $(LIBRARY) $(OBJ_FILES)
	rm -f  $(OBJ_DIR)/*.o

# build tests with usual lib
inside_test_exe: $(LIBRARY) $(INSIDE_TEST_OBJ)
	$(CC) $(GENFLAGS) $(INSIDE_TEST_OBJ) -o $(INSIDE_TEST) $(LIBRARY) $(CHLIB)
	rm -f  $(OBJ_DIR)/*.o

open_test_exe: $(LIBRARY) $(OPEN_TEST_OBJ)
	$(CC) $(GENFLAGS) $(OPEN_TEST_OBJ) -o $(OPEN_TEST) $(LIBRARY) $(CHLIB)

test_exe: $(LIBRARY) $(TEST_OBJ)
	$(CC) $(GENFLAGS) $(TEST_OBJ) -o $(TEST) $(LIBRARY) $(CHLIB)

#object usual
$(OBJ_DIR)/%.o: */%.c
	$(CC) $(GENFLAGS) -c $< -o $@

# run tests
inside_test: inside_test_exe clear_o 
	./$(INSIDE_TEST)

open_test: open_test_exe clear_o
	./$(OPEN_TEST)

test: test_exe clear_o
	./$(TEST)


#Coverage_stages-------------------------------------------------------------------------------------------------------------------
# build static lib for tests report
s21_decimal.cov.a: clear_o $(OBJ_DIR) $(OBJ_FILES)
	ar rcs $(COVLIBRARY) $(OBJ_FILES)
	rm -f  $(OBJ_DIR)/*.o

# build tests for report
$(TEST_COV): $(COVLIBRARY) $(TEST_COV_OBJ)
	$(CC) $(GENFLAGS)$(TEST_COV_OBJ) -o $(TEST_COV) $(COVLIBRARY) $(CHLIB)
	rm -f  $(OBJ_DIR)/*.o

#run test for cov
test_cov: $(TEST_COV)
	./$(TEST_COV)

# coverage
coverage: test_cov
	gcov -b --object-directory=$(OBJ_DIR) $(SRC_FILES) 

#report
gcov_report: coverage
	gcovr  --object-directory $(OBJ_DIR)  -r . --html --html-details --output=$(COV_DIR)/    
	rm -fr $(OBJ_DIR)/*.gc*
	rm -f *.gc*
#-o coverage_report.html   


#Checkers-------------------------------------------------------------------------------------------------------------------------
#code check 1
valgrind: test_exe
	$(VALG)$(TEST)

#code check 2
cpp_check: 
	$(CPPCH) *.h $(SRC_FILES) $(HEAD_FILES)

# format code style
clang_all:
	cp $(SRC_CL) .clang-format
	clang-format -i  **/*.c
	clang-format -i *.h **/*.h
	rm -f .clang-format

#Service stages------------------------------------------------------------------------------------------------------------------------------------

$(OBJ_DIR) $(COV_DIR):
	mkdir -p $@
	
clean: clear

clear: clear_o
	rm -f  *.a RESULT_VALGRIND.txt RESULT_CPPCHECK.txt $(INSIDE_TEST)  $(OPEN_TEST) $(TEST_COV) *.html *.css *.gc*
	rm -fr $(BUILD_DIR)
	
clear_o:
	rm -f  $(OBJ_DIR)/*.o

rebuild: clear all

rebuild_test: clear inside_test open_test

rebuild_inside_test: clear inside_test

rebuild_open_test: clear open_test

rebuild_cov_test: clear test_cov

rebuild_cov: clear gcov_report

.extra_list: all s21_decimal.a test gcov_report clean  
