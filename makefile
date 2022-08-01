#Compiling this programm in the most efficient way

#-----------------------------

CC = g++
CFLAGS = -g
TARGET = square_equation.exe

#------------------------------

#Building target

$(TARGET): square_equation.o
	$(CC) $(CFLAGS) -o $(TARGET) square_equation.o

#------------------------------

square_equation.o: square_equation.cpp square_equation.h log.h argument_proccessing.h input.h unit_tests.h 
	$(CC) $(CFLAGS) -c square_equation.cpp	

run: $(TARGET)