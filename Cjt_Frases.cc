#include "Cjt_Frases.hh"
#include "Frase.hh"

Cjt_Frases::Cjt_Frases(){
	
}

void substituir_paraula(string paraula1, string paraula2){
	for(int i=0; i<vfrases.size(); ++i){
		vfrases[i].substituir_paraula(paraula1, paraula2);
		}
}

int numero_de_paraules() const {
	int sum=0;
	
	for(int i=0; i<vfrases.size(); ++i){
		sum += vfrases[i].num_de_paraules();
		}
	return sum;
}

int numero_de_frases() const {
	return vfrases.size();
}

bool conte_paraula(string paraula) const {
	bool trobat=false;
	for(int i=0; i<vfrases.size() and not trobat; ++i){
		if (vfrases[i].conte_paraula(paraula)) trobat=true;
		}
	return trobat;
}

bool conte_paraules(vector<string>& paraules) const {
	bool trobat = false;
	for(int i=0; i<vfrases.size() and not trobat; ++i){
		if(vfrases[i].conte_paraules(paraules)) trobat=true;
		}
	return trobat;
}

void taula_frequencies() const;

void llegir() {	
	
}

void escriure() const;
