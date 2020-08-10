CXXFLAGS := -std=c++17 -Iinclude/ -Isrc/ -Ilibs/ -g
LDLIBS := -lboost_program_options -lOpenXLSX
TESTS_LDLIBS := -lgtest -lgtest_main -pthread
LDFLAGS := -Llibs/

BIN_DIR ?= ./bin
BUILD_DIR ?= ./build
SRC_DIRS ?= ./src
TESTS_DIR ?= ./tests
UNITTESTS_DIR ?= ./$(SRC_DIRS)/*/unittests

CONFIG_PARSER_DIR = src/config_parser
USERS_READER_DIR  = src/users_reader

SRCS := $(shell find $(SRC_DIRS) -maxdepth 2 -name "*.cpp")
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
BASE_OBJS := $(foreach file,$(OBJS), $(BUILD_DIR)/$(shell basename $(file)))

TESTS_SRCS := $(shell find $(UNITTESTS_DIR) -name "*.cpp")
TESTS_OBJS := $(TESTS_SRCS:%=$(BUILD_DIR)/%.o)
TEST_BASE_OBJS := $(foreach file,$(TESTS_OBJS), $(BUILD_DIR)/$(shell basename $(file)))

all: $(BIN_DIR)/users_creator $(BIN_DIR)/tests

$(BIN_DIR)/users_creator: $(BUILD_DIR)/main.o $(OBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $(BUILD_DIR)/main.o $(BASE_OBJS) $(LDLIBS)

$(BIN_DIR)/tests: $(BUILD_DIR)/unittests.o $(OBJS) $(TESTS_OBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $(BUILD_DIR)/unittests.o $(BASE_OBJS) $(TEST_BASE_OBJS) $(TESTS_LDLIBS) $(LDLIBS)

$(BUILD_DIR)/main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o $(BUILD_DIR)/main.o $(LDLIBS)

$(BUILD_DIR)/unittests.o: $(TESTS_DIR)/unittests.cpp
	$(CXX) $(CXXFLAGS) -c $(TESTS_DIR)/unittests.cpp -o $(BUILD_DIR)/unittests.o $(TESTS_LDLIBS)

$(OBJS) : $(BUILD_DIR)/%.cpp.o : %.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $(BUILD_DIR)/$(shell basename $@)

$(TESTS_OBJS) : $(BUILD_DIR)/%.cpp.o : %.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $(BUILD_DIR)/$(shell basename $@)

clean:
	$(RM) -r $(BUILD_DIR)
