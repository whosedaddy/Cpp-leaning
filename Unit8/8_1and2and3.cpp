#include <iostream>
#include <string>
using namespace std;

istream& str(istream &a) {
	string sent;
	while (a >> sent) {
		cout << sent << endl;
		a.clear();
	}
	return a;
}

int main() {
	//istream &a = cin;
	str(cin);
	return 0;
}
//when the cin get eofbit, failbit or badbit, the circulation will end.