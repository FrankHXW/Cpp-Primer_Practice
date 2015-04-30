#include <iostream>
#include <iomanip>
#include<string>
#include<vector>
#include<initializer_list>

<<<<<<< HEAD
#include "CP5_ex7.h"

using namespace std;
#define _CRT_SECURE_NO_WARNINGS

int Account::period=10;
double Account::interestrate;
vector<double> Account::vec(period);



int main(int argc, char *argv[])
{
	Sales_data s1;

	Sales_data s2("asd");

	Sales_data s3("sdf", 10, 23);

//	Sales_data s4(cin);

	Screen myScreen;
	myScreen.move(4, 0).set('#').display(cout);
	cout << "\n";
	myScreen.display(cout);
	cout << "\n";

	string null_isbn("9-999");
	Sales_data item1(null_isbn);
	Sales_data item2="9-999";
	print(cout, item1);
	print(cout, item2);


	Account ac1;
	Account ac2;
	cout << ac1.period << ac2.period << endl;
	ac2.period = 20;
	cout << ac1.period << ac2.period << endl;
	return -1;
}

=======
using namespace std;
#define _CRT_SECURE_NO_WARNINGS

struct Sales_data{
	string isbn() const{ return bookNo; }
	Sales_data &combine(const Sales_data &);
	double avg_price() const;

	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

Sales_data& Sales_data::combine(const Sales_data &rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

double Sales_data::avg_price() const
{
	if (units_sold)
		return revenue / units_sold;
	else
		return 0;
}

istream &read(istream &is, Sales_data &item)
{
	double price =0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price*item.units_sold;
	return is;
}

ostream &print(ostream &os, const Sales_data &item)
{
	os << item.isbn() << " " << item.units_sold << " "
		<< item.revenue << " " << item.avg_price();
	return os;
}

struct Person{
	string nam() const{ return name; }
	string add() const{ return address;}
	string name;
	string address;
};

istream &read(istream is, Person &item)
{
	is >> item.name >> item.address;
	return is;
}

ostream &print(ostream os, const Person &item)
{
	os << item.name << " " << item.address;
	return os;
}

//int main(int argc, char *argv[])
//{
//	Sales_data total;
//	if (read(cin,total)){
//		Sales_data trans;
//		while (read(cin,trans))
//		{
//			if (total.isbn()== trans.isbn()){
//				total.combine(trans);
//			}
//			else{
//				print(cout,total);
//				total = trans;
//			}
//		}
//	}
//	else
//	{
//		cerr << " no data !" << endl;
//		return 0;
//	}
//	return -1;
//}

>>>>>>> 65120b9e16d40ae63156059aed2fa0b00eda3d67
















