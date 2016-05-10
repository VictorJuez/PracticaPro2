#include "Frase.hh"

Frase::Frase(){
    numero_de_paraules = 0;
}

int Frase::num_de_paraules() const{
    return numero_de_paraules;  
}

void Frase::substituir_paraula(string& paraula1, string& paraula2){
    for (int i = 0; i < numero_de_paraules; i++){
        char fi = frase[i][frase[i].size()-1];
        char principi = frase[i][0];
        if (frase[i] == paraula1){
            frase[i] = paraula2;
        }
        else if(not (fi >= 'a' and fi <= 'z') and not(fi >= 'A' and fi <= 'Z')){
            string aux;
            for (int j = 0; j < frase[i].size() - 1; ++j){
                aux.push_back(frase[i][j]);
            }
            if (aux == paraula1){
                frase[i] = paraula2 + fi;
            }
        }
       /* else if(not (principi >= 'a' and principi <= 'z') and not(principi >= 'A' and principi <= 'Z')){
            string aux;
            for (int j = 2; j < frase[i].size(); ++j){
                aux.push_back(frase[i][j]);
            }
            if (aux == paraula1){
                frase[i] = principi + paraula2;
            }
        }*/
    }
}

void Frase::llegir(){
    string paraula;
    cin >> paraula;
    while (paraula[paraula.size()-1] != '.' and paraula[paraula.size()-1] != '?' and paraula[paraula.size()-1] != '!'){
        frase.push_back(paraula);
        ++numero_de_paraules;
        cin >> paraula;
    }
    frase.push_back(paraula);
    ++numero_de_paraules;
}

void Frase::escriure() const{
    bool primer = true;
    for (int i = 0; i < frase.size(); i++){
        if (primer){
            cout << frase[i];
            primer = false;
        }
        else cout << ' ' << frase[i];
    }
}
