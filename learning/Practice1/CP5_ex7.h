#ifndef _CP5_EX7_H
#define _CP5_EX7_H

#include <iostream>
#include<string>
using namespace std;

//define class Sales_data
class Sales_data;
istream &read(istream &is, Sales_data &item);
ostream &print(ostream &os, const Sales_data &item);

class Sales_data{
friend istream &read(istream &is, Sales_data &item);
friend ostream &print(ostream &os, const Sales_data &item);

public:
	Sales_data(const string s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(n*p){
		cout << "Sales_data(const string &s,unsigned n,double p))" << endl;
	}
	Sales_data() :Sales_data("", 0, 0.0){
		cout << "Sales_data()" << endl;
	}
	Sales_data(const string s) :Sales_data(s, 0, 0.0){
		cout << "Sales_data(const string s)" << endl;
	}
	Sales_data(istream &is) :Sales_data(){
		read(is, *this); 
		cout << "Sales_data(istream &is = cin)" << endl;
	}

	string isbn() const{ return bookNo; }
	Sales_data &combine(const Sales_data &);

private:
	inline double avg_price() const;
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

istream &read(istream &is, Sales_data &item)
{
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price*item.units_sold;
	return is;
}
ostream &print(ostream &os, const Sales_data &item)
{
	os << item.isbn() << " " << item.units_sold << " "
		<< item.revenue << " " << item.avg_price()<<"\n";
	return os;
}


Sales_data& Sales_data::combine(const Sales_data &rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

inline double Sales_data::avg_price() const
{
	if (units_sold)
		return revenue / units_sold;
	else
		return 0;
}

//define class Person
struct Person;
istream &read(istream &is, Person &item);
ostream &print(ostream &os, const Person &item);

struct Person{
	friend istream &read(istream &is, Person &item);
	friend ostream &print(ostream &os, const Person &item);

public:
	Person() = default;
	Person(const string sname, const string saddress) :name(sname), address(saddress){}
	Person(std::istream &is) { read(is, *this); }
	string nam() const{ return name; }
	string add() const{ return address; }
private:
	string name;
	string address;
};
istream &read(istream &is, Person &item)
{
	is >> item.name >> item.address;
	return is;
}
ostream &print(ostream &os, const Person &item)
{
	os << item.name << " " << item.address;
	return os;
}


//define class Screen
class Screen{
public:
	friend class Windows_mgr;
	using pos = string::size_type;
	Screen(pos ht, pos wd) :height(ht), width(wd),contents(ht*wd,' '){}
	Screen(pos ht=5, pos wd=5, char c='c') : height(ht),width(wd),contents(ht*wd,c){}
	char get(){ return contents[cursor]; }
	char get(pos r, pos c){ return contents[r*width+c]; }
	Screen &move(pos r, pos c);
	Screen &set(char c);
	Screen &set(pos r, pos c,char ch);
	Screen &sidplay(ostream &os){ do_diaplay(os); return *this; }
	const Screen &display(ostream &os) const{ do_diaplay(os); return *this; }
	pos size() const;

private:
	pos height = 0, width = 0;
	pos cursor = 0;
	string contents;
	void do_diaplay(ostream &os) const{ os << contents; }
};

inline Screen &Screen::move(pos r, pos c)
{
	cursor = r*width + c;
	return *this;
}

inline Screen &Screen::set(char c)
{
	contents[cursor] = c;
	return *this;
}

inline Screen &Screen::set(pos r, pos c,char ch)
{
	contents[r*width + c] = ch;
	return *this;
}

inline Screen::pos Screen::size() const
{

}

class Windows_mgr{
public:
	using ScreenIndex = vector<Screen>::size_type;
	void clear(ScreenIndex);
	ScreenIndex addScreen(const Screen &);
private:
	std::vector<Screen> screens;
};

inline void Windows_mgr::clear(ScreenIndex i)
{
	Screen &s = screens[i];
	s.contents = string(s.height*s.width, ' ');
}

inline Windows_mgr::ScreenIndex Windows_mgr::addScreen(const Screen&)
{

}

vector<string> str{ string(4, ' ') };

class Date;
istream &read(istream &is, Date dt);

class Date{
public:
	friend istream &read(istream &is, Date dt);
	Date(const unsigned y, const unsigned m, const unsigned d) : year(y), month(m), day(d){
		cout << "Date(const unsigned y, const unsigned m, const unsigned d)" << endl;
	}
	Date() : Date(0, 0, 0){
		cout << "Date()" << endl;
	}
	Date(istream &is) :Date(){
		read(is, *this);
		cout << "Date(istream &is)" << endl;
	}

private:
	unsigned year;
	unsigned month;
	unsigned day;
};

istream &read(istream &is, Date dt)
{
	is >> dt.year >> dt.month >> dt.day;
	return is;
}


class NoDefault{
public:
	NoDefault(int){}
};
class C{
public:
	C():t(0){}
	NoDefault t;
};


class Account{
public:
	static double rate(){ return interestrate; }
	static void rate(double);

	static int period ;
	double daily_tbl[];
	static double interestrate;
	static vector<double> vec;

};


#endif