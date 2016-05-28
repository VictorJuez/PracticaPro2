#include <iostream>
#include "Cjt_Frases.hh"
using namespace std;

int main(){
	Cjt_Frases cjtfrases;

	cjtfrases.llegir();
	cjtfrases.escriure();

	string s = "Hola, com estas filla. Primer abansa kaak. KEEk.";	
	
	cjtfrases.substituir_cjtfrases(s);
	
	cjtfrases.escriure();
}
