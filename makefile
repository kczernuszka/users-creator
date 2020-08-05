CXX = g++
CXXFLAGS = -std=c++17 -Iinclude/ -g
LDFLAGS = -L/usr/lib/x86_64-linux-gnu/
LDLIBS = -lboost_program_options
OBJ = build/file_parser.o build/cmd_parser.o build/option_value_parser.o build/config_parser.o build/users_reader.o build/xlsx_column_reader.o build/column_reader_factory.o

TESTS_OBJ = $(OBJ) build/unittests.o build/file_parser_test.o build/cmd_parser_test.o build/option_value_parser_test.o build/xlsx_reader_test.o
TESTS_LDFLAGS = -lgtest -lgtest_main -pthread
TEST_FLAGS = -Iinclude/ -g

CONFIG_PARSER = src/config_parser
USERS_READER = src/users_reader
CONFIG_PARSER_TESTS = src/config_parser/unittests
USERS_READER_TESTS = src/users_reader/unittests

all: bin/xlstousers bin/tests

bin/xlstousers: build/main.o $(OBJ)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^ $(LDLIBS) -lOpenXLSX-shared

bin/tests: $(TESTS_OBJ)
	$(CXX) $(TEST_FLAGS) -Isrc/ -o $@ $^ $(TESTS_LDFLAGS) $(LDLIBS) -lOpenXLSX-shared

build/config_parser.o: $(CONFIG_PARSER)/config_parser.cpp include/config_parser/config_parser.h
	$(CXX) $(CXXFLAGS) -Isrc/ $(LDFLAGS) $(CONFIG_PARSER)/config_parser.cpp -c -o build/config_parser.o

build/file_parser.o: $(CONFIG_PARSER)/file_parser.cpp $(CONFIG_PARSER)/file_parser.h
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(CONFIG_PARSER)/file_parser.cpp -c -o build/file_parser.o $(LDLIBS)

build/cmd_parser.o: $(CONFIG_PARSER)/cmd_parser.cpp $(CONFIG_PARSER)/cmd_parser.h
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(CONFIG_PARSER)/cmd_parser.cpp -c -o build/cmd_parser.o

build/option_value_parser.o: $(CONFIG_PARSER)/option_value_parser.cpp $(CONFIG_PARSER)/option_value_parser.h
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(CONFIG_PARSER)/option_value_parser.cpp -c -o build/option_value_parser.o

build/users_reader.o: $(USERS_READER)/users_reader.cpp include/users_reader/users_reader.h
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(USERS_READER)/users_reader.cpp -c -o build/users_reader.o -lOpenXLSX-shared

build/xlsx_column_reader.o: $(USERS_READER)/xlsx_column_reader.cpp $(USERS_READER)/xlsx_column_reader.h
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(USERS_READER)/xlsx_column_reader.cpp -c -o build/xlsx_column_reader.o -lOpenXLSX-shared

build/column_reader_factory.o: $(USERS_READER)/column_reader_factory.cpp $(USERS_READER)/column_reader_factory.h
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(USERS_READER)/column_reader_factory.cpp -c -o build/column_reader_factory.o -lOpenXLSX-shared

build/main.o: main.cpp
	$(CXX) $(CXXFLAGS) -Isrc/ $(LDFLAGS) main.cpp -c -o build/main.o

clean:
	rm build/*.o


#*****************************************************************************
#tests

build/file_parser_test.o: $(CONFIG_PARSER_TESTS)/file_parser_test.cpp
	$(CXX) $(TEST_FLAGS) -Isrc/ $(CONFIG_PARSER_TESTS)/file_parser_test.cpp -c -o build/file_parser_test.o $(TESTS_LDFLAGS) $(LDLIBS)

build/cmd_parser_test.o: $(CONFIG_PARSER_TESTS)/cmd_parser_test.cpp
	$(CXX) $(TEST_FLAGS) -Isrc/ $(CONFIG_PARSER_TESTS)/cmd_parser_test.cpp -c -o build/cmd_parser_test.o $(TESTS_LDFLAGS) $(LDLIBS)

build/option_value_parser_test.o: $(CONFIG_PARSER_TESTS)/option_value_parser_test.cpp
	$(CXX) $(TEST_FLAGS) $(CONFIG_PARSER_TESTS)/option_value_parser_test.cpp -c -o build/option_value_parser_test.o $(TESTS_LDFLAGS)

build/xlsx_reader_test.o: $(USERS_READER_TESTS)/xlsx_reader_test.cpp
	$(CXX) $(TEST_FLAGS) $(USERS_READER_TESTS)/xlsx_reader_test.cpp -c -o build/xlsx_reader_test.o -lOpenXLSX-shared

build/unittests.o: tests/unittests.cpp
	$(CXX) $(TEST_FLAGS) tests/unittests.cpp -c -o build/unittests.o $(TESTS_LDFLAGS)
