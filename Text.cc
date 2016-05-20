#include "Text.hh"

Text::Text(){
	
}
//~Text()

void Text::substituir_paraula(string paraula1, string paraula2){
	cjtfrase.substituir_paraula(paraula1, paraula2);
}

list<string> Text::consultar_autor(){
	return autor;
}

list<string> Text::consultar_titol(){
	return titol;
}

Cjt_Frases Text::consultar_contingut(){
	return cjtfrase;
}

void Text::llegir(istringstream& iss){
	string paraula;
	iss >> paraula;
	bool primer = true;
	list <string>::iterator it = titol.begin();
	while (paraula[paraula.size()-1] != '"'){
		if (primer){
			paraula.erase(0,1);
			primer = false;
			titol.insert(it,paraula);
			iss >> paraula;
			}
		else {
			titol.insert(it,paraula);
			iss >> paraula;
			}
		}
	int ultima = paraula.size()-1;
	paraula.erase(ultima,1);
	titol.insert(it,paraula);
	
	it = autor.begin();
	cin >> paraula;
	cin >> paraula;
	primer = true;
	while (paraula[paraula.size()-1] != '"'){
		if (primer){
			paraula.erase(0,1);
			primer = false;
			autor.insert(it,paraula);
			cin >> paraula;
			}
		else {
			autor.insert(it,paraula);
			cin >> paraula;
			}
		}
	ultima = paraula.size()-1;
	paraula.erase(ultima,1);
	autor.insert(it,paraula);
	cjtfrase.llegir();
}
