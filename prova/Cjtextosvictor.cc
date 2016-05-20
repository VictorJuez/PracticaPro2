#include "cjtextosvictor.hh"

Cjt_Textos::Cjt_Textos(){
	triat=false;
}
void Cjt_Textos::crear_vfrase(string s, vector<string>& frase){
	istringstream iss(s);
	string op;
	iss >> op;
	while(iss) frase.push_back(op);
}

bool Cjt_Textos::trobar_paraules(vector<string> v, Text& t){
	vector <string> titol;
	crear_vfrase(t.consultar_titol(), titol);
	
	vector <string> autor;
	crear_vfrase(t.consultar_autor(), autor);
	
	vector <bool> vb(v.size(), 0);
	
	for(int i=0; i<v.size(); ++i){  //buscar al títol
		for(int j=0; j<titol.size() and not vb[i]; ++j){
			if(v[i] == titol[j]) vb[i] = true;
		}
	}
		
	for(int i=0; i<v.size(); ++i){  //buscar al autor
		for(int j=0; j<autor.size() and not vb[i]; ++j){
			if(v[i] == autor[j]) vb[i] = true;
		}
	}
	
	for(int i=0; i<v.size(); ++i){  //buscar al contingut
		if (not vb[i]){
			Cjt_Frases cfrases;
			cfrases= t.consultar_contingut();
			if(cfrases.conte_paraula(v[i])) vb[i]=true;
			}
	}
	
	for(int i=0; i<vb.size(); ++i){
		if (not vb[i]) return false;
		}
	return true;
}

void Cjt_Textos::triar_text(string& s){
	list<Text>::iterator it;
	bool b=false;
	bool b2=false;
	for(it=ctextos.begin(); it!=ctextos.end(); ++it){
		Text t=*it;
		//if(t.consultar_titol == s or t.consultar_autor == s) return true;
		vector <string> frase;
		crear_vfrase(s, frase);
		if(trobar_paraules(frase, t) and not b){
			b=true;
			it_triat=it;
			}
		else if (trobar_paraules(frase, t) and b) cout << "errror company "<< endl;
		}
}
