#include <iostream>
#include "Table1.h"
#include <map>
#include "Student.h"
#include "Small.h"
#include "Big.h"
#include "Group.h"

namespace Prog7 {

	std::ostream & operator <<(std::ostream &os, const std::pair<const std::string, Group *> &p) {

		return os << '"' << p.first << '"' << " - " << (*p.second) << std::endl;
	}

	std::ostream& Group::show(std::ostream& os)const
	{
		return os << "Index - " << getI() << "; max number of marks - " << getM()
			<< "; type of student - " << getT() << ";";
	}

	std::ostream& operator <<(std::ostream &os, const Group &g)
	{
		return g.show(os);
	}


	std::istream& Group::get(std::istream& is)
	{
		return is >> ind >> max >> type;
	}

	std::istream& operator >>(std::istream &is, Group &p)
	{
		return p.get(is);
	}

	Group::Group(const Group &a)
	{
		std::multiset <Students::Student*, comp>::iterator p;
		for (p = a.sts.begin(); p != a.sts.end(); ++p)
			sts.insert((*p)->clone());
	}
	Group::~Group()
	{
		std::multiset <Students::Student*, comp>::iterator p;
		for (auto& g : sts)
			delete g;
	}

	Group::Group(Group &&a)
	{
		std::multiset <Students::Student*, comp>::iterator p;
		sts = a.sts;
		a.sts.clear();
	}

	Group& Group::operator = (Group &&a)
	{
		ind = a.ind;
		type = a.type;
		max = a.max;
		std::multiset <Students::Student*, comp>::iterator p;
		if (this != &a) {

			for (p = sts.begin(); p != sts.end(); ++p)
				delete &p;
			sts.clear();

			std::multiset <Students::Student*, comp>::iterator pp;
			sts = a.sts;
			a.sts.clear();
		}
		return *this;
	}

	Group& Group::operator = (const Group &a)
	{
		ind = a.ind;
		type = a.type;
		max = a.max;
		std::multiset <Students::Student*, comp>::iterator p;
		if (this != &a) {

			for (p = sts.begin(); p != sts.end(); ++p)
				delete &p;
			sts.clear();

			std::multiset <Students::Student*, comp>::iterator pp;
			for (pp = a.sts.begin(); pp != a.sts.end(); ++pp)
				sts.insert((*pp)->clone());
		}
		return *this;
	}

	bool Group::add_student(Students::Student &stud)
	{
		bool res = false;
		std::multiset <Students::Student*, comp>::iterator p = sts.find(&stud);
		if (p == sts.end()) {
			sts.insert(stud.clone());
			res = true;
		}
		else
			throw std::exception("duplication");
		return res;
	}

	void Group::show_student()
	{
		for (auto p : sts)
			std::cout << (*p) << std::endl;
		std::cout << std::endl;
	}

	std::multiset <Students::Student*, comp>::iterator Group::get_student(std::string &f, std::string &n)
	{
		std::multiset <Students::Student*, comp>::iterator p;
		for (p = sts.begin(); p != sts.end(); ++p)
		{
			if ((*p)->getFN() == f && (*p)->getN() == n)
				return std::multiset <Students::Student*, comp>::iterator(p);
		}
		throw std::exception("Error when a group index was entered");
	}

	Group::Iterator1 Group::find(Students::Student & stud)
	{
		std::multiset <Students::Student*, comp>::iterator p = sts.find(&stud);
		return StudentIt(p);
	}

	Group::Iterator1 Group::begin()
	{
		return StudentIt(sts.begin());
	}
	Group::Iterator1 Group::end()
	{
		return StudentIt(sts.end());
	}

	int StudentIt:: operator !=(StudentIt &it)
	{
		return cur != it.cur;
	}
	int StudentIt::operator ==(StudentIt &it)
	{
		return cur == it.cur;
	}

	StudentIt & StudentIt::operator ++()
	{
		++cur;
		return *this;
	}
	StudentIt StudentIt::operator ++(int)
	{
		StudentIt res(*this);
		++cur;
		return res;
	}

};