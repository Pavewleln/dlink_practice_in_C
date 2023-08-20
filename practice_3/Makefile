TARGET = main

CC = gcc

CFLAGS = -Wall -Wextra

RM = rm -rf

SRCS = main.c

OBJS = $(SRCS:.c=.o)

LIBRARY = plugins.a

all: $(TARGET)

$(TARGET): $(OBJS) $(LIBRARY)
	$(CC) $(CFLAGS) $(OBJS) -L. -lplugins -o $@

$(LIBRARY): plugins.o
	ar rcs $@ $^

%.o: %.c include/*.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(LIBRARY) $(TARGET)