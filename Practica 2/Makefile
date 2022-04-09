SRC = src
LIB = lib
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g -c -std=c++11


all: $(BIN)/pruebacronologia
# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

	
# ************ Compilación de módulos ************

 
$(BIN)/pruebacronologia : $(OBJ)/pruebacronologia.o
	$(CXX) -std=c++11 -o $(BIN)/pruebacronologia $(OBJ)/pruebacronologia.o

#$(OBJ)/fechahistorica.o : $(SRC)/fechahistorica.cpp
#	$(CXX) $(CPPFLAGS) -o $(OBJ)/fechahistorica.o $(SRC)/fechahistorica.cpp -I$(INCLUDE)

#$(OBJ)/cronologia.o : $(SRC)/cronologia.cpp
#	$(CXX) $(CPPFLAGS)  -o $(OBJ)/cronologia.o $(SRC)/cronologia.cpp -I$(INCLUDE)

$(OBJ)/pruebacronologia.o : $(SRC)/pruebacronologia.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/pruebacronologia.o $(SRC)/pruebacronologia.cpp



# ************ Limpieza ************
clean :
	#-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~
	-rm $(OBJ)/* $(SRC)/*~  ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
