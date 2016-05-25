#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

int main(){
	string s = "ef1234567";
	s.erase(0,2);/*
	char c;
	long int num = 0;
	for (int i = 0; i < s.size(); ++i){
		c = s[i];
		num = int(c - char('0')) + num*10;
		}

	 cout << num << endl;*/
	 int value = atoi(s.c_str());
	 cout << value << endl;
}
