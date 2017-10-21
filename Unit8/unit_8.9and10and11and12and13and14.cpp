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
//}第9题

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
//}第十题

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
}第十一题*/

//其中的成员皆可被访问，所以是一个聚合类，不能在内部进行初始化(第十二题）

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
}第十三题*/

//第十四题 将参数定义为&引用：在使用时无需进行赋值，省去很多空间与时间。定义为const：在函数内部不允许对参数进行修改。