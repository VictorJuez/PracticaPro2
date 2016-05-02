#include <sstream>
#include <string>
#include <iostream>
using namespace std;
int main(){
	string linia, m;
	getline(cin,linia);
	istringstream iss(linia);
	while (iss >> m) cout << m;
}
