Main: Main.o Racional.o 
	g++ Main.o Racional.o -o Main
Main.o: Main.cpp Racional.h
	g++ -c Main.cpp
Racional.o: Racional.h Racional.cpp
	g++ -c Racional.cpp
Clean:
	rm -f *.o temp
