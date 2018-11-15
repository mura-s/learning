CC=gcc
CFLAGS=-Wall -std=c11
SRCS=$(wildcard *.c)
OBJS=$(SRCS:.c=.o)

mycc: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LDFLAGS)

$(OBJS): mycc.h

fmt:
	clang-format -i *.c *.h

test: mycc
	./mycc -test
	./test.sh

clean:
	rm -f mycc *.o tmp*

docker-build:
	docker build . -t mycc

docker-test:
	docker run --rm mycc

.PHONY: fmt test clean \
	docker-build docker-test
