#include "Text.hh"
#include <iostream>
using namespace std;

void escriure_llista(list<string>& imp){
	list<string>::iterator it;
	bool primer=true;
	for(it=imp.begin(); it!= imp.end(); ++it){
		if (primer){
			primer=false;
			cout << '"' << *it;
			}
		else cout<< ' ' << *it;
		}
	cout << '"' << endl;
}


int main() {
    Text text, text_triat;
    Cjt_Frases cfrases;
       
    string linia;
    getline(cin,linia);
    istringstream iss(linia);
    string op;
    iss >> op;
    if (op == "afegir"){
		iss>>op;
		if(op == "text"){
			text.llegir(iss);
			}
	}
	cfrases=text.consultar_contingut();
	cfrases.escriure();
	
	list<string> autor;
	list<string> titol;
	
	autor=text.consultar_autor();
	titol=text.consultar_titol();
	
	escriure_llista(autor);
	escriure_llista(titol);
	
	text.substituir_paraula("lol", "XD");
	cfrases=text.consultar_contingut();
	cfrases.escriure();
	
	cfrases.taula_frequencies();
}
