#Environment settings

CC = g++
CFLAGS = -g -Wall

#Variables

TARGET = square_equation
ARG = argument_proccessing
TEST = unit_test
LOG = log
MAIN = main
INPUT = input
GRAPH = graphics

#Body

all : $(MAIN)

$(MAIN) : $(MAIN).o $(TARGET).o $(ARG).o $(TEST).o $(LOG).o $(INPUT).o $(GRAPH).o
	$(CC) $(CFLAGS) $^ -o $@   

$(MAIN).o : $(MAIN).cpp
	$(CC) $(CFLAGS) $< -c
	  
$(TARGET).o : $(TARGET).cpp 
	$(CC) $(CFLAGS) -c $<

$(ARG).o : $(ARG).cpp 
	$(CC) $(CFLAGS) $< -c

$(TEST).o : $(TEST).cpp
	$(CC) $(CFLAGS) $< -c

$(INPUT).o : $(INPUT).cpp
	$(CC) $(CFLAGS) $< -c

$(LOG).o : $(LOG).cpp 
	$(CC) $(CFLAGS) $< -c

$(GRAPH).o : $(GRAPH).cpp
	$(CC) $(CFLAGS) $(GRAPH).cpp -c

clean:
	rm -rf *.o *.save $(TARGET)