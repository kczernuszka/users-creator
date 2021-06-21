CXXFLAGS := -std=c++17 -Iinclude/ -Isrc/ -Ilibs/ -g
LDLIBS := -lboost_program_options -lOpenXLSX
TESTS_LDLIBS := -lgtest -lgtest_main -pthread
LDFLAGS := -Llibs/

BIN_DIR ?= ./bin
BUILD_DIR ?= ./build
SRC_DIRS ?= ./src
TESTS_DIR ?= ./tests
UNITTESTS_DIR ?= ./src/*/unittests

SRCS := $(shell find $(SRC_DIRS) -maxdepth 2 -name "*.cpp")
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)

TESTS_SRCS := $(shell find $(UNITTESTS_DIR) -name "*.cpp")
TESTS_OBJS := $(TESTS_SRCS:%=$(BUILD_DIR)/%.o)

all: $(BIN_DIR)/users_creator $(BIN_DIR)/tests

$(BIN_DIR)/users_creator: $(BUILD_DIR)/main.o $(OBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $(BUILD_DIR)/main.o $(OBJS) $(LDLIBS)

$(BIN_DIR)/tests: $(BUILD_DIR)/unittests.o $(OBJS) $(TESTS_OBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $(BUILD_DIR)/unittests.o $(OBJS) $(TESTS_OBJS) $(TESTS_LDLIBS) $(LDLIBS)

$(BUILD_DIR)/main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o $(BUILD_DIR)/main.o $(LDLIBS)

$(BUILD_DIR)/unittests.o: $(TESTS_DIR)/unittests.cpp
	$(CXX) $(CXXFLAGS) -c $(TESTS_DIR)/unittests.cpp -o $(BUILD_DIR)/unittests.o $(TESTS_LDLIBS)

$(BUILD_DIR)/%.cpp.o: %.cpp
	$(MKDIR_P) $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) -r $(BUILD_DIR)

MKDIR_P ?= mkdir -p
