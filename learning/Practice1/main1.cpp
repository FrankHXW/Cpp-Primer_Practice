#include <iostream>
#include <iomanip>
#include<string>
#include<vector>
#include<initializer_list>

#include "CPP5_ex7.h"

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

















