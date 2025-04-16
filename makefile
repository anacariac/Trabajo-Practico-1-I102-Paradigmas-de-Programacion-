ejercicio1:
	g++ ej1/main.cpp ej1/personajesdecombate.cpp ej1/armasmagicas.cpp ej1/clasedecombate.cpp ej1/claseguerreros.cpp ej1/clasemagica.cpp ej1/clasemagos.cpp ej1/personajesmagicos.cpp ej1/armasdecombate.cpp -Wall -o ejecutable.exe
	valgrind ./ejecutable.exe
	
ejercicio2:
	g++ ej2/main.cpp ej1/*.cpp ej2/personajefactory.cpp ej2/funcionesauxiliares.cpp -Wall -o ejecutable.exe
	valgrind ./ejecutable.exe

ejercicio3:
	g++ ej3/ej3.cpp ej2/personajefactory.cpp ej2/funcionesauxiliares.cpp ej1/*.cpp -Wall -o ejecutable.exe
	valgrind ./ejecutable.exe

