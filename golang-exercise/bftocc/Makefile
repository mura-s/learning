NAME=bftocc
BIN_DIR=bin
INPUT_BF=input/bf.txt

all: clean build

build:
	go build -o $(BIN_DIR)/$(NAME)

clean:
	rm -f $(BIN_DIR)/*

run: build
	$(BIN_DIR)/$(NAME) < $(INPUT_BF)

