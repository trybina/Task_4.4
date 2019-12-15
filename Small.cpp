#include <iostream>
#include <math.h>
#include "Student.h"
#include "Small.h"
#include "Big.h"
#include <string>
#include <vector>

namespace Students {

	std::ostream& Small::show(std::ostream& os)const
	{
		return os << "Small student; first name - " << f_name << ", name - " << getN()
			<< ", number of marks - " << getK();
	}
	
	std::istream& Small::get(std::istream& is)
	{
		return is >> f_name >> name;
	}
	
	std::map <std::string, int> Small::get_marks() const
	{
		return marks;
	}

	void  Small::add_marks(std::string &s, int n, int q)
	{
		if (kol < q)
		{
			marks.insert(make_pair(s, n));
			kol++;
		}
	}

};

