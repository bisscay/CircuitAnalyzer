task:main.o circuit.o resistor.o unit.o series.o parallel.o
	g++ -o task main.o circuit.o resistor.o unit.o series.o parallel.o
	./task
main.o: main.cpp header.h
	g++ -Wall -ggdb -c main.cpp
circuit.o: circuit.cpp circuit.h
	g++ -Wall -ggdb -c circuit.cpp
resistor.o:resistor.cpp resistor.h
	g++ -Wall -ggdb -c resistor.cpp
unit.o: unit.cpp header.h
	g++ -Wall -ggdb -c unit.cpp
series.o:series.cpp header.h
	g++ -Wall -ggdb -c series.cpp
parallel.o:parallel.cpp header.h
	g++ -Wall -ggdb -c parallel.cpp
clean:
	rm -rf *.o *# *~ task 
