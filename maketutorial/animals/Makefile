dog_program : main.o dog.o
	clang++ dog.o main.o -o dog_program
dog.o : 
	clang++ -c dog.cpp
main.o :
	clang++ -c main.cpp
clean :
	rm dog_program *.o
