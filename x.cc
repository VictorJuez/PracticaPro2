#include "Frase.hh"
using namespace std;

int main(){
    Frase frase;
    frase.llegir();
    string hola = "hola";
    string adeu = "adeu";
    frase.substituir_paraula(hola,adeu);
    frase.escriure();
    cout << endl;
    int paraules = frase.num_de_paraules();
    cout<< paraules << endl;
}