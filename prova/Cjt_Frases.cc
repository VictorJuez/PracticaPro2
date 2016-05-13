#include "Cjt_Frases.hh"
#include "Frase.hh"

Cjt_Frases::Cjt_Frases(){
	nparaules = 0;
}

void Cjt_Frases::llegir() {    
    string paraula;
    cin >> paraula;
	list <string>::iterator it;
    int i = 0;
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
    ++i;
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
