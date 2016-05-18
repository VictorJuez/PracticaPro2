/**
 * @mainpage Practica Pro2.
S'introdueixen les classes <em>Frase</em>, <em>Cjt_Frases</em>, <em>Text</em>, <em>Cjt_Textos</em> i <em>Cites</em> .

Només es documenten elements públics.
*/

/** @file main.cc
    @brief Programa principal per la pràctica <em>Gestor de textos i cites</em>.
*/


#include <sstream>
#include <string>
#include <iostream>
#include "Cjt_Textos.hh"
#include "Frases.hh"
#include "Cjt_Frases.hh"
#include "Cites.hh"
#include "Text.hh"

using namespace std;

/** @brief Programa principal per la pràctica <em>Gestor de textos i cites</em>.
*/
int main(){
    Cjt_Textos conjunt_textos;
    Text text, text_triat;
    Cjt_Frases conjunt_frases;
    Frase frase;
    Cites cites;
       
    string linia;
    getline(cin,linia,);
    while (linia!="sortir"){
        istringstream iss(linia);
        string op;
        iss >> op;
        if (op == "afegir"){
            iss >> op;
            if (op == "text"){
                text.llegir(iss);
                conjunt_textos.afegir_text(text);
            }
            else if (op == "cita"){
                int x, y;
                iss >> x;
                iss >> y;
                cites.afegir_cita(x,y,text_triat);
            }
            else cout << "Funcio incorrecte" << endl;
        }
        else if (op == "triar"){
            iss >> op;
            vector <string> paraules;
            while(iss >> op){
                paraules.push_back(op);
            }
            conjunt_textos.triar_text(paraules);
        }
        else if (op == "eliminar"){
            iss >> op;
            if (op == "text"){
                conjunt_textos.eliminar_text();
            }
            else if (op == "cita"){
                string referencia;
                iss >> referencia;
                cites.eliminar_cita(referencia);
            }
            else cout << "Funcio incorrecte" << endl;
        }
        else if (op == "substitueix"){
            string paraula1, paraula2;
            iss >> paraula1;
            iss >> paraula2;
            text_triat.substituir_paraules(paraula1,paraula2);
        }
        else if (op == "textos"){
            string autor;
            iss >> autor;
            conjunt_textos.imprimir_textos_autor(autor);
        }
        else if (op == "tots"){
            iss >> op;
            if (op == "textos"){
                iss >> op;
                if (op != '?') cout << "Error" << endl;
                else conjunt_textos.imprimir_textos();
            }
            else if (op == "autors"){
                iss >> op;
                if (op != '?') cout << "Error" << endl;
                else conjunt_textos.imrpimir_tots_autors();
            }
        }
        else if (op == "info"){
            is >> op;
            if (op == "cita"){
                string referencia;
                iss >> referencia;
                cites.escriure_cita(referencia);
            }
            else if (op == '?'){
                string autor = text_triat.consultar_autor();
                string titol = text_triat.consultar_titol();
                cout << autor << ' ' << titol << ' ';
                Cjt_frases frases;
                frases = text_triat.consultar_contingut();
                int nfrases, nparaules;
                nfrases = frases.numero_de_frases();
                nparaules = frases.numero_de_paraules();
                cout << autor << ' ' << titol << ' ' << nfrases << ' ' << nparaules << endl;
            }
            else cout << "Error" << endl;
        }
        else if (op == "autor"){
            is >> op;
            if (op != '?') cout << "Error" << endl;
            else cout << text_triat.consultar_autor() << endl;
        }
        else if (op == "contingut"){
            is >> op;
            if (op != '?') cout << "Error" << endl;
            else text_triat.consultar_contingut.escriure();
        }
        else if (op == "frases"){
            int x, y;
            iss >> x;
            iss >> y;
            iss >> op;
            if (op != '?') cout << "Error" << endl;
            else{
                Cjt_frases frases = text_triat.consultar_contingut();
                Cjt_frases aux = frases.frases_xy(x,y);
                aux.escriure();
            }
            
        }
        else if (op == "nombre"){
            iss >> op;
            if (op == "frases"){
                iss >> op;
                if (op != '?') cout << "Error" << endl;
                else{
                    int nfrases = text_triat.consultar_contingut.numero_de_frases();
                    cout << nfrases << endl;
                }
            }
            else if (op == "paraules"){
                iss >> op;
                if (op != '?') cout << "Error" << endl;
                else{
                    int nparaules = text_triat.consultar_contingut.numero_de_paraules();
                    cout << nparaules << endl;
                }
            }
        }
        else if (op == "taula"){
            iss >> op;
            if (op == "de"){
                iss >> op;
                if (op == "frequencies"){
                    iss >> op;
                    if (op == '?'){
                        Cjt_frases frases = text_triat.consultar_contingut();
                        frases.escriure_taula_frequencies();
                    }
                    else cout << "Error" < endl;
                }
                else cout << "Error" < endl;
            }
            else cout << "Error" < endl;
        }
        else if (op == "cites"){
            iss >> op;
            if (op == "autor"){
                string autor;
                iss >> autor;
                cites.escriure_cites_autor(autor);
            }
            else if (op == '?'){
                cites.escriure_cita_triat();
            }
            else cout << "Error" << endl;
        }
        else if (op == "totes"){
            iss >> op;
            if (op != 'cites') cout << "Error" << endl;
            else{
                iss >> op;
                if (op == '?')cites.escriure_cites();
                else cout << "Error" << endl;
            }
        }
        else if (op == "eliminar"){
            iss >> op;
            if (op == "cita"){
                string referencia;
                iss >> referencia;
                cites.eliminar_cita(referencia);
            }
            else cout << "Error" << endl;
        }
        else cout << "Error" << endl;
        getline (cin,linia);
        
    }
    
}
