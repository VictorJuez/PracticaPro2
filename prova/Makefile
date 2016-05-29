OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare -std=c++0x

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
