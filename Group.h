#ifndef _Group_H_
#define _Group_H_
#include <iostream>
#include <map>
#include <string>
#include <set>
#include "Student.h"
#include "Small.h"
#include "Big.h"

namespace Prog7 {

	struct comp
	{
		bool operator()(Students::Student * const &s1, Students::Student* const &s2) const
		{
			return s1->getFN() < s2->getFN();
		}
	};

	class Group {
	protected:
		std::string ind;
		int max;
		int type;
		std::multiset <Students::Student*, comp> sts;
		std::ostream& show(std::ostream&)const;
		std::istream& get(std::istream&);
	public:
		Group() {}
		Group(std::string in, int m, int typ) { ind = in; max = m; type = typ; }
		Group(const Group &);
		Group(Group &&);
		~Group();
		Group& operator = (const Group &);
		Group& operator = (Group &&);
		friend class StudentIt;
		typedef StudentIt Iterator1;
		Iterator1 find(Students::Student &);
		bool add_student(Students::Student &);
		void show_student();
		std::multiset <Students::Student*, comp>::iterator get_student(std::string &, std::string &);
		Iterator1 begin();
		Iterator1 end();

		std::string  getI() const { return ind; }
		int getM() const { return max; }
		int getT() const { return type; }
		std::multiset <Students::Student*, comp> getS() const { return sts; }

		Group & setI(std::string a) { ind = a; return *this; }
		Group & setM(int a) { max = a; return *this; }
		Group & setT(int a) { type = a; return *this; }

		friend std::ostream& operator <<(std::ostream &, const Group &);
		friend std::istream& operator >>(std::istream &, Group &);
	};

	std::ostream & operator <<(std::ostream &, const std::pair<const std::string, Group> &);

	class StudentIt {
	private:
		std::multiset <Students::Student*, comp>::iterator cur;
	public:
		StudentIt() {}
		StudentIt(std::multiset <Students::Student*, comp>::iterator it) :cur(it) {}
		int operator !=(StudentIt &);
		int operator ==(StudentIt &);
		StudentIt & operator ++();
		StudentIt operator ++(int);
	};
};
#endif


