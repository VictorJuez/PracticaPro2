#include "Cjt_Frases.hh"
using namespace std;

int main(){
    Cjt_Frases cjtfrase;
    cjtfrase.llegir();
    cjtfrase.escriure();
    string s;
    s="hola";
    
    cout << cjtfrase.conte_paraula(s) << endl;
    
    vector<string> vs(3);
    
    cin >> vs[0] >> vs[1] >> vs[2];
    
    cout << cjtfrase.conte_paraules(vs);
    
    string ss;
    
    cin>> ss;
    
    cjtfrase.substituir_paraula("hola", ss);
    
    cjtfrase.escriure();
}

