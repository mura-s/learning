mycc: mycc.c

fmt:
	clang-format -i *.c
	# clang-format -i *.c *.h

test: mycc
	./test.sh

clean:
	rm -f mycc *.o tmp*

.PHONY: fmt test clean
