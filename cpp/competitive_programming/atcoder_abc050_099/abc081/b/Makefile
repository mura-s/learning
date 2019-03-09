CPP = clang++
CPPFLAGS = -Wall -O2 -std=c++14

TARGET = main
SRC = main.cpp

# make
all: clean $(TARGET)

# make main
$(TARGET):
	$(CPP) $(CPPFLAGS) -o $@ $(SRC)

# make clean
.PHONY: clean
clean:
	$(RM) $(TARGET)

