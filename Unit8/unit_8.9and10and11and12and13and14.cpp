#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;

//istream& str(istream &a) {
//	string sent;
//	while (getline(a, sent)) {
//		cout << sent << endl;
//		a.clear();
//	}
//	return a;
//}

//int main() {
//	string s = "hello world!!!";
//	istringstream re(s);
//	str(re);
//}��9��

//int main() {
//	vector<string> str;
//	string s;
//	string o;
//	string p;
//	ifstream input("file1");
//	while (getline(input, s)) {
//		str.push_back(s);
//	}
//	input.close();
//	for (auto a : str) {
//		istringstream in(a);
//		while (in >> o) {
//			p = p+o+" ";
//		}
//	}
//	cout << p;
//}��ʮ��

/*struct PersonalInfo {
	string name;
	vector<string> numbers;
};

int main() {
	string line, word;
	vector<PersonalInfo> person;
	istringstream record;
	while (getline(cin, line) && line != "") {
		PersonalInfo people;
		record.clear();
		record.str(line);
		record >> people.name;
		while (record >> word) {
			people.numbers.push_back(word);
		}
		person.push_back(people);
	}
}��ʮһ��*/

//���еĳ�Ա�Կɱ����ʣ�������һ���ۺ��࣬�������ڲ����г�ʼ��(��ʮ���⣩

/*struct PersonalInfo {
	string name;
	vector<string> numbers;
};

int main() {
	string line, word;
	vector<PersonalInfo> person;
	istringstream record;
	fstream in("tele_book");
	while (getline(in, line) && line != "") {
		PersonalInfo people;
		record.clear();
		record.str(line);
		record >> people.name;
		while (record >> word) {
			people.numbers.push_back(word);
		}
		person.push_back(people);
	}
	for (int i = 0; i < person.size();i++) {
		for (auto a : person[i].numbers) {
			cout << person[i].name << " " << a << endl;
		}
	}
}��ʮ����*/

//��ʮ���� ����������Ϊ&���ã���ʹ��ʱ������и�ֵ��ʡȥ�ܶ�ռ���ʱ�䡣����Ϊconst���ں����ڲ�������Բ��������޸ġ�