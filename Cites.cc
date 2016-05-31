#include "Cites.hh"
#include <stdlib.h>

Cites::Cites(){
	
}

Cites::iterador Cites::buscar_referencia(string s){
	for(itc=lcites.begin(); itc!=lcites.end(); ++itc){
		if((*itc).referencia == s) return itc;
		}
	return itc;
}

string Cites::crear_ref(string s, int n){
	string Result;         
	ostringstream convert;  
	convert << n;     
	Result = convert.str();
	return s + Result;
}

bool Cites::comp(const cita& a, const cita& b){
	string primer = a.referencia;
	string primer_lletres;
	for (int i = 0; i < primer.size(); ++i){
		if ((primer[i] >= 'a' and primer[i] <= 'z') or (primer[i] >= 'A' and primer[i] <= 'Z')){
			primer_lletres.insert(primer_lletres.end(),1,primer[i]);
			}
		}
	
	string segon = b.referencia;
	string segon_lletres;
	for (int i = 0; i < segon.size(); ++i){
		if ((segon[i] >= 'a' and segon[i] <= 'z') or (segon[i] >= 'A' and segon[i] <= 'Z')){
			segon_lletres.insert(segon_lletres.end(),1,segon[i]);
			}
		}
	if (primer != segon) return primer_lletres < segon_lletres;
	string p;
	for (int i = 0; i < primer.size(); ++i){
		if (primer[i] >= '0' and primer[i] <= '9'){
			p.insert(p.end(),1,primer[i]);
			}
		}
	string s;
	for (int i = 0; i < segon.size(); ++i){
		if (segon[i] >= '0' and segon[i] <= '9'){
			s.insert(s.end(),1,primer[i]);
			}
		}
	int pr = atoi(p.c_str());
	int se = atoi(s.c_str());	
	return pr < se;
}

void Cites::escriure_cita(string& referencia){
	itc=buscar_referencia(referencia);
	Cjt_Frases cfrases= (*itc).tcita.consultar_contingut();
	
	int aux=(*itc).inici;
	for(int i=1; i<=cfrases.numero_de_frases(); ++i, ++aux){
		cout << aux << ' ';
		cfrases.imprimir_nfrase(i);
		}
}

void Cites::afegir_cita(int x, int y, Text text){
	text.consultar_frasesxy(x,y);
	string r;
	string autor = text.consultar_autor();
	
	istringstream iss(autor);
	string nom;
	iss >> nom;
	while (iss){
		r.insert(r.end(),1,nom[0]);
		iss >> nom;
		}
	
	bool trobat=false;
	for(int i=0; i<vref.size() and not trobat; ++i){
		if(vref[i].ref == r){
			trobat=true;
			++vref[i].contador;
			int aux = vref[i].contador;
			r= crear_ref(r, aux);
			}
		}
	if (not trobat){
		sref saux;
		saux.ref = r;
		saux.contador=1;
		r=crear_ref(r, 1);
		vref.push_back(saux);
		}
		
	cita xcita;
	xcita.referencia=r;
	xcita.inici = x;
	xcita.tcita = text;
	
	itc = lcites.end();
	lcites.insert(itc, xcita);
	lcites.sort(comp);
}

void Cites::eliminar_cita(string& referencia){
	itc=buscar_referencia(referencia);
	itc=lcites.erase(itc);
}

Cjt_Frases Cites::consultar_contingut(string r){
	itc=buscar_referencia(r);
	return (*itc).tcita.consultar_contingut();
}

bool Cites::existeix_cita(int x, int y, string titol, string autor){
	for(itc=lcites.begin(); itc!=lcites.end(); ++itc){
		if((*itc).tcita.consultar_titol() == titol and (*itc).tcita.consultar_autor() == autor){
			if(((*itc).inici == x)and ((*itc).inici + (*itc).tcita.consultar_contingut().numero_de_frases()-1 == y)) return true;
			}
		}
	return false;
}

bool Cites::existeix_cita_ref(string referencia){
	itc=buscar_referencia(referencia);
	if (itc == lcites.end()) return false;
	else return true;
}

void Cites::escriure_cita_ref(string& referencia){
	itc=buscar_referencia(referencia);
	cout << (*itc).tcita.consultar_autor() << ' ';
	cout << '"' << (*itc).tcita.consultar_titol()<< '"' << endl;
	cout << (*itc).inici << '-' << (*itc).inici + (*itc).tcita.consultar_contingut().numero_de_frases()-1 << endl;
	escriure_cita(referencia);
}

void Cites::escriure_cites_autor(string& autor){
	lcites.sort(comp);
	for(itc=lcites.begin(); itc!=lcites.end(); ++itc){
		if((*itc).tcita.consultar_autor() == autor){
			cout <<(*itc).referencia << endl;
			escriure_cita((*itc).referencia);
			cout << '"' << (*itc).tcita.consultar_titol() << '"' << endl;
			}
		}
}

void Cites::escriure_cita_triat(string titol, string autor){
	lcites.sort(comp);
	for (itc = lcites.begin(); itc != lcites.end(); ++itc){
		if (titol == (*itc).tcita.consultar_titol() and autor == (*itc).tcita.consultar_autor()){
			string ref = (*itc).referencia;
			cout << ref << endl;
			escriure_cita(ref);
			string a = (*itc).tcita.consultar_autor();
			string t = (*itc).tcita.consultar_titol();
			cout << a << ' ' << '"' << t << '"' << endl;
			}
		}
}

void Cites::escriure_cita_info(string titol, string autor){
	lcites.sort(comp);
	for(itc=lcites.begin(); itc!=lcites.end(); ++itc){
		if((*itc).tcita.consultar_titol() == titol and (*itc).tcita.consultar_autor() == autor){
			cout << (*itc).referencia << endl;
			escriure_cita((*itc).referencia);
			}
		}
}

void Cites::escriure_cites(){
	lcites.sort(comp);
	for (itc = lcites.begin(); itc != lcites.end(); ++itc){
		string s = (*itc).referencia;
		cout << s << endl;
		escriure_cita(s);
		string a = (*itc).tcita.consultar_autor();
		string t = (*itc).tcita.consultar_titol();
		cout << a << ' ' << '"' << t << '"' << endl;
		}
}
