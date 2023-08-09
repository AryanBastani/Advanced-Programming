CC=g++
STD=-std=c++11 -Wall -pedantic
CF=$(STD)
BUILD_DIR=build
TEMPLATE_DIR=.template

all: $(BUILD_DIR) myserver.out

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)


$(BUILD_DIR)/main.o: main.cpp backend/utaxi.hpp backend/passenger.hpp backend/driver.hpp backend/user.hpp backend/exceptions.hpp backend/trip.hpp backend/location.hpp my_server/my_server.hpp server/server.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp handlers/ut_handlers.hpp handlers/error_handlers.hpp
	$(CC) $(CF) -c main.cpp -o $(BUILD_DIR)/main.o

$(BUILD_DIR)/my_server.o: my_server/my_server.cpp server/server.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp
	$(CC) $(CF) -c my_server/my_server.cpp -o $(BUILD_DIR)/my_server.o

$(BUILD_DIR)/ut_handlers.o: handlers/ut_handlers.cpp server/server.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp handlers/error_handlers.hpp
	$(CC) $(CF) -c handlers/ut_handlers.cpp -o $(BUILD_DIR)/ut_handlers.o

$(BUILD_DIR)/error_handlers.o: handlers/error_handlers.cpp server/server.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp
	$(CC) $(CF) -c handlers/error_handlers.cpp -o $(BUILD_DIR)/error_handlers.o

$(BUILD_DIR)/utaxi.o: backend/utaxi.cpp backend/passenger.hpp backend/driver.hpp backend/user.hpp backend/exceptions.hpp backend/trip.hpp backend/location.hpp  
	$(CC) $(CF) -c backend/utaxi.cpp -o $(BUILD_DIR)/utaxi.o

$(BUILD_DIR)/driver.o: backend/driver.cpp backend/user.hpp  
	$(CC) $(CF) -c backend/driver.cpp -o $(BUILD_DIR)/driver.o

$(BUILD_DIR)/passenger.o: backend/passenger.cpp backend/user.hpp 
	$(CC) $(CF) -c backend/passenger.cpp -o $(BUILD_DIR)/passenger.o

$(BUILD_DIR)/user.o: backend/user.cpp backend/exceptions.hpp 
	$(CC) $(CF) -c backend/user.cpp -o $(BUILD_DIR)/user.o

$(BUILD_DIR)/exceptions.o: backend/exceptions.cpp
	$(CC) $(CF) -c backend/exceptions.cpp -o $(BUILD_DIR)/exceptions.o

$(BUILD_DIR)/trip.o: backend/trip.cpp backend/exceptions.hpp 
	$(CC) $(CF) -c backend/trip.cpp -o $(BUILD_DIR)/trip.o

$(BUILD_DIR)/location.o: backend/location.cpp
	$(CC) $(CF) -c backend/location.cpp -o $(BUILD_DIR)/location.o

$(BUILD_DIR)/template_parser.o: utils/template_parser.cpp utils/template_parser.hpp utils/request.cpp utils/request.hpp utils/utilities.hpp utils/utilities.cpp
	$(CC) $(CF) -c utils/template_parser.cpp -o $(BUILD_DIR)/template_parser.o

$(BUILD_DIR)/response.o: utils/response.cpp utils/response.hpp utils/include.hpp
	$(CC) $(CF) -c utils/response.cpp -o $(BUILD_DIR)/response.o

$(BUILD_DIR)/request.o: utils/request.cpp utils/request.hpp utils/include.hpp utils/utilities.hpp
	$(CC) $(CF) -c utils/request.cpp -o $(BUILD_DIR)/request.o

$(BUILD_DIR)/utilities.o: utils/utilities.cpp utils/utilities.hpp
	$(CC) $(CF) -c utils/utilities.cpp -o $(BUILD_DIR)/utilities.o

$(BUILD_DIR)/server.o: server/server.cpp server/server.hpp server/route.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp utils/template_parser.hpp utils/template_parser.cpp
	$(CC) $(CF) -c server/server.cpp -o $(BUILD_DIR)/server.o

$(BUILD_DIR)/route.o: server/route.cpp server/route.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp
	$(CC) $(CF) -c server/route.cpp -o $(BUILD_DIR)/route.o

myserver.out: $(BUILD_DIR)/my_server.o $(BUILD_DIR)/ut_handlers.o $(BUILD_DIR)/error_handlers.o $(BUILD_DIR)/main.o $(BUILD_DIR)/response.o $(BUILD_DIR)/request.o $(BUILD_DIR)/utilities.o $(BUILD_DIR)/server.o $(BUILD_DIR)/route.o $(BUILD_DIR)/template_parser.o $(BUILD_DIR)/utaxi.o $(BUILD_DIR)/driver.o $(BUILD_DIR)/passenger.o $(BUILD_DIR)/exceptions.o $(BUILD_DIR)/user.o $(BUILD_DIR)/trip.o $(BUILD_DIR)/location.o
	$(CC) $(CF) $(BUILD_DIR)/my_server.o $(BUILD_DIR)/ut_handlers.o $(BUILD_DIR)/error_handlers.o $(BUILD_DIR)/main.o $(BUILD_DIR)/response.o $(BUILD_DIR)/request.o $(BUILD_DIR)/utilities.o $(BUILD_DIR)/server.o $(BUILD_DIR)/route.o $(BUILD_DIR)/template_parser.o $(BUILD_DIR)/utaxi.o $(BUILD_DIR)/driver.o $(BUILD_DIR)/passenger.o $(BUILD_DIR)/exceptions.o $(BUILD_DIR)/user.o $(BUILD_DIR)/trip.o $(BUILD_DIR)/location.o  -o myserver.out

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR) $(TEMPLATE_DIR) *.o *.out &> /dev/null
