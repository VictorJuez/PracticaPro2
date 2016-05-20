#include "Cjt_Textos.hh"
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
    Text text, text1, text2;
    Cjt_Frases cfrases;
    Cjt_Textos ctextos;
       
    string linia;
    getline(cin,linia);
    istringstream iss(linia);
    string op;
    iss >> op;

    if (op == "afegir"){
		iss>>op;
		if(op == "text"){
			text.llegir(linia);
			ctextos.afegir_text(text);
			}
	}
	
	getline(cin,linia);
    iss >> op;
    
    if (op == "afegir"){
		iss>>op;
		if(op == "text"){
			text1.llegir(linia);
			ctextos.afegir_text(text1);
			}
	}
	getline(cin,linia);
    iss >> op;
    
    if (op == "afegir"){
		iss>>op;
		if(op == "text"){
			text2.llegir(linia);
			ctextos.afegir_text(text2);
			}
	}
	
	ctextos.imprimir_textos();
}
