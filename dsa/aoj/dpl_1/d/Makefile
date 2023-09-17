CPP = clang++
CPPFLAGS = -std=c++17 -stdlib=libc++ -Wall -O2

TARGET = main
SRCS=$(wildcard *.cpp)
OBJS=$(SRCS:.cpp=.o)

$(TARGET): $(OBJS)
	$(CPP) $(CPPFLAGS) -o $@ $(OBJS)

.PHONY: run
run:
	./main

.PHONY: test
test:
	./test.sh

.PHONY: fmt
fmt:
	clang-format -i *.cpp

.PHONY: clean
clean:
	rm -rf *.o $(TARGET) $(TARGET).dSYM
