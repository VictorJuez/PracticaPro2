#include "Text.hh"
using namespace std;

int main(){
	
	Text text;
	string linia;
	getline (cin, linia);
	cout << linia << endl;
	text.llegir(linia);
	
	Cjt_Frases cfrases = text.consultar_contingut();
	cfrases.escriure();
}
