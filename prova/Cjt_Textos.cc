#include "Cjt_Textos.hh"

bool Cjt_Textos::ordena(aut_tit a,aut_tit b){
	if (a.autor != b.autor) return a.autor < b.autor;
	return a.titol < b.titol;
}

Cjt_Textos::Cjt_Textos(){
	triat = false;
	it = ctextos.end();
	}



void Cjt_Textos::afegir_text(const Text& text){
	list <Text>::iterator fi;
	fi = ctextos.end();
	ctextos.insert(fi,text);
	}
	
void Cjt_Textos::eliminar_text(){
	it = ctextos.erase(it);
	triat = false;
	}

bool Cjt_Textos::text_triat(){
	return triat;
	}
	
Text Cjt_Textos::consultar_text_triat(){
	Text text = (*it);
	return text;
	}

void Cjt_Textos::imprimir_textos(){
	vector <aut_tit> v (ctextos.size());
	list <Text>::iterator it;
	int i = 0;
	for (it = ctextos.begin(); it != ctextos.end(); ++it){
		v[i].autor = (*it).consultar_autor();
		v[i].titol = (*it).consultar_titol();
		++i;
		}
	sort(v.begin(), v.end(),ordena);
	for (int i = 0; i < v.size();++i){
		cout << v[i].autor << ' ' << '"' << v[i].titol << '"' << endl;
		}
	}

