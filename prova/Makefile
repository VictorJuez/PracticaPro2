OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG

main.exe: main.o Cjt_Frases.o Cjt_Textos.o Text.o Cites.o
	g++ -o main.exe main.o Cjt_Frases.o Cjt_Textos.o Text.o Cites.o

main.o: main.cc
	g++ -c main.cc $(OPCIONS)

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
