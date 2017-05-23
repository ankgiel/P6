#GENERA EJECUTABLES A PARTIR DE FICHEROS OBJETO

all: ./bin/ejercicio5

#-----EJERCICIO 5

./bin/ejercicio5 : ./obj/matriz2D-2.o ./obj/ej5.o ./obj/main5.o 
	g++ -o $@ ./obj/ej5.o ./obj/main5.o ./obj/matriz2D-2.o

./obj/matriz2D-2.o : ./src/matriz2D-2.cpp
	g++ -c -o $@ -I./include/ ./src/matriz2D-2.cpp

./obj/ej5.o : ./src/ej5.cpp 
	g++ -c -o $@ -I./include/ ./src/ej5.cpp

./obj/main5.o : ./src/main5.cpp 
	g++ -c -o $@ -I./include/ ./src/main5.cpp



#-----

#-----

#----- 

#-----

mrproper: clean
	@echo Borrando ejecutables...
	rm ./bin/*
	
clean:
	@echo Borrando módulos objetos...
	rm ./obj/*
