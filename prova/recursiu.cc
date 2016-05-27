#include <iostream>
#include <string>
#include <sstream>

using namespace std;

bool no_te_simbol(string& exp/*, vector<list<string> >& lfrase*/){
	//cout << exp << endl;
	if (exp[0] == '{' and exp[exp.size()-1] == '}'){
		/*exp.erase(0,1);
		exp.erase(exp.size()-1, 1);
		istringstream iss(exp);
		string paraula;
		iss >> paraula;
		bool b = true;
		while(b and iss){
			if(not conte_paraula(paraula)) b=false;
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
}


int main(){
	//string linia;
   // ws(cin);
    //getline(cin,linia);
	string s = "(({night wolf} | {When}) | ({casa} & {taula}))";
	bool t = no_te_simbol(s);
	}
