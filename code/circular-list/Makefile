CXX = g++
FLAGS = -Wall -o2 -g
LIBS = -lboost_unit_test_framework

SRC = cilist.cpp cilist_test.cpp
OBJS = $(SRC:.cpp=.o)
TARGET = cilist_test

%.o: %.cpp
	$(CXX) $(LIBS) $(FLAGS) -c $< -o $@

all: clean $(TARGET)
$(TARGET): $(OBJS)
	$(CXX) $(LIBS) $(FLAGS) $^ -o $@

.PRONY:clean
clean:
	rm -f $(OBJS) $(TARGET)
