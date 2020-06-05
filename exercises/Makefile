CC = gcc
CFLAGS = -ansi -pedantic -Wall
DEPS = helpers.c
SOURCES = $(wildcard e*.c)
EXECS = $(SOURCES:.c=)

all: $(EXECS)

.c:
	$(CC) $(CFLAGS) -o $@ $< $(DEPS)
	@echo "successful build of" $@

clean:
	rm -f $(EXECS)
