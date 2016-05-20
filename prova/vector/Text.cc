#include "Text.hh"

Text::Text(){
	
}
//~Text()

void Text::substituir_paraula(string paraula1, string paraula2){
	cjtfrase.substituir_paraula(paraula1, paraula2);
}

string Text::consultar_autor(){
	return autor;
}

string Text::consultar_titol(){
	return titol;
}

Cjt_Frases Text::consultar_contingut(){
	return cjtfrase;
}

void Text::llegir(string& linia){
	linia.erase(0,13);
    linia.erase(linia.size()-1,1);
    titol = linia;
    
    getline(cin,linia);
    linia.erase(0,7);
    linia.erase(linia.size()-1,1);
    autor = linia;
    
    cjtfrase.llegir();
}
