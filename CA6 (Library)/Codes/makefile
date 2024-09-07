CC := g++

all:main.out


main.out: main.o library.o document.o member.o student.o professor.o reference.o book.o magazine.o
	$(CC) main.o library.o document.o member.o student.o professor.o reference.o book.o magazine.o -o main.out

main.o: library.hpp professor.hpp student.hpp member.hpp reference.hpp book.hpp magazine.hpp document.hpp main.cpp
	$(CC) -c main.cpp -o main.o

library.o:  document.hpp professor.hpp student.hpp member.hpp reference.hpp book.hpp magazine.hpp library.cpp
	$(CC) -c library.cpp -o library.o

student.o:  member.hpp document.hpp reference.hpp book.hpp magazine.hpp student.cpp
	$(CC) -c student.cpp -o student.o

professor.o: member.hpp  document.hpp reference.hpp book.hpp magazine.hpp professor.cpp
	$(CC) -c professor.cpp -o professor.o

member.o: reference.hpp book.hpp magazine.hpp document.hpp member.cpp
	$(CC) -c member.cpp -o member.o

document.o: document.cpp
	$(CC) -c document.cpp -o document.o

reference.o: document.hpp reference.cpp
	$(CC) -c reference.cpp -o reference.o

book.o: document.hpp book.cpp
	$(CC) -c book.cpp -o book.o

magazine.o: document.hpp magazine.cpp
	$(CC) -c magazine.cpp -o magazine.o


.PHONY: clean
clean:
	rm -r *.o
