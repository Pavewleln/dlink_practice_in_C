TARGET = main

CC = gcc

CFLAGS = -Wall -Wextra

RM = rm -rf

SRCS = main.c txt_file_generator.c html_file_generator.c  c_file_generator.c csv_reader.c cmd_line_parser.c 

OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c include/*.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(TARGET)