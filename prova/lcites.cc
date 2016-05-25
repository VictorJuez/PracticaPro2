#include "lcites.hh"
#include <stdlib.h>

Cites::Cites(){
	
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

void Cites::buscar_referencia(string s, list<cita>::iterator& it){
	bool trobat=false;
	for(it=lcites.begin(); not trobat and it!=lcites.end(); ++it){
		if((*it).referencia == s) trobat=true;
		}
	--it;
	if (not trobat) it=lcites.end();
}

void Cites::afegir_cita(int x, int y, Text text){
	text.consultar_contingut().consultar_frasesxy(x, y);
	string r;
	string autor = text.consultar_autor();
	
	istringstream iss(autor);
	string n, c;
	iss >> n;
	iss >> c;
	cout << n[0] << c[0] << endl;
	r.insert(0,1, n[0]);
	r.insert(1,1, c[0]);
	cout << "r ---> " << r << endl;
	
	bool trobat=false;
	for(int i=0; i<vref.size() and not trobat; ++i){
		if(vref[i].ref == r){
			trobat=true;
			++vref[i].contador;
			int aux = vref[i].contador;
			r= crear_ref(r, aux);
			}
		cout << "comparaaacio -------------> "<< vref[i].ref << ' ' << r << endl;
		}
	if (not trobat){
		sref saux;
		cout << "r ---->> " << r << endl;
		saux.ref = r;
		saux.contador=1;
		r=crear_ref(r, 1);
		vref.push_back(saux);
		}
	cout << vref.size() << "mida vref   ****" << endl;
	cout << "REFERENCIIIAA ----->" << r << endl;
		
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
