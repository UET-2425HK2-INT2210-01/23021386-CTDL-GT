#include <iostream>
using namespace std;
int main () {
	string s;
	getline (cin,s);
	string daonguoc = "";
	for (int i = s.length() - 1; i >= 0; i--) {
		daonguoc += s[i];
	}
	cout << daonguoc << endl;
	return 0;	
}
