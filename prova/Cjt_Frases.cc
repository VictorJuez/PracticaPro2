#include "Cjt_Frases.hh"

bool Cjt_Frases::te_signe(string aux){
	char last = aux[aux.size()-1];
		if ((last < 'a' or last >'z') and (last < 'A' or last > 'Z')){
				return true;
				}
		return false;
}

string Cjt_Frases::treure_signes(string aux){
	aux.erase(aux.end()-1);
	return aux;
}

char Cjt_Frases::guardar_signe(string aux){
	char last = aux[aux.size()-1];
		if (te_signe(aux)){
				return aux[aux.size()-1];
				}	
}

bool Cjt_Frases::conte_paraules_plus(list<string>& l, vector<string>& s){
	list<string>::iterator it;
	int cont=0;
	for(it=l.begin(); it!=l.end(); ++it){
		if((l.size()-cont) < s.size()) return false;
		string aux=*it;
		if(te_signe(aux)){ //modificat
			aux=treure_signes(aux);
		}
		if (aux==s[0]){
			bool b=false;
			for(int i=1; i<s.size() and not b; ++i){
				++it;
				string aux=*it;
				if(te_signe(aux)){ //modificat
				aux=treure_signes(aux);
					}
				if(aux != s[i]) b=true;
				if(i == s.size()-1) return true;
				}
			}
		++cont;
		}
	return false;
}

void Cjt_Frases::afegir(string& s){
	bool nova = false;
	for (int i = 0;not nova and (i < taula.size());++i){
		if (taula[i].paraula == s){
			taula[i].repeticions++;
			nova = true;
			}
		}
	if (not nova){
		freq p;
		p.paraula = s;
		p.repeticions = 1;
		taula.push_back(p);
		}
}

bool Cjt_Frases::ord(freq a,freq b){
	if (a.repeticions > b.repeticions) return true;
	else if (a.repeticions < b.repeticions) return false;
	else if (a.paraula.size() < b.paraula.size()) return true;
	else if (a.paraula.size() > b.paraula.size()) return false;
	return a.paraula < b.paraula;
}

Cjt_Frases::Cjt_Frases(){
	nparaules = 0;
}

void Cjt_Frases::substituir_paraula(string paraula1, string paraula2){
	list <list <string> >::iterator it;
	for(it = vfrases.begin(); it!=vfrases.end(); ++it){
		list<string>::iterator it1;
		for(it1=(*it).begin(); it1 !=(*it).end(); ++it1){
			string aux= *it1;
			if(te_signe(aux)){
				char c;
				c= guardar_signe(aux);
				aux=treure_signes(aux);
				if(aux == paraula1){
					*it1 = paraula2 + c;
					}
				}
			else if(aux == paraula1) *it1=paraula2;
			}
		}
	bool trobat = false;
	bool existent = false;
	int i;
	for (i = 0;not existent and i < taula.size(); ++i){
		if (taula[i].paraula == paraula2) existent = true;
		}
	--i;
	int j;
	for (j = 0;not trobat and j < taula.size(); ++j){
		if (taula[j].paraula == paraula1) {
			taula[j].paraula = paraula2;
			taula[j].repeticions += taula[i].repeticions;
			trobat = true;
			}
		}
	--j;
	if (existent){
		for (i; i < taula.size() - 1; ++i){
			taula[i] = taula[i+1];
			}
		taula.pop_back();
		}
	sort(taula.begin(),taula.end(),ord);
}

int Cjt_Frases::numero_de_paraules() const{
	return nparaules;
}

int Cjt_Frases::numero_de_frases() const{
	return vfrases.size();
}

bool Cjt_Frases::conte_paraula(string paraula){
	for(int i=0; i<taula.size(); ++i){
		if (paraula == taula[i].paraula) return true;
		}
	return false;
}

bool Cjt_Frases::conte_paraules(vector<string> paraules){
	list <list < string > >::iterator it;
	for( it=vfrases.begin(); it!=vfrases.end(); ++it){
		if(conte_paraules_plus(*it, paraules)) return true;
		}
	return false;
}

void Cjt_Frases::taula_frequencies(){
	int tamany = taula.size();
	for (int i = 0; i < tamany; ++i){
		cout << taula[i].paraula << ' ' << taula[i].repeticions << endl;
		}
}

void Cjt_Frases::llegir() {    
    string paraula;
    cin >> paraula;
	list <list <string> >::iterator it;
	it = vfrases.begin();
	list <string>::iterator it1;
    while (paraula != "****"){
		list <string> l ;
        it1 = l.begin();
        char fi = paraula[paraula.size()-1];
        while (fi != '.' and fi != '?' and fi != '!'){
			l.insert(it1, paraula);
			++nparaules;
			if (te_signe(paraula)){
				paraula = treure_signes(paraula);
				afegir(paraula);
				}
			else afegir(paraula);
			cin >> paraula;
			fi = paraula[paraula.size()-1];
			}
            
		if (paraula != "****"){
			l.insert(it1,paraula);
			if (te_signe(paraula)){
				paraula = treure_signes(paraula);
				afegir(paraula);
				}
			else afegir(paraula);
			cin >> paraula;
			}
		vfrases.insert(it,l);
        ++nparaules;
    }
    sort(taula.begin(),taula.end(),ord);
}

void Cjt_Frases::escriure() const{
    bool primer = true;    
    list<string>::const_iterator it1;
    list <list <string> >::const_iterator it;
    for (it = vfrases.begin(); it != vfrases.end(); ++it){
		list <string> l1 = (*it);
		for (it1 = l1.begin(); it1 != l1.end(); ++it1){
			string aux = (*it1);
			if (primer){
				primer = false;
				cout << aux;
				}
			else cout << ' ' << aux;
			}
		}
	cout << endl;
}
