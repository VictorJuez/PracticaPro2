#include "Cites.hh"
#include <list>

bool Cites::comp(const cita& a, const cita& b){
	string primer = a.referencia;
	primer.erase(2,primer.size()-1);
	string segon = b.referencia;
	segon.eares(2,segon.size()-1);
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
	list <cita>::const_iterator it;
	for (it = lcites.begin(); it != lcites.end(); ++it){
		string s = (*it).referencia;
		cout << s << endl;
		escriure_cita(s);
		string a = (*it).tcita.consultar_autor();
		string t = (*it).tcita.consultar_titol();
		cout << a << ' ' << t << endl;
		}
}

void Cites::escriure_cita_triat(string titol){
	lcites.sort(comp);
	list <cita>::const_iterator it;
	for (it = lcites.begin(); it != lcites.end(); ++it){
		if (titol == (*it).tcita.consultar_autor()){
			string ref = (*it).referencia;
			cout << ref << endl;
			escriure_cita(ref);
			string a = (*it).tcita.consultar_autor();
			string t = (*it).tcita.consultar_titol();
			cout << a << ' ' << t << endl;
			}
		}
}
