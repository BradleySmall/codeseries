DEPS=combo.h cut.h Makefile tests.h 
SRCS=combo.cpp cut.cpp main.cpp tests.cpp
BIN=main.bin
OBJS = $(SRCS:.cpp=.o)

TEST_SRCS=unit_test.cpp combo.cpp cut.cpp tests.cpp
TEST_BIN=unit_test.bin

TEST_OBJS = $(TEST_SRCS:.cpp=.o)

CXXFLAGS = -g -Wall
TESTCXXFLAGS = -I${HOME}/include

all : $(BIN) $(TEST_BIN)

%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS) $(TESTCXXFLAGS)

$(BIN) : $(OBJS)
	$(CXX) -o $@ $^ $(CXXFLAGS) 

$(TEST_BIN) : $(TEST_OBJS) 
	$(CXX) -o $@ $^ $(TESTCXXFLAGS) 
	./$(TEST_BIN)

clean :
	rm -rf $(OBJS) $(BIN) $(TEST_OBJS) $(TEST_BIN)

