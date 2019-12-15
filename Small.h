#ifndef _Small_H_
#define _Small_H_
#include <iostream>
#include "Student.h"
#include <vector>
#include <map>

namespace Students {

	class Small :public Student {
	protected:
		virtual std::ostream& show(std::ostream&)const;
		virtual std::istream& get(std::istream&);
	public:
		Small() :Student() {}
		Small(int kol0, std::string  f_name0, std::string  name0, std::map <std::string, int> marks0) : Student(kol0, f_name0, name0, marks0) {}
		virtual Small* clone() const
		{
			return new Small(*this);
		}
		virtual int get_type()const { return 1; }
		virtual std::map <std::string, int> get_marks()const;
		virtual void add_marks(std::string &, int n, int q);
	};

};
#endif



