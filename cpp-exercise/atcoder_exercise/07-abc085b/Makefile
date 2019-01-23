CPP = clang++
CPPFLAGS = -Wall -O2 -std=c++14

TARGET = main
SRCS=$(wildcard *.cpp)
OBJS=$(SRCS:.cpp=.o)

$(TARGET): $(OBJS)
	$(CPP) $(CPPFLAGS) -o $@ $(OBJS)

.PHONY: fmt
fmt:
	clang-format -i *.cpp

.PHONY: test
test:
	./test.sh

.PHONY: clean
clean:
	$(RM) $(TARGET) *.o
