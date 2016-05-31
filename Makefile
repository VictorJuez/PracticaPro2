OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare -std=c++0x

practica.tar: program.cc Cjt_Frases.cc Cjt_Textos.cc Text.cc Cites.cc Cites.hh Cjt_Frases.hh Cjt_Textos.hh Text.hh Makefile jp_enric.bover.est.fib.upc.edu_entrada.txt jp_enric.bover.est.fib.upc.edu_sortida.txt jp_victor.juez.est.fib.upc.edu_entrada.txt jp_victor.juez.est.fib.upc.edu_sortida.txt html.zip equip.pdf
	tar -cvf practica.tar program.cc Cjt_Frases.cc Cjt_Textos.cc Text.cc Cites.cc Cjt_Frases.hh Cjt_Textos.hh Text.hh Cites.hh Makefile jp_enric.bover.est.fib.upc.edu_entrada.txt jp_enric.bover.est.fib.upc.edu_sortida.txt jp_victor.juez.est.fib.upc.edu_entrada.txt jp_victor.juez.est.fib.upc.edu_sortida.txt html.zip equip.pdf 

program.exe: program.o Cjt_Frases.o Cjt_Textos.o Text.o Cites.o
	g++ -o program.exe program.o Cjt_Frases.o Cjt_Textos.o Text.o Cites.o

program.o: program.cc
	g++ -c program.cc $(OPCIONS)

Cjt_Frases.o: Cjt_Frases.cc
	g++ -c Cjt_Frases.cc $(OPCIONS)

Cjt_Textos.o: Cjt_Textos.cc
	g++ -c Cjt_Textos.cc $(OPCIONS)

Text.o: Text.cc
	g++ -c Text.cc $(OPCIONS)

Cites.o: Cites.cc
	g++ -c Cites.cc $(OPCIONS)

clean:
	rm *.o
	rm *.exe
