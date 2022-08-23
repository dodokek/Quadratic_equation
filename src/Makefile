CC = g++
CFLAGS = -g -Wall

TARGET = square_equation
ARG = argument_proccessing
TEST = unit_test

all : $(TARGET)

$(TARGET) : $(TARGET).o $(ARG).o $(TEST).o log.o input.o
	$(CC) $(CFLAGS) $(TARGET).o $(ARG).o $(TEST).o log.o input.o -o $(TARGET)   
	  
$(TARGET).o : $(TARGET).cpp include/$(TARGET).h include/$(ARG).h include/$(TEST).h include/input.h include/log.h
	$(CC) $(CFLAGS) -c $(TARGET).cpp

$(ARG).o : $(ARG).cpp include/$(ARG).h
	$(CC) $(CFLAGS) $(ARG).cpp -c

$(TEST).o : $(TEST).cpp include/$(TEST).h
	$(CC) $(CFLAGS) $(TEST).cpp -c

input.o : input.cpp include/input.h
	$(CC) $(CFLAGS) input.cpp -c

log.o : log.cpp include/log.h
	$(CC) $(CFLAGS) log.cpp -c

clean:
	rm -rf *.o $(TARGET)