CC := g++

all: ModelSim.out

ModelSim.out: main.o CmdsManager.o CircuitsManager.o Circuit.o Module.o MainModule.o NewModule.o XorGate.o NotGate.o NorGate.o NandGate.o OrGate.o AndGate.o Gate.o InterfaceManager.o ModelSim.o Exeptions.o
	$(CC) main.o CmdsManager.o CircuitsManager.o Circuit.o Module.o MainModule.o NewModule.o XorGate.o NotGate.o NorGate.o NandGate.o OrGate.o AndGate.o Gate.o InterfaceManager.o ModelSim.o Exeptions.o -o ModelSim.out

main.o: CmdsManager.hpp CircuitsManager.hpp Wire.hpp Exeptions.hpp Circuit.hpp Module.hpp MainModule.hpp NewModule.hpp XorGate.hpp NotGate.hpp NorGate.hpp NandGate.hpp OrGate.hpp AndGate.hpp Gate.hpp InterfaceManager.hpp ModelSim.hpp main.cpp
	$(CC) -c main.cpp -o main.o

Circuit.o: Wire.hpp Exeptions.hpp Circuit.hpp
	$(CC) -c Circuit.cpp -o Circuit.o

Gate.o: Wire.hpp Exeptions.hpp Circuit.hpp Gate.hpp
	$(CC) -c Gate.cpp -o Gate.o

AndGate.o: Wire.hpp Exeptions.hpp Circuit.hpp AndGate.hpp Gate.hpp
	$(CC) -c AndGate.cpp -o AndGate.o

OrGate.o: Wire.hpp Exeptions.hpp Circuit.hpp OrGate.hpp Gate.hpp
	$(CC) -c OrGate.cpp -o OrGate.o

NandGate.o: Wire.hpp Exeptions.hpp Circuit.hpp NandGate.hpp Gate.hpp
	$(CC) -c NandGate.cpp -o NandGate.o

NorGate.o: Wire.hpp Exeptions.hpp Circuit.hpp NorGate.hpp Gate.hpp
	$(CC) -c NorGate.cpp -o NorGate.o

NotGate.o: Wire.hpp Exeptions.hpp Circuit.hpp NotGate.hpp Gate.hpp
	$(CC) -c NotGate.cpp -o NotGate.o

XorGate.o: Wire.hpp Exeptions.hpp Circuit.hpp XorGate.hpp Gate.hpp
	$(CC) -c XorGate.cpp -o XorGate.o

Module.o: Wire.hpp Exeptions.hpp Circuit.hpp Module.hpp XorGate.hpp NotGate.hpp NorGate.hpp NandGate.hpp OrGate.hpp AndGate.hpp Gate.hpp
	$(CC) -c Module.cpp -o Module.o

NewModule.o: Wire.hpp Exeptions.hpp Circuit.hpp Module.hpp NewModule.hpp XorGate.hpp NotGate.hpp NorGate.hpp NandGate.hpp OrGate.hpp AndGate.hpp Gate.hpp
	$(CC) -c NewModule.cpp -o NewModule.o

MainModule.o: Wire.hpp Exeptions.hpp Circuit.hpp Module.hpp MainModule.hpp XorGate.hpp NotGate.hpp NorGate.hpp NandGate.hpp OrGate.hpp AndGate.hpp Gate.hpp
	$(CC) -c MainModule.cpp -o MainModule.o

CircuitsManager.o: Wire.hpp Exeptions.hpp Circuit.hpp Module.hpp MainModule.hpp NewModule.hpp XorGate.hpp NotGate.hpp NorGate.hpp NandGate.hpp OrGate.hpp AndGate.hpp Gate.hpp CircuitsManager.hpp 
	$(CC) -c CircuitsManager.cpp -o CircuitsManager.o

CmdsManager.o: Wire.hpp Exeptions.hpp Circuit.hpp Module.hpp MainModule.hpp NewModule.hpp XorGate.hpp NotGate.hpp NorGate.hpp NandGate.hpp OrGate.hpp AndGate.hpp Gate.hpp CircuitsManager.hpp CmdsManager.hpp
	$(CC) -c CmdsManager.cpp -o CmdsManager.o

InterfaceManager.o: InterfaceManager.hpp
	$(CC) -c InterfaceManager.cpp -o InterfaceManager.o

ModelSim.o: Wire.hpp Circuit.hpp Module.hpp MainModule.hpp NewModule.hpp XorGate.hpp NotGate.hpp NorGate.hpp NandGate.hpp OrGate.hpp AndGate.hpp Gate.hpp CircuitsManager.hpp CmdsManager.hpp Exeptions.hpp ModelSim.hpp
	$(CC) -c ModelSim.cpp -o ModelSim.o

Exeptions.o: Exeptions.hpp
	$(CC) -c Exeptions.cpp -o Exeptions.o

.PHONY: clean
clean:
	rm -r *.o main.out
