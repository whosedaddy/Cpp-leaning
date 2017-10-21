#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

struct Sales_data {
	string isbn() const { return bookNo; }
	Sales_data& combine(const Sales_data&);
	double avg_price() const;
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};
Sales_data add(const Sales_data&, const Sales_data&);
ostream &print(ostream&, const Sales_data&);
istream &read(istream&, Sales_data&);

double Sales_data::avg_price() const {
	if (units_sold)
		return revenue / units_sold;
	else return 0;
}

istream &read(istream &is, Sales_data &item) {
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}

ostream &print(ostream &os, const Sales_data &item) {
	os << item.isbn() << " " << item.units_sold << " "
		<< item.revenue << " " << item.avg_price();
	return os;
}

Sales_data& Sales_data::combine(const Sales_data &rhs) {
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}

struct PersonalInfo {
	string name;
	vector<string> numbers;
};

int main(){
	/*argc = 5;
	argv[0] = "prog";
	argv[1] = "-d";
	argv[2] = "-o";
	argv[3] = "ofile";
	argv[4] = "data0";
	argv[5] = 0;
	ifstream input(argv[1]);
	ofstream output(argv[2]);
	Sales_data total;
	if (read(input, total)) {
		Sales_data trans;
		while (read(input, trans)) {
			if (total.isbn() == trans.isbn()) {
				total.combine(trans);
			}
			else {
				print(output, total) << endl;
				total = trans;
			}
		}
		print(output, total) << endl;
	}
	else
		cerr << "no data?!" << endl;
	string ifile = "ifile.txt";
	ifstream in(ifile);
	ofstream out;
	out.open(ifile);
	if (out) { cout << 1; }
	in.close();
	in.open(ifile+"2");
	out << ifile;*/
	

	/*ofstream output("file1", ofstream::trunc);
	output << "new, message";
	return 0;*/

	string line, word;
	vector<PersonalInfo> person;
	while (getline(cin,line) && line != "") {
		PersonalInfo people;
		istringstream record(line);
		record >> people.name;
		while (record >> word) {
			people.numbers.push_back(word);
		}
		person.push_back(people);
	}
}