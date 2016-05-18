#include "Cjt_Frases.hh"

Cjt_Frases::Cjt_Frases(){
	nparaules = 0;
}

bool Cjt_Frases::te_signe(string aux){
	char last = aux[aux.size()-1];
		if ((last < 'a' or last >'z') and (last < 'A' or last > 'Z')){
				return true;
				}
		return false;
}

char Cjt_Frases::guardar_signe(string aux){
	char last = aux[aux.size()-1];
		if (te_signe(aux)){
				return aux[aux.size()-1];
				}	
}

string Cjt_Frases::treure_signes(string aux){ //modificat
	aux.erase(aux.end()-1);
	return aux;
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

/*int Cjt_Frases::numero_de_frases() const{
	return vfrases.size();
}*/

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

bool Cjt_Frases::conte_paraula(string paraula){
	for(int i=0; i < vfrases.size(); ++i){
		list<string>::const_iterator it;
		for(it=vfrases[i].begin(); it != vfrases[i].end(); ++it){
			string aux = *it;
			
			if(te_signe(aux)){ //modificat
				aux=treure_signes(aux);
			}
			
			if(aux == paraula) return true;
			}
		}
	return false;
}

bool Cjt_Frases::conte_paraules(vector<string> paraules){
	for(int i=0; i<vfrases.size(); ++i){
		if(conte_paraules_plus(vfrases[i], paraules)) return true;
		}
	return false;
}

void Cjt_Frases::llegir() {    
    string paraula;
    cin >> paraula;
	list <string>::iterator it;
    while (paraula != "*****"){
		list <string> l ;
        it = l.begin();
        char fi = paraula[paraula.size()-1];
        while (fi != '.' and fi != '?' and fi != '!'){
			l.insert(it, paraula);
			++nparaules;
			cin >> paraula;
			fi = paraula[paraula.size()-1];
			}
		if (paraula != "*****"){
			l.insert(it,paraula);
			cin >> paraula;
			}
		vfrases.push_back(l);
        ++nparaules;
    }
}

void Cjt_Frases::escriure() const{
    bool primer = true;    
    list<string> ::const_iterator it;
    for (int i = 0; i < vfrases.size(); ++i){
		for (it = vfrases[i].begin(); it != vfrases[i].end(); ++it){
			if (primer){
				primer = false;
				cout << *it;
				}
			else cout << ' ' << *it;
			}
		}
	cout << endl;
}
