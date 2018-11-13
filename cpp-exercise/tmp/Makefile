TARGET = main

CPP = clang++
CPPFLAGS = -Wall -Wextra -O2 -std=c++14 -MMD -MP

SRCS = $(wildcard *.cpp)
OBJS := $(SRCS:.cpp=.o) #SRCSの各ファイルのサフィックスの.cppを.oに変換
DEPS := $(OBJS:.o=.d)

$(TARGET): $(OBJS)
	$(CPP) -o $@ $^

.PHONY: clean
clean:
	$(RM) $(TARGET) $(OBJS) $(DEPS)

-include $(DEPS)
