CXX = g++
FLAGS = -Wall -o2 -g
LIBS = -lboost_unit_test_framework

SRC = bilist.cpp bilist_test.cpp
OBJS = $(SRC:.cpp=.o)
TARGET = bilist_test

%.o: %.cpp
	$(CXX) $(LIBS) $(FLAGS) -c $< -o $@

all: clean $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(LIBS) $(FLAGS) $^ -o $@

.PRONY: clean
clean:
	rm -f $(OBJS) $(TARGET)
