#####################################################################################
#
#	SE420
#	Packet Switching Group Project
#
#####################################################################################

#####################################################################################
#	App Variables
#####################################################################################

EXECUTABLE=psp.exe
SRC_FOLDER=src
SOURCES=packetswitch.cpp ethernetswitch.cpp wirelessrouter.cpp subnet.cpp newMain.cpp 
OBJ_FOLDER=obj
OTHER_CAT_FILES=Makefile
EXECUTE=

#####################################################################################
#	Compiler Options
#####################################################################################

# Compiler
CC=g++

# Compiler Flags
CC_DEBUG_LEVEL=-g
CC_FLAGS=-Wall -std=c++11

# Linker Flags
LD_DEBUG_LEVEL=$(CC_DEBUG_LEVEL)
LD_FLAGS=$(CC_FLAGS)

# Linker Libraries
LD_LIBS=

# Source Path (*.cpp to SRC_FOLDER/*.cpp)
SRC_PATH=$(SOURCES:%.cpp=$(SRC_FOLDER)/%.cpp)

# Cat Path (*.cpp to (*.h *.cpp))
CAT_PATH=$(OTHER_CAT_FILES) ./$(SRC_FOLDER)/*

# Object Files (*.cpp to *.o)
OBJ_PATH=$(SOURCES:%.cpp=$(OBJ_FOLDER)/%.o)

#####################################################################################
#	RULES
#####################################################################################

all: build

build: genre_file_struct $(SRC_PATH) $(EXECUTABLE)

clean:
			rm -rf $(OBJ_FOLDER) $(EXECUTABLE);

rebuild: clean build

genre_file_struct:
			-mkdir $(OBJ_FOLDER);

cat:
			cat $(CAT_PATH);

script: cat clean build execute

execute:
			$(EXECUTE)

$(EXECUTABLE): $(OBJ_PATH)
	$(CC) $(LD_DEBUG_LEVEL) $(LD_FLAGS) $(LD_LIBS) -o $@ $(OBJ_PATH);

$(OBJ_FOLDER)/%.o : $(SRC_FOLDER)/%.cpp
	$(CC) $(CC_DEBUG_LEVEL) $(CC_FLAGS) -c $< -o $@;

