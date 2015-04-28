#include <iostream>
#include <iomanip>
#include<string>
#include<vector>
#include<initializer_list>

using namespace std;
#define _CRT_SECURE_NO_WARNINGS

struct Sales_data{
	string isbn() const{ return bookNo; }
	Sales_data &combine(const Sales_data &){}

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

struct Person{
	string nam() const{ return name; }
	string add() const{ return address;}
	string name;
	string address;

};

int main(int argc, char *argv[])
{
	Sales_data total;
	if (cin >> total.bookNo>>total.units_sold>>total.revenue){
		Sales_data trans;
		while (cin>>trans.bookNo>>trans.units_sold>>trans.revenue)
		{
			if (total.isbn()== trans.isbn()){
				total.combine(trans);
			}
			else{
				cout << total.bookNo << "  " << total.units_sold << "  " << total.revenue << endl;
				total = trans;
			}
		}
	}
	else
	{
		cerr << " no data !" << endl;
		return 0;
	}
	return -1;
}

















