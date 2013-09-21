CXX = g++
FLAGS = -Wall -o2 -g
LIBS = -lboost_unit_test_framework

SRC = list.cpp list-test.cpp
OBJS = $(SRC:.cpp=.o)
TARGET = list-test

%.o: %.cpp
	$(CXX) $(LIBS) $(FLAGS) -c $< -o $@

$(TARGET): $(OBJS)
	$(CXX) $(LIBS) $(FLAGS) $^ -o $@

.PRONY:clean
clean:
	rm -f $(OBJS) $(TARGET)
