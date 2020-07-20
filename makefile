CXX = g++
CXXFLAGS = -std=c++17 -Iinclude/ -g
LDFLAGS = -L/usr/lib/x86_64-linux-gnu/
LDLIBS = -lboost_program_options
OBJ = build/main.o build/file_parser.o build/cmd_parser.o build/option_value_parser.o build/config_parser.o

TESTS_OBJ = build/unittests.o build/file_parser_test.o build/file_parser.o build/option_value_parser.o build/cmd_parser_test.o build/cmd_parser.o build/option_value_parser_test.o
TESTS_LDFLAGS = -lgtest -lgtest_main -pthread
TEST_FLAGS = -Iinclude/ -g

CONFIG_PARSER = src/config_parser
CONFIG_PARSER_TESTS = src/config_parser/unittests

all: bin/xlstousers bin/tests

bin/xlstousers: $(OBJ)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^ $(LDLIBS)

bin/tests: $(TESTS_OBJ)
	$(CXX) $(TEST_FLAGS) -o $@ $^ $(TESTS_LDFLAGS) $(LDLIBS)

build/config_parser.o: $(CONFIG_PARSER)/config_parser.cpp $(CONFIG_PARSER)/config_parser.h
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(CONFIG_PARSER)/config_parser.cpp -c -o build/config_parser.o

build/file_parser.o: $(CONFIG_PARSER)/file_parser.cpp $(CONFIG_PARSER)/file_parser.h
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(CONFIG_PARSER)/file_parser.cpp -c -o build/file_parser.o $(LDLIBS)

build/cmd_parser.o: $(CONFIG_PARSER)/cmd_parser.cpp $(CONFIG_PARSER)/cmd_parser.h
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(CONFIG_PARSER)/cmd_parser.cpp -c -o build/cmd_parser.o

build/option_value_parser.o: $(CONFIG_PARSER)/option_value_parser.cpp $(CONFIG_PARSER)/option_value_parser.h
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(CONFIG_PARSER)/option_value_parser.cpp -c -o build/option_value_parser.o

build/main.o: main.cpp
	$(CXX) $(CXXFLAGS) $(LDFLAGS) main.cpp -c -o build/main.o


#*****************************************************************************
#tests

build/file_parser_test.o: $(CONFIG_PARSER_TESTS)/file_parser_test.cpp
	$(CXX) $(TEST_FLAGS) $(CONFIG_PARSER_TESTS)/file_parser_test.cpp -c -o build/file_parser_test.o $(TESTS_LDFLAGS) $(LDLIBS)

build/cmd_parser_test.o: $(CONFIG_PARSER_TESTS)/cmd_parser_test.cpp
	$(CXX) $(TEST_FLAGS) $(CONFIG_PARSER_TESTS)/cmd_parser_test.cpp -c -o build/cmd_parser_test.o $(TESTS_LDFLAGS) $(LDLIBS)

build/option_value_parser_test.o: $(CONFIG_PARSER_TESTS)/option_value_parser_test.cpp
	$(CXX) $(TEST_FLAGS) $(CONFIG_PARSER_TESTS)/option_value_parser_test.cpp -c -o build/option_value_parser_test.o $(TESTS_LDFLAGS)

build/unittests.o: tests/unittests.cpp
	$(CXX) $(TEST_FLAGS) tests/unittests.cpp -c -o build/unittests.o $(TESTS_LDFLAGS)
