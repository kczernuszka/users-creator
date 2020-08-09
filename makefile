CXXFLAGS := -std=c++17 -Iinclude/ -Isrc/ -Ilibs/ -g
LDLIBS := -lboost_program_options -lOpenXLSX
TESTS_LDLIBS := -lgtest -lgtest_main -pthread
LDFLAGS := -Llibs/

BIN_DIR ?= ./bin
BUILD_DIR ?= ./build
SRC_DIRS ?= ./src
TESTS_DIR ?= ./tests

CONFIG_PARSER_DIR = src/config_parser
USERS_READER_DIR  = src/users_reader

SRCS := $(shell find $(SRC_DIRS) -maxdepth 2 -name "*.cpp")
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)

TESTS_SRCS := $(shell find $(SRC_DIRS)/*/unittests -name "*.cpp")
TESTS_OBJS := $(TEST_SRCS:%=$(BUILD_DIR)/%.o)

all: $(BIN_DIR)/users_creator $(BIN_DIR)/tests

$(BIN_DIR)/tests: $(BUILD_DIR)/unittests.o $(TESTS_OBJS)
	$(CXX) -o $@ $^ $(TESTS_LDLIBS) $(LDLIBS)

$(BIN_DIR)/users_creator: $(BUILD_DIR)/main.o $(OBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $(foreach file,$^, $(BUILD_DIR)/$(shell basename $(file))) $(LDLIBS)

$(BUILD_DIR)/main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o $(BUILD_DIR)/main.o $(LDLIBS)

$(BUILD_DIR)/unittests.o: $(TESTS_DIR)/unittests.cpp
	$(CXX) $(CXXFLAGS) -c $(TESTS_DIR)/unittests.cpp -o $(BUILD_DIR)/unittests.o $(TESTS_LDLIBS)

$(OBJS) : $(BUILD_DIR)/%.cpp.o : %.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $(BUILD_DIR)/$(shell basename $@)

clean:
	$(RM) -r $(BUILD_DIR)
