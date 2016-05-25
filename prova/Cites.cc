#include "Cites.hh"

void Cites::escriure_aux(Cjt_Frases& c){
	int aux=inici;
	for(int i=1; i<=c.numero_de_frases(); ++i, ++aux){
		cout << aux << ' ';
		c.imprimir_nfrase(i);
		}
}

void Cites::afegir_cita(int x, int y, Text text){
	text.consultar_contingut.consultar_frasesxy(x, y);
	string ref;
	string autor = text.consultar_autor();
	ref= autor[0]+
	mcites.insert(make_pair(ref, text));
}

void Cites::eliminar_cita(string& referencia){
	map <string, cita>::const_iterator it = mcites.find(referencia);
	if (it != mcites.end()) mcites.erase(referencia);
	else cout << "error" << endl;
}

void Cites::escriure_cita(string& referencia) const{
	map <string, cita>::const_iterator it = mcites.find(referencia);
	if (it != mcites.end()){
		it -> second;
		escriure_aux(*it.consultar_contingut());
		
		}
	else cout << "error" << endl;
}
