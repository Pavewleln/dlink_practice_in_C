TARGET = main
CC = gcc
CFLAGS = -Wall -Wextra
RM = rm -rf
SRCS = main.c plugins.c
OBJS = $(SRCS:.c=.o)
LIBRARY = plugins.so

all: $(TARGET)

$(TARGET): $(OBJS) $(LIBRARY)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(LIBRARY): plugins.o
	$(CC) $(CFLAGS) -shared -o $@ $^

%.o: %.c include/*.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(LIBRARY) $(TARGET)