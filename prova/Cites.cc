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
	while(n>0){
		int residu= n%10;
		char c = char(residu) + char('0');
		string ss;
		
		s.insert(s.size(), 1, c);
		n=n/10;
		}
	return s;
}

bool Cites::existeix_cita(int x, int y, string titol){
	list<cita>::iterator it;
	
	for(it=lcites.begin(); it!=lcites.end(); ++it){
		if((*it).tcita.consultar_titol() == titol){
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
	--it;
	if (not trobat) it=lcites.end();
}

void Cites::afegir_cita(int x, int y, Text text){
	text.consultar_frasesxy(x,y);
	string r;
	string autor = text.consultar_autor();
	
	istringstream iss(autor);
	string n, c;
	iss >> n;
	iss >> c;
	r.insert(0,1, n[0]);
	r.insert(1,1, c[0]);
	
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
	cout<< (*it).tcita.consultar_titol() << endl;
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

void Cites::escriure_cita_info(string titol){
	list<cita>::iterator it;
	for(it=lcites.begin(); it!=lcites.end(); ++it){
		if((*it).tcita.consultar_titol() == titol){
			cout << (*it).referencia << endl;
			escriure_cita((*it).referencia);
			}
		}
}

bool Cites::comp(const cita& a, const cita& b){
	string primer = a.referencia;
	primer.erase(2,primer.size()-1);
	string segon = b.referencia;
	segon.erase(2,segon.size()-1);
	if (primer != segon) return primer < segon;
	primer = a.referencia;
	primer.erase(0,2);
	int p = atoi(primer.c_str());
	segon = b.referencia;
	segon.erase(0,2);
	int s = atoi(segon.c_str());	
	return p < s;
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

void Cites::escriure_cita_triat(string titol){
	lcites.sort(comp);
	list <cita>::iterator it;
	for (it = lcites.begin(); it != lcites.end(); ++it){
		if (titol == (*it).tcita.consultar_titol()){
			string ref = (*it).referencia;
			cout << ref << endl;
			escriure_cita(ref);
			string a = (*it).tcita.consultar_autor();
			string t = (*it).tcita.consultar_titol();
			cout << a << ' ' << '"' << t << '"' << endl;
			}
		}
}
