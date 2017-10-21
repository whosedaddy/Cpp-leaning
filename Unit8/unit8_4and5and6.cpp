#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

/*int main() {
	string ifile = "ifile.txt";
	vector<string> v;
	ifstream in(ifile);
	if (in) {
		string buf;
		while (getline(in, buf)) {
			v.push_back(buf);
		}
	}
	else {
		cerr << "can't open this file:" << ifile << endl;
	}
	if (in) {
		string buf;
		while (getline(in, buf, ' ')) {
			v.push_back(buf);
		}
	}
	in.close();
	return 0;
}*/

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

int main(int argc, char *argv[]) {
	Sales_data total;
	ifstream input(argv[1]);
	ofstream output(argv[2], ofstream::app);
	if (read(input, total)) {
		Sales_data trans;
		while (read(input, trans)) {
			if (total.isbn() == trans.isbn())
				total.combine(trans);
			else {
				print(output, total) << endl;
				total = trans;
			}
		}
		print(output, total) << endl;
	}
	else {
		cerr << "No data?" << endl;
	}
	return 0;
}