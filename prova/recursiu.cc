#include <iostream>
#include <string>
#include <sstream>

using namespace std;

bool no_te_simbol(string& exp/*, list <string>& lfrase*/){
	cout << exp << endl;
	if (exp[0] == '{' and exp[exp.size()-1] == '}'){
		return true;
		}
	else{
		string esq, dre;
		int cont = 0;
		bool t = true;
		cout << exp.size() << endl;
		for (int i = 0; i < exp.size(); ++i){
			cout << exp[i] << endl;
			if (t) esq.insert(esq.end(),1,exp[i]);
			else dre.insert(dre.end(),1,exp[i]);
			if (exp[i] == '(') ++cont;
			else if (exp[i] == ')') --cont;
			if (cont == 1 and (exp[i] == '&' or exp[i] == '|')){
				t = false;
			}
		cout << esq << " esquerre" << endl;
		cout << dre << "dreta" << endl;
		return true;
		//return no_te_simbol(esq);
		//return no_te_simbol(dre);
		
		}
	}
}


int main(){
	//string linia;
   // ws(cin);
    //getline(cin,linia);
	string s = "(({casa} & {taula}) | ({night wolf} | {When}))";
	bool t = no_te_simbol(s);
	}
