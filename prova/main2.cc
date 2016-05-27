#include <sstream>
#include <string>
#include <iostream>
#include "Cjt_Textos.hh"
#include "Cites.hh"
using namespace std;

int main(){
	/*string linia;
	getline(cin, linia);*/
	
	Text hola;
	string titol;
	getline(cin, titol);
	hola.llegir(titol);
	
	string s;
	s= "({hola & adeu} | {bye})";
	hola.consultar_contingut().expressio(s);
}
