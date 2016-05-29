#include "Cites.hh"
#include <stdlib.h>

Cites::Cites(){
	
}

Cjt_Frases Cites::consultar_contingut(string r){
	list<cita>::iterator it;
	buscar_referencia(r, it);
	return (*it).tcita.consultar_contingut();
}

string Cites::crear_ref(string s, int n){
	string Result;         
	ostringstream convert;  
	convert << n;     
	Result = convert.str();
	return s + Result;
}

bool Cites::existeix_cita(int x, int y, string titol, string autor){
	list<cita>::iterator it;
	
	for(it=lcites.begin(); it!=lcites.end(); ++it){
		if((*it).tcita.consultar_titol() == titol and (*it).tcita.consultar_autor() == autor){
			if(((*it).inici == x)and ((*it).inici + (*it).tcita.consultar_contingut().numero_de_frases()-1 == y)) return true;
			}
		}
	return false;
}

bool Cites::existeix_cita_ref(string referencia){
	list<cita>::iterator it;
	buscar_referencia(referencia, it);
	if (it == lcites.end()) return false;
	else return true;
}

void Cites::buscar_referencia(string s, list<cita>::iterator& it){
	bool trobat=false;
	for(it=lcites.begin(); not trobat and it!=lcites.end(); ++it){
		if((*it).referencia == s) trobat=true;
		}
	if (lcites.size() != 0)--it;
	if (not trobat) it=lcites.end();
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
	
	list<cita>::iterator it = lcites.end();
	lcites.insert(it, xcita);
	lcites.sort(comp);
}

void Cites::eliminar_cita(string& referencia){
	list<cita>::iterator it;
	buscar_referencia(referencia, it);
	it=lcites.erase(it);
}

void Cites::escriure_cita(string& referencia){
	list<cita>::iterator it;
	buscar_referencia(referencia, it);
	Cjt_Frases cfrases= (*it).tcita.consultar_contingut();
	
	int aux=(*it).inici;
	for(int i=1; i<=cfrases.numero_de_frases(); ++i, ++aux){
		cout << aux << ' ';
		cfrases.imprimir_nfrase(i);
		}
}
void Cites::escriure_cita_ref(string& referencia){
	list<cita>::iterator it;
	buscar_referencia(referencia, it);
	cout << (*it).tcita.consultar_autor() << ' ';
	cout << '"' << (*it).tcita.consultar_titol()<< '"' << endl;
	cout << (*it).inici << '-' << (*it).inici + (*it).tcita.consultar_contingut().numero_de_frases()-1 << endl;
	escriure_cita(referencia);
	
}

void Cites::escriure_cites_autor(string& autor){
	lcites.sort(comp);
	list<cita>::iterator it;
	for(it=lcites.begin(); it!=lcites.end(); ++it){
		if((*it).tcita.consultar_autor() == autor){
			cout <<(*it).referencia << endl;
			escriure_cita((*it).referencia);
			cout << '"' << (*it).tcita.consultar_titol() << '"' << endl;
			}
		}
}

void Cites::escriure_cita_info(string titol, string autor){
	lcites.sort(comp);
	list<cita>::iterator it;
	for(it=lcites.begin(); it!=lcites.end(); ++it){
		if((*it).tcita.consultar_titol() == titol and (*it).tcita.consultar_autor() == autor){
			cout << (*it).referencia << endl;
			escriure_cita((*it).referencia);
			}
		}
}

bool Cites::comp(const cita& a, const cita& b){
	string primer = a.referencia;
	string primer_lletres;
	for (int i = 0; i < primer.size(); ++i){
		if ((primer[i] >= 'a' and primer[i] <= 'z') or (primer[i] > 'A' and primer[i] <= 'Z')){
			primer_lletres.insert(primer_lletres.end(),1,primer[i]);
			}
		}
	
	string segon = b.referencia;
	string segon_lletres;
	for (int i = 0; i < segon.size(); ++i){
		if ((segon[i] >= 'a' and segon[i] <= 'z') or (segon[i] > 'A' and segon[i] <= 'Z')){
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

void Cites::escriure_cites(){
	lcites.sort(comp);
	list <cita>::iterator it;
	for (it = lcites.begin(); it != lcites.end(); ++it){
		string s = (*it).referencia;
		cout << s << endl;
		escriure_cita(s);
		string a = (*it).tcita.consultar_autor();
		string t = (*it).tcita.consultar_titol();
		cout << a << ' ' << '"' << t << '"' << endl;
		}
}

void Cites::escriure_cita_triat(string titol, string autor){
	lcites.sort(comp);
	list <cita>::iterator it;
	for (it = lcites.begin(); it != lcites.end(); ++it){
		if (titol == (*it).tcita.consultar_titol() and autor == (*it).tcita.consultar_autor()){
			string ref = (*it).referencia;
			cout << ref << endl;
			escriure_cita(ref);
			string a = (*it).tcita.consultar_autor();
			string t = (*it).tcita.consultar_titol();
			cout << a << ' ' << '"' << t << '"' << endl;
			}
		}
}

