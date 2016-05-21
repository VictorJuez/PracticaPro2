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
			cout << linia << endl;
			text.llegir(linia);
			ctextos.afegir_text(text);
			}
	}
	
	ws(cin);
	getline(cin,linia);
	istringstream iss1(linia);
	iss1 >> op;
	cout << op << endl;
    if (op == "afegir"){
		iss1>>op;
		if(op == "text"){
			text.llegir(linia);
			ctextos.afegir_text(text);
			}
	}
	
	ws(cin);
	getline(cin,linia);
	istringstream iss2(linia);
	iss2 >> op;
	cout << op << endl;
    if (op == "afegir"){
		iss2>>op;
		if(op == "text"){
			text.llegir(linia);
			ctextos.afegir_text(text);
			}
	}
	ws(cin);
	getline(cin, linia);
	istringstream iss3(linia);
	iss3 >> op;
	cout << op << endl;
	
	if (op== "triar"){
		iss3 >> op;
		if(op == "text"){
			cout << linia << endl;
			ctextos.triar_text(linia);
			
			if(ctextos.text_triat()){
			cout << "Text triat  " << endl;
			text = ctextos.consultar_text_triat();
			cout << text.consultar_titol() << endl;}
			else cout <<"cap text triat, error" << endl;
			}
		}
	ws(cin);
	getline(cin, linia);
	istringstream iss4(linia);
	iss4 >> op;
	cout << op << endl;

	if (op== "tots"){
		iss4 >> op;
		cout << "ok" << endl;
		if(op == "autors"){
			cout << "ok" << endl;
			cout << linia << endl;
			ctextos.imprimir_tots_autors();
		}
	
	//ctextos.imprimir_textos();
	}
	string h = "triar text {halooo}";
	ctextos.triar_text(h);
	text = ctextos.consultar_text_triat();
	
	cout << text.consultar_autor() << endl;
	
	cfrases = text.consultar_contingut();
	
	cout << cfrases.numero_de_frases() << ' ' << cfrases.numero_de_paraules() << endl;
	
	cfrases.escriure();
}
