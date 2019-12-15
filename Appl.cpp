#include <string>
#include <iostream>
#include "Table1.h"
#include "Student.h"
#include <iterator>

using namespace Students;
using namespace Prog7;
const std::string Names[] = { "Unknown", "Small", "Big" };
const std::string Menu[] = { "1. Add a group", "2. Find a group",
"3. Remove", "4. Show all", "5. Add student", "6. ShowStudents", "7. Add_Marks", "8. ShowMarks", "9. Average",
 "0. Quit" },

	Choice = "Make your choice",
	Msg = "You are wrong; repeate please";
int Answer(const std::string alt[], int n);
int Add(Table &), Find(Table &), Remove(Table &), ShowAll(Table &), Add_Student(Table &), ShowStudents(Table &), Add_Marks(Table &a), ShowMarks(Table &a), Average(Table &a);
int(*Funcs[])(Table &) = { nullptr, Add, Find, Remove, ShowAll, Add_Student, ShowStudents, Add_Marks, ShowMarks, Average };
const int Num = sizeof(Menu) / sizeof(Menu[0]);
int main()
{
	Table ar;
	int ind;
	try {
		while (ind = Answer(Menu, Num))
			Funcs[ind](ar);

		std::cout << "That's all. Buy!" << std::endl;
	}
	catch (const std::exception &er)
	{
		std::cout << er.what() << std::endl;
	}
	return 0;
}
int Answer(const std::string alt[], int n)
{
	int answer;
	std::string prompt = Choice;
	std::cout << "\nWhat do you want to do:" << std::endl;
	for (int i = 0; i < n; i++)
		std::cout << alt[i].c_str() << std::endl;
	do {
		std::cout << prompt.c_str() << ": -> ";
		prompt = Msg;
		std::cin >> answer;
		if (!std::cin.good()) {
			std::cout << "Error when number of choice was entered; \nRepeat, please." << std::endl;
			std::cin.ignore(80, '\n');
			std::cin.clear();
		}
	} while (answer < 0 || answer >= n);
	std::cin.ignore(80, '\n');
	return answer;
}
const std::string Sh[] = { "1. Continue", "0. Quit" };
const int NumSh = sizeof(Sh) / sizeof(Sh[0]);

const std::string Sh1[] = { "1. Small", "2. Big","0. Quit" };
const int NumSh1 = sizeof(Sh1) / sizeof(Sh1[0]);

int Add(Table &a)
{
	std::string name;
	int max;
	int type;
	int ans;
	while (ans = Answer(Sh, NumSh)) {
		std::cout << "Enter a index: --> ";
		std::cin >> name;
		if (!std::cin.good())
			throw std::exception("Error when a index was entered");
		std::cout << "Enter max: --> ";
		std::cin >> max;
		std::cout << "Enter type : --> ";
		std::cin >> type;
		if (a.insert(name, Group(name, max, type)))
			std::cout << "Ok" << std::endl;
		else
			std::cout << "Duplicate name" << std::endl;
	}
	return 0;
}

int Add_Student(Table &a)
{
	std::string name;
	std::map <std::string, Group>::iterator it;
	Group *ptr = nullptr;
	std::cout << "Enter a group index: --> ";
	std::cin >> name;
	if (!std::cin.good())
		throw std::exception("Error when a group index was entered");
	it = a.find1(name);
	if (it == a.end1()) {
		std::cout << "The Group with index \"" << name << "\" is absent in container"
			<< std::endl;
		return -1;
	}
	Student *ptr1 = nullptr;
	Small s;
	Big b;
	int ans;
	while (ans = Answer(Sh1, NumSh1)) {
		switch (ans) {
		case 1:
			std::cout << "Enter values fname, name: --> ";
			ptr1 = &s;
			break;
		case 2:
			std::cout << "Enter values fname, name, work, place, mark: --> ";
			ptr1 = &b;
			break;
		}
		std::cin >> (*ptr1);
		if (!std::cin.good())
			throw std::exception("Error when data were entered");
		std::cin.ignore(80, '\n');
		if (((*it).second).add_student(*ptr1))
			std::cout << "Ok" << std::endl;
		else
			std::cout << "Duplicate name" << std::endl;
	}
	return 0;
}

int Find(Table &a)
{
	std::string name;
	Table::Const_Iterator it;
	const Group *ptr = nullptr;
	std::cout << "Enter a group index: --> ";
	std::cin >> name;
	if (!std::cin.good())
		throw std::exception("Error when a group index was entered");
	it = a.find(name);
	if (it == a.end()) {
		std::cout << "The Group with index \"" << name << "\" is absent in container"
			<< std::endl;
		return -1;
	}
	ptr = &(*it).second;
	std::cout << "The Group with index \"" << (*it).first
		<< "\" is a " << Names[ptr->getT()] << std::endl;
	std::cout << (*ptr) << std::endl;
	return 0;
}

int Remove(Table &a)
{
	std::string name;
	const Group *ptr = nullptr;
	std::cout << "Enter a index of group: --> ";
	std::cin >> name;
	if (!std::cin.good())
		throw std::exception("Error when a shape name was entered");
	if (a.remove(name))
		std::cout << "Ok" << std::endl;
	else
		std::cout << "The Group with index \"" << name << "\" is absent in container"
		<< std::endl;
	return 0;
}

int ShowAll(Table &a)
{
	std::map <std::string, Group>::iterator it;
	for (it = a.begin1(); it != a.end1(); ++it)
	{
		std::cout << it->second << std::endl;
		std::cout << std::endl;
		std::cout << "List of students:" << std::endl;
		std::multiset <Students::Student*, comp> sts = (*it).second.getS();
		for (auto z : sts)
		{
			std::cout << (*z) << std::endl;
			std::map <std::string, int> p = (*z).get_marks();
			std::cout << "List of marks:" << std::endl;
			for (auto k : p)
				std::cout << k.first << " - " << k.second << std::endl;
			std::cout << std::endl;

		}
		std::cout << std::endl;
	}
	return 0;
}

int ShowStudents(Table &a)
{
	std::string name;
	std::map <std::string, Group>::iterator it;
	std::cout << "Enter a group index: --> ";
	std::cin >> name;
	if (!std::cin.good())
		throw std::exception("Error when a group index was entered");
	it = a.find1(name);
	if (it == a.end1()) {
		std::cout << "The Group with index \"" << name << "\" is absent in container"
			<< std::endl;
		return -1;
	}
	(*it).second.show_student();
	return 0;
}

int Add_Marks(Table &a)
{
	std::string ind;
	std::map <std::string, Group>::iterator it;
	std::cout << "Enter a group index: --> ";
	std::cin >> ind;
	if (!std::cin.good())
		throw std::exception("Error when a group index was entered");
	it = a.find1(ind);
	if (it == a.end1()) {
		std::cout << "The Group with index \"" << ind << "\" is absent in container"
			<< std::endl;
		return -1;
	}
	std::multiset <Students::Student*, comp>::iterator it1;
	std::string fname;
	std::cout << "Enter a f_name: --> ";
	std::cin >> fname;
	if (!std::cin.good())
		throw std::exception("Error when a f_name was entered");
	std::string name;
	std::cout << "Enter a name: --> ";
	std::cin >> name;
	if (!std::cin.good())
		throw std::exception("Error when a was entered");
	it1 = (*it).second.get_student(fname, name);

	int q = (*it).second.getM();
	int ans;
	int m;
	std::string sub;
	while (ans = Answer(Sh, NumSh)) {
		std::cout << "Enter a subject: --> ";
		std::cin >> sub;
		if (!std::cin.good())
			throw std::exception("Error when a was entered");
		std::cout << "Enter a mark: --> ";
		std::cin >> m;
		if (!std::cin.good())
			throw std::exception("Error when a group index was entered");
		(*it1)->add_marks(sub, m, q);
	}
	return 0;
}

int ShowMarks(Table &a)
{
	std::string ind;
	std::map <std::string, Group>::iterator it;
	Group *ptr = nullptr;
	std::cout << "Enter a group index: --> ";
	std::cin >> ind;
	if (!std::cin.good())
		throw std::exception("Error when a group index was entered");
	it = a.find1(ind);
	if (it == a.end1()) {
		std::cout << "The Group with index \"" << ind << "\" is absent in container"
			<< std::endl;
		return -1;
	}
	std::multiset <Students::Student*, comp>::iterator it1;
	std::string fname;
	std::cout << "Enter a f_name: --> ";
	std::cin >> fname;
	if (!std::cin.good())
		throw std::exception("Error when a f_name was entered");
	std::string name;
	std::cout << "Enter a name: --> ";
	std::cin >> name;
	if (!std::cin.good())
		throw std::exception("Error when a was entered");
	it1 = (*it).second.get_student(fname, name);
	std::map <std::string, int> p = (*it1)->get_marks();
	for (auto z : p)
		std::cout << z.first << " - " << z.second << std::endl;
	std::cout << std::endl;
	return 0;
}

int score(Students::Student* sts)
{
	int q = 0;
	int b = 0;
	std::map <std::string, int> p = (*sts).get_marks();
	for (auto k : p)
	{
		q++;
		b = b + k.second;
	}
	b = b / q;
	return b;
}

int Average(Table &a)
{
	std::string name;
	std::map <std::string, Group>::iterator it;
	std::cout << "Enter a group index: --> ";
	std::cin >> name;
	if (!std::cin.good())
		throw std::exception("Error when a group index was entered");
	it = a.find1(name);
	if (it == a.end1()) {
		std::cout << "The Group with index \"" << name << "\" is absent in container"
			<< std::endl;
		return -1;
	}
	int q = 0;
	int b = 0;
	std::multiset <Students::Student*, comp> sts = (*it).second.getS();
	for (auto z : sts)
	{
		q++;
		b = b + score(z);
	}
	b = b / q;
	std::cout << b;
	std::cout << std::endl;
	return 0;
}
int File_out(Table &a)
{
	std::ofstream fout("1.txt", std::ios_base::out);
	std::map <std::string, Group>::iterator it;
	for (it = a.begin1(); it != a.end1(); ++it)
	{
		fout << it->second << "\n";
		fout << "List of students:";
		std::multiset <Students::Student*, comp> sts = (*it).second.getS();
		for (auto z : sts)
		{
			fout << (*z) << "\n";
			std::map <std::string, int> p = (*z).get_marks();
			fout << "List of marks:" << "\n";
			for (auto k : p)
				fout << k.first << " - " << k.second << "\n";
			fout << "\n";

		}
		fout << "\n";
	}
	fout.close();
	std::cout << "Ok"<< std::endl;
	return 0;
}

