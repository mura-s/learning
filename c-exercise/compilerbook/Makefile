CC=clang
CFLAGS=-Wall -std=c11
SRCS=$(wildcard *.c)
OBJS=$(SRCS:.c=.o)

mycc: $(OBJS)
	$(CC) -o $@ $(OBJS) $(LDFLAGS)

$(OBJS): mycc.h

test: mycc
	./test.sh

fmt:
	clang-format -i *.c *.h

clean:
	rm -f mycc *.o tmp*

.PHONY: test fmt clean
