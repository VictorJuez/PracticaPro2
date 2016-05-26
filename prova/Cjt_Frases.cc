#include "Cjt_Frases.hh"

void Cjt_Frases::imprimir_frase(list<string>& l) const{
	bool primer=true;
	list<string>::const_iterator it;
	for(it=l.begin(); it!=l.end(); ++it){
		if(primer){
			cout << *it;
			primer=false;
			}
		else cout << ' ' << *it;
		}
	cout << endl;
}

void Cjt_Frases::crear_vfrase(string s, vector<string>& frase){
	istringstream iss(s);
	string op;
	iss >> op;
	while(iss){
		frase.push_back(op);
		iss >> op;
		}
}


bool Cjt_Frases::te_signe(string aux){
	char last = aux[aux.size()-1];
		if ((last < 'a' or last >'z') and (last < 'A' or last > 'Z') and (last < '0' or last > '9')){
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
			if(s.size() == 1) return true;
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
	for(int i=0; i<vfrases.size(); ++i){
		list<string>::iterator it;
		for(it=vfrases[i].begin(); it !=vfrases[i].end(); ++it){
			string aux= *it;
			if(te_signe(aux)){
				char c;
				c= guardar_signe(aux);
				aux=treure_signes(aux);
				if(aux == paraula1){
					*it = paraula2 + c;
					}
				}
			else if(aux == paraula1) *it=paraula2;
			}
		}
}

int Cjt_Frases::numero_de_paraules() const{
	return nparaules;
}

int Cjt_Frases::numero_de_frases() const{
	return vfrases.size();
}

bool Cjt_Frases::conte_paraula(string paraula){
	for(int i=0; i < vfrases.size(); ++i){
		list<string>::const_iterator it;
		for(it=vfrases[i].begin(); it != vfrases[i].end(); ++it){
			string aux = *it;
			
			if (te_signe(aux)){
				aux=treure_signes(aux);
				}
			if(aux == paraula) return true;
			}
		}
	return false;
}

void Cjt_Frases::conte_paraules(string paraules){
	vector<string> v;
	crear_vfrase(paraules, v);
	for(int i=0; i<vfrases.size(); ++i){
		if(conte_paraules_plus(vfrases[i], v)) {
			cout << i+1 << ' ';
			imprimir_frase(vfrases[i]);
		}
	}
}

void Cjt_Frases::taula_frequencies(){
	list <string>::iterator it;
	for (int i = 0; i < vfrases.size(); ++i){
		for (it = vfrases[i].begin(); it != vfrases[i].end();++it){
			string paraula = (*it);
			if (te_signe(paraula)){
				paraula = treure_signes(paraula);
				afegir(paraula);
				}
			else afegir(paraula);
			}
		}
	sort(taula.begin(),taula.end(),ord);
	int tamany = taula.size();
	for (int i = 0; i < tamany; ++i){
		cout << taula[i].paraula << ' ' << taula[i].repeticions << endl;
		}
}

void Cjt_Frases::llegir() {  
	vfrases.resize(0);
	nparaules = 0;  
    string paraula;
    cin >> paraula;
	list <string>::iterator it;
    while (paraula != "****"){
		list <string> l;
        it = l.begin();
        char fi = paraula[paraula.size()-1];
        while (fi != '.' and fi != '?' and fi != '!' or (fi >= '0' and fi <= '9')){
			l.insert(it, paraula);
			++nparaules;
			cin >> paraula;
			fi = paraula[paraula.size()-1];
			}
            
		if (paraula != "****"){
			l.insert(it,paraula);
			cin >>paraula;
			}
		vfrases.push_back(l);
        ++nparaules; 
    }
}

void Cjt_Frases::consultar_frasesxy(int n, int m) {
	vector< list<string> > aux;
	for(int i=n-1; i<m; ++i){
		aux.push_back(vfrases[i]);
		}
	vfrases.resize(0);
	vfrases = aux;
}

void Cjt_Frases::imprimir_nfrase(int n){
	imprimir_frase(vfrases[n-1]);
}

void Cjt_Frases::frasesxy(int n, int m) const{
	list<string>::const_iterator it;
    for (int i = n-1; i < m; ++i){
		cout << i+1;
		for (it = vfrases[i].begin(); it != vfrases[i].end(); ++it){
			 cout << ' ' << *it;
			}
		cout << endl;
		}
}

void Cjt_Frases::escriure() const{    
    list<string>::const_iterator it;
    for (int i = 0; i < vfrases.size(); ++i){
		cout << i+1;
		for (it = vfrases[i].begin(); it != vfrases[i].end(); ++it){
			 cout << ' ' << *it;
			}
		cout << endl;
		}
}
