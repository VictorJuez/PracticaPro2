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
			text.llegir(linia);
			}
	}
	cfrases = text.consultar_contingut();
	cfrases.taula_frequencies();
	text.substituir_paraula("lol", "XD");
	cfrases = text.consultar_contingut();
	cfrases.escriure();
	cfrases.taula_frequencies();
	/*cfrases=text.consultar_contingut();
	cfrases.escriure();
	
	string autor;
	string titol;
	
	autor=text.consultar_autor();
	titol=text.consultar_titol();
	
	cout << '"' << autor << '"' << endl;
	cout << '"' << titol << '"' << endl;
	
	text.substituir_paraula("lol", "XD");
	cfrases=text.consultar_contingut();
	cfrases.escriure();
	
	cfrases.taula_frequencies();*/
}
