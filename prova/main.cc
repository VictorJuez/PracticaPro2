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
using namespace std;

/** @brief Programa principal per la pràctica <em>Gestor de textos i cites</em>.
*/

string netejar(string s){
	s.erase(0,1);
    s.erase(s.size()-1,1);
    return s;
}


int main(){
    Cjt_Textos ctextos;
    Text text_triat;
    Cjt_Frases cfrases;
    Cites cites;
    Text text;
    string linia;
    ws(cin);
    getline(cin,linia);
    while (linia!="sortir"){
		cout << linia << endl;
        istringstream iss(linia);
        string op;
        iss >> op;
        if (op == "afegir"){
            iss >> op;
            if (op == "text"){				
				text.llegir(linia);			
				ctextos.afegir_text(text);	
            }
            else if (op == "cita"){
				if (ctextos.text_triat()){ 
					int x, y;
					iss >> x;
					iss >> y;
					if (x <= Y and y <= cfrases.numero_de_frases() and x > 0){
						if (not cites.existeix_cita(x,y,text_triat.consultar_titol()){
							cites.afegir_cita(x,y,text_triat);
						}
						else cout << "error"
					}
					else cout << "error" << endl;
				}
				else cout << "error" << endl;
            }
        }
        
        else if (op == "triar"){
			linia.erase(0,12);
			linia.erase(linia.size()-1, 1);
            ctextos.triar_text(linia);
            text_triat = ctextos.consultar_text_triat();
        }
        else if (op == "eliminar"){
            iss >> op;
            if (op == "text"){
				if (ctextos.text_triat()){		
					ctextos.eliminar_text();	
				}								
				else cout << "error" << endl;	
            }
            
            else if (op == "cita"){
                string referencia;
                iss >> referencia;
                if (cites.existeix_cita_ref(referencia)){
					cites.eliminar_cita(referencia);
				}
				else cout << "error" << endl;
            }
        }
        
        else if (op == "substitueix"){
			if(ctextos.text_triat()){
				string paraula1, paraula2;						
				iss >> paraula1;									
				paraula1 = netejar(paraula1);				
				iss >> op;											
				iss >> paraula2;										
				paraula2 = netejar(paraula2);
				text_triat.substituir_paraula(paraula1, paraula2);
				}
			else cout << "error" << endl;
			
			
        }
        else if (op == "textos"){
            string autor;
			autor = linia.erase(0,14);
			autor = autor.erase(autor.size()-1, 1);
            ctextos.imprimir_textos_autor(autor);
        }
        else if (op == "tots"){
            iss >> op;
            if (op == "textos"){
                iss >> op;
                if (op == "?")ctextos.imprimir_textos();
            }
            else if (op == "autors"){
                iss >> op;
                if (op == "?")ctextos.imprimir_tots_autors();
            }
        }
        else if (op == "info"){
            iss >> op;
            if (op == "cita"){
                string referencia;
                iss >> referencia;
                referencia.erase(0,1);	
                referencia.erase(referencia.size()-1,1);
                if (existeix_cita_ref(referencia)){
					cites.escriure_cita_ref(referencia);
				}
				else cout << "error" << endl;
            } 
            else if (op == '?'){
				if(ctextos.text_triat()){
					string autor = text_triat.consultar_autor();		
					string titol = text_triat.consultar_titol();		
					cout << autor << ' ' << '"' << titol << '"';		
					cfrases = text_triat.consultar_contingut();			
					int nfrases, nparaules;								
					nfrases = cfrases.numero_de_frases();				
					nparaules = cfrases.numero_de_paraules();			
					cout << ' ' << nfrases << ' ' << nparaules << endl;	
					cout << "Cites Associades:" << endl;
					cites.escriure_cita_info(string titol);
					}
				else cout << "error" << endl;
            }
            
        }
        else if (op == "autor"){
			if(ctextos.text_triat()){
				iss >> op;
				cout << text_triat.consultar_autor() << endl;
			}
			else cout << "error" << endl;
        }
        else if (op == "contingut"){
			if(ctextos.text_triat()){
				iss >> op;
				text_triat.consultar_contingut().escriure();
			}
			else cout << "error" << endl;
        }
        else if (op == "frases"){
			if (ctextos.text_triat()){
				int x, y;
				iss >> x;
				iss >> y;
				cfrases = text_triat.consultar_contingut();
				if (x <=y and y <= cfrases.numero_de_frases() and x > 0)
					cfrases = text_triat.consultar_contingut();
					cfrases.frases_xy(x,y);
				else cout << "error" << endl;
            else cout << "error" << endl;
            }
            
        }
        else if (op == "nombre"){
			if(ctextos.text_triat()){
				iss >> op;
				iss >> op;
				if (op == "frases"){
					iss >> op;
					int nfrases = text_triat.consultar_contingut().numero_de_frases();
					cout << nfrases << endl;
					}
				}
				else if (op == "paraules"){
					iss >> op;
					int nparaules = text_triat.consultar_contingut().numero_de_paraules();
					out << nparaules << endl;
					}
				}
			}
			else cout << "error" << endl;
        }
        else if (op == "taula"){
			if(ctextos.text_triat()){
				cfrases = text_triat.consultar_contingut();
				cfrases.taula_frequencies();
			}
			else cout << "error" << endl;
		}
		
		else if (op == "frases"){
			iss >> op;			
			if(op[0] != '"'){
				linia.erase(0,7);
				istringstream aux(linia);
				if(ctextos.text_triat()){
					cfrases = text_triat.consultar_contingut();
					int n, m;
					aux >> n;
					aux >> m;
					frases.frasesxy(n, m);
					}
				}
			else{
				linia.erase(0,8);
				linia.erase(linia.size()-1, 1);
				cout << linia << endl;
				if(ctextos.text_triat()){
					cfrases = text_triat.consultar_contingut();
					cfrases.conte_paraules(linia);
				}
			}
		}
		
		else if (op == "cites"){
			iss >> op;
			if (op == "autor"){
				string autor;
				iss >> autor;
				iss >> op;
				cites.escriure_cites_autor(autor);
				}
			else if (op == '?'){
				if (ctextos.text_triat()){
					cites.escriure_cita_triat();
				}
				else cout << "error" << endl;
        }
        
        else if (op == "totes"){
                cites.escriure_cites();
        }
        
        cout << endl;
        ws(cin);
        getline (cin,linia);
       
    }
    
}
