CFLAGS=-std=c11 -g -static
SRCS=$(wildcard *.c)
OBJS=$(SRCS:.c=.o)

acc: $(OBJS)
	$(CC) -pthread -o ../result/res $(OBJS) $(LDFLAGS)

$(OBJS):

clean:
	rm -f *.o *~ tmp* res

.PHONY: clean
