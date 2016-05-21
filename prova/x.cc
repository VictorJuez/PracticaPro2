#include "cjtextosvictor.hh"
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
    Cjt_Frases cfrases;
    Cjt_Textos ctextos;
     string linia;
     ws(cin);
     getline(cin,linia); 
    
    for(int i=0; i<3; ++i){
		Text text;
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
		ws(cin);
		getline (cin, linia);
		
	}
		ctextos.imprimir_tots_autors();
		
}
