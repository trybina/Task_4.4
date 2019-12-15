#include <iostream>
#include "Table1.h"
#include <map>
#include "Student.h"
#include "Small.h"
#include "Big.h"
#include "Group.h"

namespace Prog7 {

	bool Table::insert(const std::string &ss, const Group &f)
	{
		bool res = false;
		auto p = gr.find(ss);
		if (p == gr.end()) {
			gr[ss] = f;
			res = true;
		}
		return res;
	}

	bool Table::remove(const std::string &s)
	{
		bool res = false;
		auto p = gr.find(s);
		if (p != gr.end()) {
			gr.erase(p);
			res = true;
		}
		return res;
	}

	Table::Const_Iterator Table::find(const std::string &ss) const
	{
		std::map<const std::string, Group>::const_iterator p = gr.find(ss);
		return ConstTableIt(p);
	}

	std::map <std::string, Group>::iterator Table::find1(const std::string &s)
	{
		std::map<const std::string, Group>::iterator p = gr.find(s);
		return std::map <std::string, Group>::iterator(p);
	}

	Table::Const_Iterator Table::begin() const
	{
		return ConstTableIt(gr.begin());
	}

	std::map <std::string, Group>::iterator Table::begin1()
	{
		return std::map <std::string, Group>::iterator(gr.begin());
	}


	Table::Const_Iterator Table::end() const
	{
		return ConstTableIt(gr.end());
	}

	std::map <std::string, Group>::iterator Table::end1()
	{
		return std::map <std::string, Group>::iterator(gr.end());
	}

	int ConstTableIt:: operator !=(const ConstTableIt &it) const
	{
		return cur != it.cur;
	}

	int ConstTableIt::operator ==(const ConstTableIt &it) const
	{
		return cur == it.cur;
	}

	const std::pair<const std::string, Group > & ConstTableIt::operator *()
	{
		return *cur;
	}

	const std::pair<const std::string, Group > * ConstTableIt::operator ->()
	{
		return &*cur;
	}

	ConstTableIt & ConstTableIt::operator ++()
	{
		++cur;
		return *this;
	}

	ConstTableIt ConstTableIt::operator ++(int)
	{
		ConstTableIt res(*this);
		++cur;
		return res;
	}
};