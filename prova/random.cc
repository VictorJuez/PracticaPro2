// string::erase
#include <iostream>
#include <string>

using namespace std;

int main ()
{
	string s;
	cin >> s;
	cout << s.size()<< endl;
	s.erase(s.end()-1);
	cout << s << ' ' << s.size() << endl;
}
