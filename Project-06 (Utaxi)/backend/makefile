CC := g++

all:utaxi.out


utaxi.out: main.o utaxi.o user.o driver.o passenger.o exceptions.o trip.o location.o 
	$(CC) main.o utaxi.o user.o driver.o passenger.o exceptions.o trip.o location.o  -o utaxi.out

main.o: utaxi.hpp passenger.hpp driver.hpp user.hpp exceptions.hpp trip.hpp location.hpp  main.cpp
	$(CC) -c main.cpp -o main.o

utaxi.o:   passenger.hpp driver.hpp user.hpp exceptions.hpp trip.hpp location.hpp  utaxi.cpp
	$(CC) -c utaxi.cpp -o utaxi.o

driver.o:  user.hpp  driver.cpp
	$(CC) -c driver.cpp -o driver.o

passenger.o: user.hpp passenger.cpp
	$(CC) -c passenger.cpp -o passenger.o

user.o:   exceptions.hpp user.cpp
	$(CC) -c user.cpp -o user.o

exceptions.o:  exceptions.cpp
	$(CC) -c exceptions.cpp -o exceptions.o

trip.o:  exceptions.hpp trip.cpp
	$(CC) -c trip.cpp -o trip.o

location.o: location.cpp
	$(CC) -c location.cpp -o location.o


.PHONY: clean
clean:
	rm -r *.o
