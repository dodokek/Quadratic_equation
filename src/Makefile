CC = g++
CFLAGS = -g -Wall

TARGET = square_equation
ARG = argument_proccessing
TEST = unit_test

all : main

main : main.o $(TARGET).o $(ARG).o $(TEST).o log.o input.o graphics.o
	$(CC) $(CFLAGS) main.o $(TARGET).o $(ARG).o $(TEST).o log.o input.o graphics.o -o main   

main.o : main.cpp include/main.h
	$(CC) $(CFLAGS) main.cpp -c
	  
$(TARGET).o : $(TARGET).cpp include/$(TARGET).h include/$(ARG).h include/$(TEST).h include/input.h include/log.h include/graphics.h
	$(CC) $(CFLAGS) -c $(TARGET).cpp

$(ARG).o : $(ARG).cpp include/$(ARG).h
	$(CC) $(CFLAGS) $(ARG).cpp -c

$(TEST).o : $(TEST).cpp include/$(TEST).h
	$(CC) $(CFLAGS) $(TEST).cpp -c

input.o : input.cpp include/input.h
	$(CC) $(CFLAGS) input.cpp -c

log.o : log.cpp include/log.h
	$(CC) $(CFLAGS) log.cpp -c

graphics.o : graphics.cpp include/graphics.h
	$(CC) $(CFLAGS) graphics.cpp -c

clean:
	rm -rf *.o *.save $(TARGET)