SRC_FOLDER = src
INC_FOLDER = inc
OBJ_FOLDER = obj
BIN_FOLDER = bin

SOURCES = $(wildcard $(SRC_FOLDER)/*.c)
HEADERS = $(wildcard $(INC_FOLDER)/*.h)
 
OBJECTS = $(SOURCES:$(SRC_FOLDER)/%.c=$(OBJ_FOLDER)/%.o)
PROGRAM = $(shell basename `pwd`)
 
CC := $(shell which gcc)
CFLAGS = -Wall -W -O -I inc
LIBS =
LDFLAGS = $(LIBS:%=-l%)
MKDIR = mkdir -p
 
$(PROGRAM) : $(OBJECTS)
	$(MKDIR) $(BIN_FOLDER)
	$(CC) $(LDFLAGS) -o $(BIN_FOLDER)/$@ $^
 
$(OBJ_FOLDER)/%.o : $(SRC_FOLDER)/%.c $(HEADERS)
	$(MKDIR) $(OBJ_FOLDER)
	$(CC) $(CFLAGS) -c -o $@ $<
 
.PHONY : clean
clean :
	rm -rf $(BIN_FOLDER) $(OBJ_FOLDER)

