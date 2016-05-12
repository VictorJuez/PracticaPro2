#include "Cjt_Frases.hh"

Cjt_Frases::Cjt_Frases(){
    nparaules = 0;
}
/*
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

void taula_frequencies() const; */

void Cjt_Frases::llegir() {	
    string paraula;
    cin >> paraula;
    int i = 0;
    while (paraula != "*****"){
        vector <string> v(0);
        vfrases.push_back(v);
        while (paraula[paraula.size()-1] != '.' and paraula[paraula.size()-1] != '?' and paraula[paraula.size()-1] != '!'){
            vfrases[i].push_back(paraula);
            ++nparaules;
            cin >> paraula;
        }
        if (paraula != "*****"){
            vfrases[i].push_back(paraula);
            cin >> paraula;
        }
        ++nparaules;
        ++i;
    }
}

void Cjt_Frases::escriure() const{
    bool primer = true;
    for (int i = 0; i < vfrases.size(); ++i){
        for (int j = 0; j < vfrases[i].size(); ++j){
            if (primer){
                primer = false;
                cout << vfrases[i][j];
            }
            else cout << ' ' << vfrases[i][j];
        }
    }
    cout << endl;
}
