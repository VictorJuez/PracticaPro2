#include <iostream>
#include <string>
#include <sstream>
#include "Cjt_Frases.hh"

using namespace std;
bool jaja(string& exp, Cjt_Frases frase){
	cout << exp << endl;
	char signe;
	if (exp[0] == '{' and exp[exp.size()-1] == '}'){
		/*exp.erase(0,1);
		exp.erase(exp.size()-1, 1);
		istringstream iss(exp);
		string paraula;
		iss >> paraula;
		bool b = true;
		while(b and iss){
			if(not frase.conte_paraula(paraula)) b=false;
			iss >> paraula;
			}
		return b;*/
		}
	else{
		string esq, dre;
		int cont = 0;
		bool t = true;
		for (int i = 0; i < exp.size(); ++i){
			if (t) esq.insert(esq.end(),1,exp[i]);
			else dre.insert(dre.end(),1,exp[i]);
			
			if (exp[i] == '(') ++cont;
			else if (exp[i] == ')') --cont;
			
			if (cont == 1 and (exp[i] == '&' or exp[i] == '|')){
				t = false;
				signe = exp[i];
			}
		}
		
		esq.erase(0,1);
		for(int i=esq.size()-1; esq[i]!='}' and esq[i]!=')'; --i){
			esq.erase(esq.end()-1);
			}

		while(dre[0]!='(' and dre[0]!='{'){
			dre.erase(dre.begin());
			}
		
		dre.erase(dre.size()-1,1);
		

		if(signe == '&'){
			if(jaja(esq,frase) and jaja(dre,frase)) return true;
			else return false;
			}
		else if(signe == '|'){
			if(jaja(esq,frase) or jaja(dre,frase)) return true;
			else return false;
			}
			
		//esq.erase(esq.size()-2, 2);
		//dre.erase(0,1);
		cout << esq << " esquerra " << endl;
		cout << dre << " dreta " << endl;
		}
}

/*bool no_te_simbol(string& exp, Cjt_Frases& frase){
	//cout << exp << endl;
	if (exp[0] == '{' and exp[exp.size()-1] == '}'){
		exp.erase(0,1);
		exp.erase(exp.size()-1, 1);
		istringstream iss(exp);
		string paraula;
		iss >> paraula;
		bool b = true;
		while(b and iss){
			if(not frase.conte_paraula(paraula)) b=false;
			iss >> paraula;
			}
		return b;
		}
	else{
		string esq, dre;
		int cont = 0;
		bool t = true;
		for (int i = 0; i < exp.size(); ++i){
			if (t) esq.insert(esq.end(),1,exp[i]);
			else dre.insert(dre.end(),1,exp[i]);
			
			if (exp[i] == '(') ++cont;
			else if (exp[i] == ')') --cont;
			
			if (cont == 1 and (exp[i] == '&' or exp[i] == '|')){
				t = false;
			//cout << "hola" << endl;
			}
		}
		esq.erase(0,1);
		esq.erase(esq.size()-2, 2);
		dre.erase(0,1);
		dre.erase(dre.size()-1,1);
		
		no_te_simbol(esq);
		no_te_simbol(dre);
		cout << esq << ' ' << dre << endl;
		}
}*/


int main(){
	//string linia;
   // ws(cin);
    //getline(cin,linia);
	string s = "(({night wolf} | {When}) | ({casa} & {taula}))";
	Cjt_Frases frase;
	frase.llegir();
	bool t = jaja(s, frase);
	cout << t << endl;
	}
