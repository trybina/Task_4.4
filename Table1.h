#ifndef _TABLE_1_H_
#define _TABLE_1_H_
#include <iostream>
#include <map>
#include <string>
#include <set>
#include "Student.h"
#include "Small.h"
#include "Big.h"
#include "Group.h"

namespace Prog7 {

	class Table {
	private:
		std::map <std::string, Group> gr;
	public:
		Table() {}
		friend class ConstTableIt;
		typedef ConstTableIt Const_Iterator;
		typedef ConstTableIt Iterator;
		Const_Iterator find(const std::string &)const;
		std::map <std::string, Group>::iterator find1(const std::string &);
		bool insert(const std::string &, const Group &);
		bool remove(const std::string&);
		Const_Iterator begin() const;
		std::map <std::string, Group>::iterator begin1();
		Const_Iterator end() const;
		std::map <std::string, Group>::iterator end1();
	};

	class ConstTableIt {
	private:
		std::map<const std::string, Group>::const_iterator cur;
	public:
		ConstTableIt() {}
		ConstTableIt(std::map<const std::string, Group>::iterator it) :cur(it) {}
		ConstTableIt(std::map<const std::string, Group>::const_iterator it) :cur(it) {}
		int operator !=(const ConstTableIt &) const;
		int operator ==(const ConstTableIt &) const;
		const std::pair<const std::string, Group> & operator *();
		const std::pair<const std::string, Group> * operator ->();
		ConstTableIt & operator ++();
		ConstTableIt operator ++(int);
	};
};
#endif


