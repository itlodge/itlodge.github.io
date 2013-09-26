CXX = g++
FLAGS = -Wall -o2 -g
LIBS = -lboost_unit_test_framework

SRC = sort.cpp sort-test.cpp
OBJS = $(SRC:.cpp=.o)
TARGET = sort-test

%.o: %.cpp
	$(CXX) $(FLAGS) -c $< -o $@

all: clean $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(LIBS) $(FLAGS) $^ -o $@

.PRONY: clean
clean:
	rm -f $(OBJS) $(TARGET)
