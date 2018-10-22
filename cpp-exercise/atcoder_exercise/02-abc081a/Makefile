CPP = clang++
CPPFLAGS = -Wall -O2 -std=c++14

TARGET = main
SRC = main.cpp

$(TARGET):
	$(CPP) $(CPPFLAGS) -o $@ $(SRC)

.PHONY: clean
clean:
	$(RM) $(TARGET)

